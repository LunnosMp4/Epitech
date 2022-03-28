/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-mydefender-enzo.daumalle
** File description:
** read.c
*/

#include "my_defender.h"

char *read_file(char *path)
{
    int fd = 0;
    int nread = 0;
    char *buffer = NULL;
    size_t size = 10000;
    fd = open(path, O_RDONLY);

    buffer = malloc(sizeof(char) * (size + 1));
    if (fd == -1)
        return NULL;
    nread = read(fd, buffer, size);
    buffer[nread] = '\0';
    close(fd);
    return buffer;
}

static int read_first_layer(int i, char *map, lnk_ltype_t *ltype,
config_t *conf)
{
    int id = 0;
    int ii = 0;
    sfVector2i p_id = {0, -1};

    i += 1;
    conf->set_biome -= 1;
    while (map[i] >= '0' && map[i] <= '9') {
        if (map[i - 1] == '\n') {
            p_id = (sfVector2i) {0, p_id.y + 1};
            conf->map[p_id.y] = malloc(sizeof(int) * (MAPX + 1));
        }
        id = my_getnbr(map + i);
        create_texture((utils_t) {{RES * id, RES * conf->set_biome, RES, RES},
        {p_id.x * RES, p_id.y * RES}, id, TEXTURE},
        &ltype->textures, ltype->texture);
        conf->map[p_id.y][p_id.x++] = id;
        ii = i;
        if ((i = check_map_isvalid(map, ii, p_id)) != ii + 3)
            break;
    }
    return 0;
}

static int read_second_layer(char *map, lnk_ltype_t *ltype)
{
    int id = 0;
    sfVector2i p_id = {0, 0};
    int i = 0;
    int ii = 0;

    while (map[i] >= '0' && map[i] <= '9') {
        ii = i;
        if ((i = check_map_isvalid(map, ii, p_id)) != ii + 3)
            break;
        if (map[i - 1] == '\n')
            p_id = (sfVector2i) {0, p_id.y + 1};
        id = my_getnbr(map + i);
        if (id < 16)
            create_texture((utils_t) {{RES * id, 192, RES, RES},
            {p_id.x * RES, p_id.y * RES}, id, TEXTURE},
            &ltype->textures, ltype->texture);
        p_id.x += 1;
    }
    return i;
}

int read_map(char *map, lnk_ltype_t *ltype, config_t *conf)
{
    int i = read_second_layer(map, ltype);

    if (i == -1)
        return 84;
    if (read_first_layer(i, map, ltype, conf) == -1)
        return 84;
    return 0;
}
