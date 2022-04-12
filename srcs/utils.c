/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 21:09:08 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/04/12 15:40:13 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_nm.h"

int display_help()
{
    printf("Usage: ft_nm [OPTION]... [FILE]...\n");
    printf(" List symbols in files. (a.out) by default\n");
    printf(" The options are:\n");
    printf("  -r:\t Reverse sort\n");
    printf("  -p:\t Do not sort symbols\n");
    printf("\nft_nm supported targets: elf64 - elf32 - binaries - libraries\n");
    return (SUCCESS);
}

bool has_only_tild(char *str)
{
    if (!str)
        return (false);
    else
    {
        for (size_t i = 0; str[i]; i++)
        {
            if (str[i] != '-')
                return (false);
        }
    }
    return (true);
}

bool parser_checker(char *str)
{
    char *flags[NB_NM_FLAGS + 1] = NM_FLAGS;
    char flags_ascii[NB_NM_FLAGS] = NM_ASCII_FLAGS;

    for (size_t i = 0; i < NB_NM_FLAGS; i++)
    {
        if (ft_strcmp(str, flags[i]) == 0)
        {
            get_nm()->flags[i] = true;
            return (SUCCESS);
        }
    }
    if (str[0] != '-')
        return (SUCCESS);
    else
    {
        for (size_t j = 1; str[j]; j++)
        {
            if (ft_ccof(str[j], flags_ascii) == false)
            {
                display_multiple_error("ft_nm: " E_ARG " \'%s\'\n", (char[2]){str[j], 0});
                return (FAILURE);
            }
            else
            {
                if (str[j] == 'r')
                    get_nm()->flags[FLAGS_REVERSE_SORT] = true;
                else if (str[j] == 'p')
                    get_nm()->flags[FLAGS_DO_NOT_SORT] = true;
            }
        }
    }
    return (SUCCESS);
}

size_t ft_strlen(const char *str)
{
    size_t i = 0;

    if (!str)
        return (0);
    while (str[i])
        ++i;
    return (i);
}

int display_multiple_error(const char *format, const char *str)
{
    fprintf(stderr, format, str);
    return (FAILURE);
}

int display_error(const char *str)
{
    write(2, "ft_nm: ", 7);
    write(2, str, ft_strlen(str));
    write(2, "\n", 1);
    return (FAILURE);
}

t_nm *get_nm()
{
    static t_nm nm = {NULL, 0, 0, {(bool){false}}};
    static int init = 0;

    if (!init)
    {
        nm.meta_files = NULL;
        nm.meta_file_count = 0;
        nm.nm_non_arg_count = 0;
        for (size_t i = 0; i < NB_NM_FLAGS; i++)
            nm.flags[i] = false;
        init = 1;
    }
    return (&nm);
}
