/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_03.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:15:51 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/03/31 14:22:14 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
    char s1[13] = "Hello world!";
    char s2[13] = "Hello world!";
    char *s3 = NULL;

    if (strcmp(s1, s2) == 0)
        printf("s1 and s2 are equal\n");
    else
        printf("s1 and s2 are not equal\n");
    if (!(s3 = malloc(sizeof(char) * 13)))
        return (1);
    free(s3);
    s3 = strdup("Hello world!");
    printf("%s", s3);
    return (0);
}