/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbol_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:33:14 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/04/11 13:33:56 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_nm.h"

void reverse_sort_symbols(t_symbol *symbols, size_t symbol_count)
{
    sort_symbols(symbols, symbol_count);
    for (size_t i = 0; i < symbol_count / 2; i++)
    {
        t_symbol tmp = symbols[i];
        symbols[i] = symbols[symbol_count - i - 1];
        symbols[symbol_count - i - 1] = tmp;
    }
}

void sort_symbols(t_symbol *symbols, size_t symbol_count)
{
    t_symbol tmp;
    size_t i;
    size_t j;

    i = 0;
    while (i < symbol_count)
    {
        j = i + 1;
        while (j < symbol_count)
        {
            char *s1, *s2;

            s1 = ft_strremove(ft_strdup(symbols[i].sym_name), '_');
            s2 = ft_strremove(ft_strdup(symbols[j].sym_name), '_');
            s1 = ft_strremove(s1, '.');
            s2 = ft_strremove(s2, '.');
            s1 = ft_strremove(s1, '@');
            s2 = ft_strremove(s2, '@');
            s1 = ft_strtolower(s1);
            s2 = ft_strtolower(s2);

            if (ft_strcmp(s1, s2) >= 0)
            {
                if (ft_strcmp(s1, s2) == 0)
                {
                    uint64_t v1 = symbols[i].sym_value;
                    uint64_t v2 = symbols[j].sym_value;

                    if (v1 >= v2)
                    {
                        tmp = symbols[i];
                        symbols[i] = symbols[j];
                        symbols[j] = tmp;
                    }
                }
                else
                {
                    tmp = symbols[i];
                    symbols[i] = symbols[j];
                    symbols[j] = tmp;
                }
            }
            ft_multifree((void *[]){s1, s2, NULL});
            j++;
        }
        i++;
    }
}