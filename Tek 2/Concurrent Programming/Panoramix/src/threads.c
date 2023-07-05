/*
** EPITECH PROJECT, 2022
** Panoramix
** File description:
** threads.c
*/

#include "panoramix.h"

static bool loop_villager(panoramix_t *panoramix, long id, int i)
{
    pthread_mutex_lock(&panoramix->mutex);
    if (panoramix->nb_servings == 0 && panoramix->nb_refills == 0) {
        pthread_mutex_unlock(&panoramix->mutex);
        return false;
    }
    printf("Villager %ld: I need a drink... I see %d servings left.\n",
        id, panoramix->nb_servings);
    if (panoramix->nb_servings == 0) {
        printf("Villager %ld: Hey Pano wake up! We need more potion.\n", id);
        sem_post(&panoramix->druid_sem);
        sem_wait(&panoramix->villager_sem);
    }
    panoramix->nb_servings--;
    printf("Villager %ld: Take that roman scum! Only %d left.\n",
    id, panoramix->nb_fights - i - 1);
    pthread_mutex_unlock(&panoramix->mutex);
    return true;
}

void *villager_thread(void *arg)
{
    panoramix_t *panoramix = (panoramix_t*) arg;
    long id = panoramix->next_villager_id++;
    printf("Villager %ld: Going into battle !\n", id);
    for (int i = 0; i < panoramix->nb_fights; i++)
        if (loop_villager(panoramix, id, i) == false)
            break;

    printf("Villager %ld: I'm going to sleep now.\n", id);
    sem_post(&panoramix->druid_sem);
    return NULL;
}

static int loop_druid(panoramix_t *panoramix, int refills_left)
{
    sem_wait(&panoramix->druid_sem);
    printf("Druid: Ah! Yes, yes, I'm awake! Working on it! \
Beware I can only make %d more refills after this one.\n", refills_left - 1);
    panoramix->nb_servings = panoramix->pot_size;
    for (int i = 0; i < panoramix->nb_villagers; i++)
        sem_post(&panoramix->villager_sem);
    refills_left--;
    return refills_left;
}

void *druid_thread(void *arg)
{
    panoramix_t *panoramix = (panoramix_t*) arg;
    printf("Druid: I'm ready... but sleepy...\n");
    int refills_left = panoramix->nb_refills;

    while (refills_left > 0)
        refills_left = loop_druid(panoramix, refills_left);

    panoramix->nb_refills = 0;
    printf("Druid: I'm out of viscum. I'm going back to... zZz\n");

    for (int i = 0; i < panoramix->nb_villagers; i++)
        sem_post(&panoramix->villager_sem);
    return NULL;
}
