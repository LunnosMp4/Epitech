/*
** EPITECH PROJECT, 2022
** Panoramix
** File description:
** main.c
*/

#include "panoramix.h"

panoramix_t *init_panoramix(char **av)
{
    panoramix_t *panoramix = malloc(sizeof(panoramix_t));

    panoramix->nb_villagers = atoi(av[1]);
    panoramix->pot_size = atoi(av[2]);
    panoramix->nb_fights = atoi(av[3]);
    panoramix->nb_refills = atoi(av[4]);
    if (panoramix->nb_villagers <= 0 || panoramix->pot_size <= 0 ||
    panoramix->nb_fights <= 0 || panoramix->nb_refills <= 0) {
        free(panoramix);
        return NULL;
    }
    panoramix->nb_servings = panoramix->pot_size;
    sem_init(&panoramix->druid_sem, 0, 0);

    return panoramix;
}

int create_join_threads(panoramix_t *panoramix, pthread_t *threads)
{
    if (pthread_create(&threads[0], NULL, druid_thread, panoramix))
        return EXIT_FAILED;

    for (long i = 1; i <= panoramix->nb_villagers; i++) {
        if (pthread_create(&threads[i], NULL,
        villager_thread, (void*) panoramix))
            return EXIT_FAILED;
    }

    for (long i = 1; i <= panoramix->nb_villagers; i++) {
        if (pthread_join(threads[i], NULL))
            return EXIT_FAILED;
    }
    pthread_cancel(threads[0]);
    if (pthread_join(threads[0], NULL))
        return EXIT_FAILED;

    return EXIT_SUCCESS;
}

int start_threads(panoramix_t *panoramix)
{
    sem_init(&panoramix->druid_sem, 0, 0);
    sem_init(&panoramix->villager_sem, 0, 0);
    pthread_mutex_init(&panoramix->mutex, NULL);

    pthread_t *threads = malloc(sizeof(pthread_t) *
    (panoramix->nb_villagers + 1));
    if (threads == NULL)
        return EXIT_FAILED;

    if (create_join_threads(panoramix, threads) == EXIT_FAILED) {
        free(threads);
        return EXIT_FAILED;
    }

    free(threads);
    return 0;
}

int main(int ac, char **av)
{
    if (ac != 5) {
        fprintf(stderr, USAGE);
        return EXIT_FAILED;
    }

    panoramix_t *panoramix = NULL;
    if ((panoramix = init_panoramix(av)) == NULL) {
        fprintf(stderr, WRONG_ARG);
        return EXIT_FAILED;
    }

    if (start_threads(panoramix) == EXIT_FAILED) {
        fprintf(stderr, "Error: Failed to start threads.\n");
        free(panoramix);
        return EXIT_FAILED;
    }

    free(panoramix);
    return EXIT_SUCCESS;
}
