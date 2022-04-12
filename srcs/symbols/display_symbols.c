/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_symbols.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:23:56 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/04/02 12:10:14 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_nm.h"

void print_line(t_symbol symbol, char c)
{
    if (_g_meta_file->arc == ARCH_32)
    {
        if (value_to_print(symbol, c) == SUCCESS)
        {
            printf("%08zx %c %s\n", symbol.sym_value, c, symbol.sym_name);
        }
        else
            printf("%8s %c %s\n", "", c, symbol.sym_name);
    }
    else if (_g_meta_file->arc == ARCH_64)
    {

        if (value_to_print(symbol, c) == SUCCESS)
        {
            printf("%016zx %c %s\n", symbol.sym_value, c, symbol.sym_name);
        }
        else
            printf("%16s %c %s\n", "", c, symbol.sym_name);
    }
}

static void display_symbol_line(t_symbol symbol)
{
    if (symbol.sym_name[0] == 0 || symbol.sym_type == STT_FILE)
        return;
    else if (display_section_spec(symbol) == SUCCESS)
        return;
    else if (display_section_name(symbol) == SUCCESS)
        return;
    else if (display_section_flags(symbol) == SUCCESS)
        return;
    print_line(symbol, 'U');
}

void display_symbols(t_symbol *symbols, size_t symbol_count)
{
    if (get_nm()->meta_file_count > 1 || get_nm()->nm_non_arg_count > 1)
        printf("\n%s:\n", _g_meta_file->file_name);
    if (get_nm()->flags[FLAGS_REVERSE_SORT] == true)
        reverse_sort_symbols(symbols, symbol_count);
    else if (get_nm()->flags[FLAGS_DO_NOT_SORT] == false)
        sort_symbols(symbols, symbol_count);
    for (size_t i = 0; i < symbol_count; i++)
    {
        display_symbol_line(symbols[i]);
    }
}