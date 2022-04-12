/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:28:40 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/04/11 13:32:46 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char *ft_strtolower(const char *str)
{
    char *nstr = NULL;
    size_t i = 0;

    if (!str)
        return (NULL);
    if (!(nstr = ft_strdup(str)))
        return (NULL);
    while (nstr[i])
    {
        nstr[i] = ft_tolower(nstr[i]);
        ++i;
    }
    free((char *)str);
    return (nstr);
}