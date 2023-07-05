/*
** EPITECH PROJECT, 2022
** Panoramix
** File description:
** panoramix.h
*/


#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILED 84
#define UNUSED __attribute__((unused))
#define USAGE "USAGE: ./panoramix <nb_villagers> <pot_size> \
<nb_fights> <nb_refills>\n"
#define WRONG_ARG "Values must be >0.\n"

typedef struct panoramix_s {
    int nb_villagers;
    int pot_size;
    int nb_fights;
    int nb_refills;
    int nb_servings;
    long next_villager_id;
    pthread_mutex_t mutex;
    sem_t villager_sem;
    sem_t druid_sem;
} panoramix_t;


// Function prototypes
void *villager_thread(void *arg);
void *druid_thread(void *arg);
