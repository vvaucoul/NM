/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 12:12:49 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/04/12 13:55:46 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_nm.h"

static int clean_execution(t_meta_file *meta_file)
{
    if ((munmap(meta_file->ptr, meta_file->st.st_size)) == FAILURE)
        return ((display_error(E_FATAL)));
    close(meta_file->fd);
    return (SUCCESS);
}

static int init_fill_elf_structure(t_meta_file *meta_file)
{
    char *ptr;
    enum e_arch arc = ARCH_64;

    ptr = meta_file->ptr;
    if ((unsigned char)ptr[EI_CLASS] == ELFCLASSNONE)
        return (display_multiple_error("ft_nm: %s: " E_FORMAT "\n", meta_file->file_name));
    arc = (unsigned char)ptr[EI_CLASS] == ELFCLASS32 ? ARCH_32 : ARCH_64;
    meta_file->arc = arc;
    return (SUCCESS);
}

static int check_execution_binary(t_meta_file *meta_file)
{
    char *ptr = NULL;

    if ((meta_file->ptr = mmap(NULL, meta_file->st.st_size, PROT_READ, MAP_PRIVATE, meta_file->fd, 0)) == MAP_FAILED)
        return (display_error(E_FATAL));
    else
        ptr = meta_file->ptr;
    if (meta_file->st.st_size < EI_NIDENT)
        return (display_multiple_error("ft_nm: %s: " E_FORMAT "\n", meta_file->file_name));
    if ((unsigned char)ptr[EI_MAG0] == ELFMAG0 &&
        (unsigned char)ptr[EI_MAG1] == ELFMAG1 &&
        (unsigned char)ptr[EI_MAG2] == ELFMAG2 &&
        (unsigned char)ptr[EI_MAG3] == ELFMAG3)
    {
        if ((init_fill_elf_structure(meta_file)) == FAILURE)
            return (FAILURE);
        else
        {
            if (meta_file->arc == ARCH_32)
                x32_execution(meta_file);
            else
                x64_execution(meta_file);
        }
    }
    else
        return (display_multiple_error("ft_nm: %s: " E_FORMAT "\n", meta_file->file_name));
    return (SUCCESS);
}

int execution()
{
    t_meta_file *meta_files;

    meta_files = get_nm()->meta_files;
    for (size_t i = 0; i < get_nm()->meta_file_count; i++)
    {
        _g_meta_file = &meta_files[i];
        if ((check_execution_binary(&meta_files[i])) == FAILURE)
            continue;
        if ((clean_execution(&meta_files[i])) == FAILURE)
            continue;
    }
    return (SUCCESS);
}