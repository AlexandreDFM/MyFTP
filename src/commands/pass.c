/*
** EPITECH PROJECT, 2023
** B-NWP-400-NCE-4-1-myftp-alexandre-kevin.de-freitas-martins
** File description:
** pass.c
*/

#include "../../include/myftp.h"

void pass(client_t *client)
{
    if (client->password != NULL) {
        free(client->password); client->password = strdup("");
    }
    int len_command = 0;
    for (commands_lines_t *tmp = client->commands_lines; tmp;
    tmp = tmp->next, len_command++) {
        if (len_command == 1) {
            free(client->password); client->password = strdup(tmp->argument);
        }
        if (len_command >= 2) return not_logged(client);
    }
    if (strcmp(client->username, USERNAME) == 0 &&
        strcmp(client->password, PASSWORD) == 0) {
        write(client->cl_fd, PASS, strlen(PASS));
        client->is_logged = true;
    } else {
        write(client->cl_fd, PASS_FAIL, strlen(PASS_FAIL));
    }
}
