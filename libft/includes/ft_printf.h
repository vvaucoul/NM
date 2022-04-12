/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 01:00:32 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/02/22 15:03:53 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>

#include "libft.h"

#define NB_FLAGS 8
#define SUPPORTED_FLAGS \
    (char *[]) { "d", "i", "c", "s", "p", "zu", "llu", "u" }

typedef struct s_printf
{
    char *str;
    va_list list;
} t_printf;

int ft_printf(const char *str, ...);

#endif