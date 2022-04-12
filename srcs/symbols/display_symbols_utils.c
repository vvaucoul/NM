/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_symbols_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:22:58 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/04/02 18:34:05 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_nm.h"

static char get_symbol(char sym, char c)
{
    if (sym == STB_GLOBAL)
        return (c);
    else
        return (ft_tolower(c));
}

char value_to_print(t_symbol symbol, char c)
{
    char nc;

    if (symbol.sym_value)
        return (SUCCESS);
    else
    {
        nc = ft_tolower(c);
        if (nc == 't' || nc == 'a' || nc == 'n' ||
            nc == 'b' || nc == 'r' || nc == 'd' ||
            c == 'W')
            return (SUCCESS);
    }
    return (FAILURE);
}

char display_section_spec(t_symbol symbol)
{
    int shndx;

    shndx = symbol.shdr_index;
    if (shndx >= SHN_LORESERVE && shndx <= SHN_HIRESERVE)
    {
        if (shndx == SHN_ABS)
        {
            print_line(symbol, get_symbol(symbol.sym_bind, 'A'));
            return (SUCCESS);
        }
        else if (shndx == SHN_COMMON)
        {
            print_line(symbol, 'C');
            return (SUCCESS);
        }
    }
    else if (symbol.shdr_type == STT_LOOS &&
             symbol.shdr_flags & SHF_ALLOC &&
             symbol.shdr_flags & SHF_EXECINSTR)
    {
        print_line(symbol, 'i');
        return (SUCCESS);
    }
    else if (symbol.sym_bind == STB_WEAK)
    {
        if (symbol.sym_type == STT_OBJECT)
        {
            if (symbol.sym_value)
                print_line(symbol, 'V');
            else
                print_line(symbol, 'v');
        }
        else
        {
            if (symbol.sym_value || symbol.shdr_index)
                print_line(symbol, 'W');
            else
                print_line(symbol, 'w');
        }
        return (SUCCESS);
    }
    else if (symbol.sym_type == STT_OBJECT && symbol.sym_bind == STB_GNU_UNIQUE)
    {
        print_line(symbol, 'u');
        return (SUCCESS);
    }
    return (FAILURE);
}

char display_section_name(t_symbol symbol)
{
    if (ft_strncmp(symbol.shdr_name, ".bss", 4) == 0)
    {
        print_line(symbol, get_symbol(symbol.sym_bind, 'B'));
        return (SUCCESS);
    }
    else if (ft_strncmp(symbol.shdr_name, ".text", 5) == 0)
    {
        print_line(symbol, get_symbol(symbol.sym_bind, 'T'));
        return (SUCCESS);
    }
    else if (ft_strncmp(symbol.shdr_name, ".data", 5) == 0)
    {
        print_line(symbol, get_symbol(symbol.sym_bind, 'D'));
        return (SUCCESS);
    }
    else if (ft_strncmp(symbol.shdr_name, ".rodata", 7) == 0)
    {
        print_line(symbol, get_symbol(symbol.sym_bind, 'R'));
        return (SUCCESS);
    }
    return (FAILURE);
}

char display_section_flags(t_symbol symbol)
{
    if (symbol.shdr_type == SHT_NOBITS &&
        symbol.shdr_flags & SHF_ALLOC &&
        (!(symbol.shdr_flags & SHF_EXECINSTR)))
    {
        print_line(symbol, get_symbol(symbol.sym_bind, 'B'));
        return (SUCCESS);
    }
    else if (!(symbol.shdr_flags & SHF_WRITE) &&
               symbol.shdr_flags & SHF_ALLOC &&
               (!(symbol.shdr_flags & SHF_EXECINSTR)))
    {
        print_line(symbol, get_symbol(symbol.sym_bind, 'R'));
        return (SUCCESS);
    }
    else if (symbol.shdr_flags & SHF_WRITE &&
             symbol.shdr_flags & SHF_ALLOC)
    {
        print_line(symbol, get_symbol(symbol.sym_bind, 'D'));
        return (SUCCESS);
    }
    else if (symbol.shdr_flags & SHF_ALLOC &&
             symbol.shdr_flags & SHF_EXECINSTR)
    {
        print_line(symbol, get_symbol(symbol.sym_bind, 'T'));
        return (SUCCESS);
    }
    else if (symbol.shdr_type == SHT_PROGBITS &&
             (!(symbol.shdr_flags)))
    {
        print_line(symbol, get_symbol(symbol.sym_bind, 'N'));
        return (SUCCESS);
    }
    return (FAILURE);
}