/*
** EPITECH PROJECT, 2023
** B-NWP-400-NCE-4-1-myftp-alexandre-kevin.de-freitas-martins
** File description:
** list.c
*/

#include "../../include/myftp.h"

void list(client_t *client)
{
    if (!client->is_logged) return not_logged(client);
    int len_command = 0;
    for (commands_lines_t *tmp = client->commands_lines; tmp;
    tmp = tmp->next, len_command++);
    if (len_command < 2) {
        write(client->cl_fd, LIST_FAIL, strlen(LIST_FAIL));
        return;
    }
}
