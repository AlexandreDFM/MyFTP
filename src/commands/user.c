/*
** EPITECH PROJECT, 2023
** B-NWP-400-NCE-4-1-myftp-alexandre-kevin.de-freitas-martins
** File description:
** user.c
*/

#include "../../include/myftp.h"

void user(client_t *client)
{
    int len_command = 0;
    for (commands_lines_t *tmp = client->commands_lines; tmp; tmp = tmp->next,
            len_command++);
    if (len_command == 0) {
        not_logged(client); return;
    }
    len_command = 0;
    if (client->username != NULL) {
        free(client->username); client->username = NULL;
    }
    for (commands_lines_t *tmp = client->commands_lines; tmp; tmp = tmp->next,
            len_command++) {
        if (len_command == 1) client->username = strdup(tmp->argument);
        if (len_command >= 2) return not_logged(client);
    }
    write(client->cl_fd, USER, strlen(USER));
}
