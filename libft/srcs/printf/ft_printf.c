/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 00:59:06 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/02/22 15:05:50 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char *find_flag_case(const char *str)
{
    size_t i = 0;

    while (i < NB_FLAGS)
    {
        if (ft_strncmp(str, SUPPORTED_FLAGS[i], ft_strlen(SUPPORTED_FLAGS[i])) == 0)
            return (SUPPORTED_FLAGS[i]);
        i++;
    }
    return (NULL);
}

static int display_case(t_printf *tfp, char *str)
{
    if (!ft_strcmp(str, "c"))
    {
        char tmp = va_arg(tfp->list, int);
        ft_putchar(tmp);
    }
    else if (!ft_strcmp(str, "d") || !ft_strcmp(str, "i"))
    {
        int tmp = va_arg(tfp->list, int);
        ft_putnbr(tmp);
    }
    else if (!ft_strcmp(str, "s"))
    {
        char *tmp = va_arg(tfp->list, char *);

        if (!tmp)
            ft_putstr("(null)");
        else
            ft_putstr(tmp);
    }
    else if (!ft_strcmp(str, "p"))
    {
        void *tmp = va_arg(tfp->list, void *);
        ft_putstr("0x");
        ft_putnbr_base((unsigned long long)tmp, "0123456789abcdef");
    }
    else if (!ft_strcmp(str, "u"))
    {
        unsigned int tmp = va_arg(tfp->list, unsigned int);
        ft_putunbr(tmp);
    }
    else if (!ft_strcmp(str, "zu"))
    {
        size_t tmp = va_arg(tfp->list, size_t);
        ft_putnbr(tmp);
    }
    else if (!ft_strcmp(str, "llu"))
    {
        unsigned long long tmp = va_arg(tfp->list, unsigned long long);
        ft_putull(tmp);
    }
    return (0);
}

static size_t parse(t_printf *ptf)
{
    size_t i = 0;

    if (!ptf->str)
        return (0);
    for (; ptf->str[i]; ++i)
    {
        if (ptf->str[i] == '%')
        {
            char *flag = find_flag_case(&(ptf->str[i + 1]));
            if (!flag)
            {
                ft_putstr("(error)");
                continue;
            }
            display_case(ptf, flag);
            i += ft_strlen(flag);
        }
        else
            ft_putchar(ptf->str[i]);
    }
    return (0);
}

int ft_printf(const char *str, ...)
{
    t_printf ptf;

    ptf.str = (char *)str;
    va_start(ptf.list, str);
    if (parse(&ptf))
        return (1);
    va_end(ptf.list);
    return (0);
}