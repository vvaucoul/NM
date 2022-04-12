/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 21:08:21 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/04/11 13:06:25 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_nm.h"

t_meta_file *_g_meta_file;

static bool check_display_help(int argc, char **argv)
{
    if (argc > 1)
    {
        if (ft_strcmp(argv[1], "--help") == 0 || ft_strcmp(argv[1], "-h") == 0 ||
        (has_only_tild(argv[1]) && ft_strlen(argv[1]) >= 3))
        {
            display_help();
            return (true);
        }
    }
    return (false);
}

int main(int argc, char **argv)
{
    if (argc <= 1)
    {
        if ((check_arguments(2, (char *[]){argv[0], "a.out", NULL})) == FAILURE)
            return (FAILURE);
    }
    else if (check_display_help(argc, argv) == true)
        return (SUCCESS);
    else
    {
        if ((check_arguments(argc, argv)) == FAILURE)
            return (FAILURE);
    }
    if ((execution()) == FAILURE)
        return (FAILURE);
    if (get_nm()->meta_files)
        free(get_nm()->meta_files);
    return (SUCCESS);
}