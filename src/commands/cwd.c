/*
** EPITECH PROJECT, 2023
** B-NWP-400-NCE-4-1-myftp-alexandre-kevin.de-freitas-martins
** File description:
** cwd.c
*/

#include "../../include/myftp.h"

void cwd(client_t *client)
{
    if (!client->is_logged) return not_logged(client);
    int len_command = 0;
    for (commands_lines_t *tmp = client->commands_lines; tmp;
    tmp = tmp->next, len_command++);
    if (len_command < 2) {
        write(client->cl_fd, CWD_FAIL, strlen(CWD_FAIL)); return;
    }
    if (chdir(client->commands_lines->next->argument) == -1) {
        write(client->cl_fd, CWD_FAIL, strlen(CWD_FAIL)); return;
    }
    write(client->cl_fd, CWD, strlen(CWD));
    if (client->pwd != NULL) free(client->pwd);
    client->pwd = strdup(client->commands_lines->next->argument);
}
