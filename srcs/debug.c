/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:27:45 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/04/01 12:57:41 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_nm.h"

void debug_display_arguments()
{
    size_t count = get_nm()->meta_file_count;
    t_meta_file *meta_files = get_nm()->meta_files;

    printf("Arguments List:\n");
    for (size_t i = 0; i < count; i++)
    {
        printf("[%zu] - %s\n", i, meta_files[i].file_name);
    }
}