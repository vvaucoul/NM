/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_04.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:17:46 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/03/31 14:29:11 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void *routine()
{
    size_t i = 0;

    usleep(100000);
    while (i <= 42)
    {
        printf("Hello world! [%ld]\n", i);
        ++i;
        usleep(100000);
    }
    return (NULL);
}

int main()
{
    size_t count = 10;

    pthread_t *threads = malloc(sizeof(pthread_t) * count);
    for (size_t i = 0; i < count; i++)
    {
        pthread_create(&threads[i], NULL, *routine, NULL);
    }
        usleep(100000);
    for (size_t i = 0; i < count; i++)
    {
        pthread_join(threads[i], NULL);
    }
    free(threads);
}