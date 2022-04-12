/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 21:25:06 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/03/11 13:23:08 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_nm.h"

int append_meta_file(t_meta_file meta_file)
{
    t_meta_file *new_meta_files = NULL;
    size_t i = 0;

    if (!(new_meta_files = (t_meta_file *)malloc(META_FILE_SIZE * (get_nm()->meta_file_count + 1))))
        return (FAILURE);
    while (i < get_nm()->meta_file_count)
    {
        new_meta_files[i] = get_nm()->meta_files[i];
        ++i;
    }
    new_meta_files[i] = meta_file;
    get_nm()->meta_file_count++;
    free(get_nm()->meta_files);
    get_nm()->meta_files = new_meta_files;
    return (SUCCESS);
}
