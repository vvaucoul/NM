/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 21:14:28 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/04/11 13:11:13 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_nm.h"

static int check_nm_flags(char *str)
{
    return (parser_checker(str));
}

static bool flags_conflict_checker()
{
    bool flags[NB_NM_FLAGS] = {false, false};

    ft_memcpy(flags, get_nm()->flags, sizeof(flags));
    if (flags[FLAGS_REVERSE_SORT] == true && flags[FLAGS_DO_NOT_SORT] == true)
        return (true);
    return (false);
}

static bool flags_has_only_flags(size_t argc, char **argv)
{
    for (size_t i = 1; i < argc; i++)
    {
        if (check_nm_flags(argv[i]) == FAILURE)
            return (false);
        if (argv[i][0] != '-')
            return (false);
    }
    return (true);
}

static size_t flags_get_non_arg_flags(size_t argc, char **argv)
{
    size_t count = 0;

    for (size_t i = 1; i < argc; i++)
    {
        if (argv[i][0] != '-')
            ++count;
    }
    return (count);
}

int valid_argument(char *argument)
{
    t_meta_file new_meta_file;

    new_meta_file.file_name = argument;
    if (!(new_meta_file.fd = open(new_meta_file.file_name, O_RDONLY)))
        return (display_multiple_error("ft_nm: %s", E_ENOENT));
    if (fstat(new_meta_file.fd, &new_meta_file.st) == -1)
    {
        close(new_meta_file.fd);
        return (display_multiple_error("ft_nm: \'%s\': " E_ENOENT "\n", new_meta_file.file_name));
    }
    if (S_ISDIR(new_meta_file.st.st_mode))
    {
        close(new_meta_file.fd);
        return (display_multiple_error("ft_nm: \'%s\' " E_EISDIR "\n", new_meta_file.file_name));
    }
    if ((append_meta_file(new_meta_file) == FAILURE))
    {
        close(new_meta_file.fd);
        return (display_multiple_error("ft_nm: Failed to append meta file\n", NULL));
    }
    return (SUCCESS);
}

int check_arguments(size_t argc, char **argv)
{
    size_t i = 1;

    for (size_t k = i; k < argc; k++)
    {
        if (check_nm_flags(argv[k]) == FAILURE)
            return (FAILURE);
    }
    if (flags_conflict_checker() == true)
        return (display_multiple_error("ft_nm: %s\n", E_CONFLICT));
    if (flags_has_only_flags(argc, argv) == true)
        argv = (char *[]){argv[0], "a.out", NULL};
    get_nm()->nm_non_arg_count = flags_get_non_arg_flags(argc, argv);
    while (i < argc)
    {
        if (argv[i][0] == '-' && ft_strlen(argv[i]) > 1)
        {
            ++i;
            continue;
        }
        if ((valid_argument(argv[i])) == FAILURE)
        {
            ++i;
            continue;
        }
        ++i;
    }
    return (SUCCESS);
}