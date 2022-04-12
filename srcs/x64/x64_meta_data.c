/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x64_meta_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:23:14 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/03/23 17:06:30 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_nm.h"

static void get_values(t_elf_64 *meta_data, void *ptr)
{
    meta_data->start = ptr;
    meta_data->ehdr = (Elf64_Ehdr *)ptr;
    meta_data->shdr = (Elf64_Shdr *)(ptr + meta_data->ehdr->e_shoff);
    meta_data->shstr = (char *)(meta_data->start + meta_data->shdr[meta_data->ehdr->e_shstrndx].sh_offset);
}

static void get_shdr_values(t_elf_64 *meta_data)
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

int setup_x64_meta_data(t_elf_64 **x64_meta_data, void *file)
{
    void *symbols;

    if (!(*x64_meta_data = malloc(sizeof(t_elf_64))))
        return (display_error(E_FATAL));
    get_values(*x64_meta_data, file);
    get_shdr_values(*x64_meta_data);
    if (!((*x64_meta_data)->shdr_str))
        return (0);
    (*x64_meta_data)->str = (char *)((*x64_meta_data)->start + (*x64_meta_data)->shdr_str->sh_offset);
    symbols = ((*x64_meta_data)->start + (*x64_meta_data)->shdr_sym->sh_offset);
    if (!(((*x64_meta_data)->sym) = (Elf64_Sym *)malloc(sizeof(Elf64_Sym) * (*x64_meta_data)->shdr_sym->sh_size)))
    {
        free(*x64_meta_data);
        return (display_error(E_FATAL));
    }
    ft_memcpy((*x64_meta_data)->sym, symbols, (*x64_meta_data)->shdr_sym->sh_size);
    (*x64_meta_data)->sym_count = (*x64_meta_data)->shdr_sym->sh_size / sizeof(Elf64_Sym);
    return (0);
}