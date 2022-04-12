/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 19:03:23 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/02/21 19:04:00 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putnbr_base(unsigned long long nbr, const char *base)
{
    int base_len;
    int i;
    int tmp;

    base_len = ft_strlen(base);
    i = 0;
    if (nbr == 0)
        ft_putchar(base[0]);
    while (nbr != 0)
    {
        tmp = nbr % base_len;
        ft_putchar(base[tmp]);
        nbr = nbr / base_len;
    }
}