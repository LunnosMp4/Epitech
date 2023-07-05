/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** type.h
*/

#ifndef TYPE_H_
    #define TYPE_H_
    #include "graphic.h"
    #include "object.h"
    #include "text.h"

typedef struct type_s {
    lnk_tlist_t *buttons;
    object_t *bg;
    lnk_tlist_t *texts;
} type_t;

type_t *create_type(void);

#endif /* TYPE_H_ */
