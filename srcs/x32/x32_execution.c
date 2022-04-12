/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x32_execution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 13:26:07 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/04/02 12:15:48 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_nm.h"

static void init_section_info(t_symbol *sym, t_elf_32 *meta_data, size_t i)
{
    int shndx;

    shndx = meta_data->sym[i].st_shndx;
    sym[i].shdr_index = shndx;
    if ((shndx >= SHN_LORESERVE && shndx <= SHN_HIRESERVE) || shndx == SHN_UNDEF)
    {
        sym[i].shdr_name = "";
        sym[i].shdr_link = 0;
        sym[i].shdr_type = 0;
        sym[i].shdr_flags = 0;
    }
    else
    {
        sym[i].shdr_name = SHDR_NAME(meta_data, shndx);
        sym[i].shdr_link = meta_data->shdr[shndx].sh_link;
        sym[i].shdr_type = meta_data->shdr[shndx].sh_type;
        sym[i].shdr_flags = meta_data->shdr[shndx].sh_flags;
    }
}

static t_symbol *get_symbols(t_elf_32 *meta_data)
{
    t_symbol *symbols = NULL;

    if (!(symbols = malloc(sizeof(t_symbol) * meta_data->sym_count)))
        return (NULL);
    else
    {
        for (size_t i = 0; i < meta_data->sym_count; i++)
        {
            symbols[i].sym_name = SYM_NAME(meta_data, i);
            symbols[i].sym_type = ELF32_ST_TYPE(meta_data->sym[i].st_info);
            symbols[i].sym_bind = ELF32_ST_BIND(meta_data->sym[i].st_info);
            symbols[i].sym_vis = ELF32_ST_VISIBILITY(meta_data->sym[i].st_other);
            symbols[i].sym_value = meta_data->sym[i].st_value;
            symbols[i].sym_size = meta_data->sym[i].st_size;
            init_section_info(symbols, meta_data, i);
        }
    }
    return (symbols);
}

int x32_execution(t_meta_file *meta_file)
{
    Elf32_Ehdr *ehdr;
    t_elf_32 *meta_data;
    t_symbol *symbols;

    ehdr = (Elf32_Ehdr *)meta_file->ptr;
    if (meta_file->st.st_size < ehdr->e_shoff + (ehdr->e_shnum * ehdr->e_shentsize))
        return (display_error(E_FORMAT));
    if (setup_x32_meta_data(&meta_data, meta_file->ptr))
        return (FAILURE);
    if (!meta_data->shdr_str)
    {
        display_multiple_error("ft_nm: %s: " E_SYM "\n", meta_file->file_name);
        free(meta_data);
        return (SUCCESS);
    }
    if (!(symbols = get_symbols(meta_data)))
    {
        free(meta_data->sym);
        free(meta_data);
        return (display_error(E_FATAL));
    }
    display_symbols(symbols, meta_data->sym_count);
    free(symbols);
    free(meta_data->sym);
    free(meta_data);
    return (SUCCESS);
}