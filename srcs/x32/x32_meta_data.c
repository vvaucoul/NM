/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x32_meta_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 12:13:25 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/04/02 12:14:58 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_nm.h"

static void get_values(t_elf_32 *meta_data, void *ptr)
{
    meta_data->start = ptr;
    meta_data->ehdr = (Elf32_Ehdr *)ptr;
    meta_data->shdr = (Elf32_Shdr *)(ptr + meta_data->ehdr->e_shoff);
    meta_data->shstr = (char *)(meta_data->start + meta_data->shdr[meta_data->ehdr->e_shstrndx].sh_offset);
}

static void get_shdr_values(t_elf_32 *meta_data)
{
    char *name;

    meta_data->shdr_str = NULL;
    meta_data->shdr_sym = NULL;
    meta_data->sym = NULL;
    for (size_t i = 0; i < meta_data->ehdr->e_shnum; i++)
    {
        name = SHDR_NAME(meta_data, i);
        if (ft_strcmp(name, ".strtab") == 0)
            meta_data->shdr_str = meta_data->shdr + i;
        else if (ft_strcmp(name, ".symtab") == 0)
            meta_data->shdr_sym = meta_data->shdr + i;
    }
}

int setup_x32_meta_data(t_elf_32 **x32_meta_data, void *file)
{
    void *symbols;

    if (!(*x32_meta_data = malloc(sizeof(t_elf_32))))
        return (display_error(E_FATAL));
    get_values(*x32_meta_data, file);
    get_shdr_values(*x32_meta_data);
    if (!((*x32_meta_data)->shdr_str))
        return (0);
    (*x32_meta_data)->str = (char *)((*x32_meta_data)->start + (*x32_meta_data)->shdr_str->sh_offset);
    symbols = ((*x32_meta_data)->start + (*x32_meta_data)->shdr_sym->sh_offset);
    if (!(((*x32_meta_data)->sym) = (Elf32_Sym *)malloc(sizeof(Elf32_Sym) * (*x32_meta_data)->shdr_sym->sh_size)))
    {
        free(*x32_meta_data);
        return (display_error(E_FATAL));
    }
    ft_memcpy((*x32_meta_data)->sym, symbols, (*x32_meta_data)->shdr_sym->sh_size);
    (*x32_meta_data)->sym_count = (*x32_meta_data)->shdr_sym->sh_size / sizeof(Elf32_Sym);
    return (0);
}