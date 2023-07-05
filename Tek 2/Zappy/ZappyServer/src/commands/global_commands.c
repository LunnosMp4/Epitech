/*
** EPITECH PROJECT, 2023
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** global_commands
*/

#include "server.h"

const command_handler commands[NB_CMDS] = {
    &forward,
    &right,
    &left,
    &look,
    &inventory,
    &broadcast,
    &connect_nbr,
    &fork_f,
    &eject,
    &take,
    &set,
    &incantation
};

const commands_no_timer real_commands[NB_CMDS] = {
    &forward_r,
    &right_r,
    &left_r,
    &look_r,
    &inventory_r,
    &broadcast_r,
    &connect_nbr_r,
    &fork_r,
    &eject_r,
    &take_r,
    &set_r,
    &incantation_r
};

const command_gui gui_commands[NB_CMDS] = {
    &msz,
    &sgt,
    &mct,
    &tna,
    &plv,
    &pnw,
    &sst,
    &bct,
    &pin,
    &ppo
};
