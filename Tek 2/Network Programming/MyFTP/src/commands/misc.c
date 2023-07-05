/*
** EPITECH PROJECT, 2022
** B-NWP-400-MPL-4-1-myftp-loic.tisseyre
** File description:
** misc.c
*/

#include "myftp.h"

void display_specific_cmd(struct clients_data_t *client, char *args,
struct help_struct_t help_messages[])
{
    bool found = false;
    for (int i = 0; i < 15; i++) {
        if (strcasecmp(args, help_messages[i].name) == 0) {
            dprintf(client->fd, "214 %s", help_messages[i].help);
            found = true;
            break;
        }
    }
    if (!found) {
        dprintf(client->fd, "500 Unknown command '%s'\r\n", args);
    }
}

bool display_help_cmd(struct clients_data_t *client, char *args,
struct help_struct_t help_messages[])
{
    args[strlen(args) - 2] = '\0';
    if (!check_commands(client, args, (bool[]){false, false, true}, 0))
        return false;
    if (strlen(args) == 0) {
        dprintf(client->fd, "214 The following commands are recognized: \
USER PASS QUIT PASV PORT NOOP HELP CWD CDUP PWD RETR STOR LIST\r\n");
    } else
        display_specific_cmd(client, args, help_messages);
    return true;
}

bool display_help(struct clients_data_t *client, char *args)
{
    struct help_struct_t help_messages[] = {
        {"USER", "Syntax: USER <username>\r\n"},
        {"PASS", "Syntax: PASS <password>\r\n"},
        {"QUIT", "Syntax: QUIT\r\n"},
        {"PASV", "Syntax: PASV\r\n"},
        {"PORT", "Syntax: PORT <ip_address> <port_number>\r\n"},
        {"NOOP", "Syntax: NOOP\r\n"},
        {"HELP", "Syntax: HELP [command]\r\n"},
        {"CWD", "Syntax: CWD <directory_name>\r\n"},
        {"CDUP", "Syntax: CDUP\r\n"},
        {"PWD", "Syntax: PWD\r\n"},
        {"RETR", "Syntax: RETR <file_name>\r\n"},
        {"STOR", "Syntax: STOR <file_name>\r\n"},
        {"LIST", "Syntax: LIST [directory_name]\r\n"},
        {"RMD", "Syntax: RMD <directory_name>\r\n"},
        {"MKD", "Syntax: MKD <directory_name>\r\n"}
    };

    return display_help_cmd(client, args, help_messages);
}

bool noop(struct clients_data_t *client, UNUSED char *args)
{
    if (!check_commands(client, args, (bool[]){false, false, false}, 0))
        return false;
    dprintf(client->fd, "200 Command okay.\r\n");
    return true;
}
