/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-enzo.daumalle
** File description:
** type
*/

#include "graphic.h"

text_t *create_text(utils_txt_t utils, lnk_tlist_t **texts)
{
    text_t *text = malloc(sizeof(text_t));

    text->text = sfText_create();
    text->utils = utils;
    text->font = sfFont_createFromFile("Assets/04b.ttf");
    sfText_setString(text->text, text->utils.string);
    sfText_setFont(text->text, text->font);
    sfText_setCharacterSize(text->text, text->utils.size);
    sfText_setPosition(text->text, text->utils.pos);
    sfText_setColor(text->text, text->utils.color);
    sfText_setString(text->text, text->utils.string);
    if (texts)
        add_type_node(text, texts);
    return text;
}

static object_t *create_object(utils_t utils, lnk_tlist_t **objects,
sfTexture *texture)
{
    object_t *object = malloc(sizeof(object_t));

    object->sprite = sfSprite_create();
    object->utils = utils;
    object->anim.clock = sfClock_create();
    sfSprite_setPosition(object->sprite, object->utils.pos);
    sfSprite_setTexture(object->sprite, texture, sfTrue);
    sfSprite_setTextureRect(object->sprite, object->utils.rect);
    if (objects)
        add_type_node(object, objects);
    return object;
}

static char *new_line(char *str, int sep)
{
    char *tmp = malloc(sizeof(char) * (my_strlen(str) + 1 + MEM_SIZE / sep));
    int j = 0;
    int mult = 1;

    for (int i = 0; str[i]; i++, j++) {
        if (i == sep * mult) {
            tmp[j++] = '\n';
            mult++;
        }
        tmp[j] = str[i];
    }
    tmp[j] = '\0';
    return tmp;
}

static void init_profile(type_t *type, champion_t *champ, int i)
{
    char *comment = new_line(champ->header->comment, 21);

    create_text((utils_txt_t) {{130, 10 + i}, TEXT, 30,
    champ->header->prog_name, sfWhite}, &type->texts);
    create_text((utils_txt_t) {{30, 80 + i}, TEXT, 20,
    strcat_alloc("Magic : ", itoa(champ->header->magic)),
    sfWhite}, &type->texts);
    create_text((utils_txt_t) {{30, 100 + i}, TEXT, 20,
    strcat_alloc("Prog nb : ", itoa(champ->header->prog_size)),
    sfWhite}, &type->texts);
    create_text((utils_txt_t) {{30, 120 + i}, TEXT, 20,
    strcat_alloc("Carry : ", itoa(champ->process->carry)),
    sfWhite}, &type->texts);
    create_text((utils_txt_t) {{30, 140 + i}, TEXT, 20,
    strcat_alloc("Comment : ", comment),
    sfWhite}, &type->texts);
    create_text((utils_txt_t) {{30, 200 + i}, TEXT, 20,
    strcat_alloc("Live : ", itoa(champ->nb_live)), sfWhite}, &type->texts);
}

void init_objects(type_t *type, corewar_t *corewar)
{
    sfTexture *bg = TEXTURE("Assets/Img/Background.jpg", NULL);
    sfTexture *buttons = TEXTURE("Assets/Img/Button.png", NULL);
    lnk_list_t *tmp = corewar->champs;
    char *arena = new_line(corewar->final_arena, 197);

    type->bg = create_object((utils_t) {{0, 0, 1980, 1066},
    {0, 0}, BG}, NULL, bg);
    create_object((utils_t) {{0, 0, 228, 100},
    {1196, 795}, BTN}, &type->buttons, buttons);
    create_text((utils_txt_t) {{400, 50}, TEXT, 50,
    "ARENA", sfWhite}, &type->texts);
    for (int i = 0; tmp; tmp = tmp->next, i += 270)
        init_profile(type, tmp->champ, i);
    create_text((utils_txt_t) {{390, 205}, TEXT, 17,
    arena, sfWhite}, &type->texts);
}
