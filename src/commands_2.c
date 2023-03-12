/*
** EPITECH PROJECT, 2023
** B-NWP-400-NCE-4-1-myftp-alexandre-kevin.de-freitas-martins
** File description:
** commands
*/

#include "../include/myftp.h"

void dele(client_t *client)
{
    if (!client->is_logged) return not_logged(client);
    int len_command = 0;
    for (commands_lines_t *tmp = client->commands_lines; tmp;
    tmp = tmp->next, len_command++);
    if (len_command < 2) {
        write(client->cl_fd, DELE_FAIL, strlen(DELE_FAIL)); return;
    }
    remove(client->commands_lines->next->argument);
    write(client->cl_fd, DELE, strlen(DELE));
}

void pwd(client_t *client)
{
    if (!client->is_logged) return not_logged(client);
    write(client->cl_fd, PWD_CODE, strlen(PWD_CODE));
    write(client->cl_fd, client->pwd, strlen(client->pwd));
    write(client->cl_fd, PWD_MESSAGE, strlen(PWD_MESSAGE));
}

void pasv(client_t *client)
{
    if (!client->is_logged) return not_logged(client);
    int len_command = 0;
    for (commands_lines_t *tmp = client->commands_lines; tmp;
    tmp = tmp->next, len_command++);
    if (len_command < 2) return;
    write(client->cl_fd, PASV, strlen(PASV));
}

void port(client_t *client)
{
    if (!client->is_logged) return not_logged(client);
    int len_command = 0;
    for (commands_lines_t *tmp = client->commands_lines; tmp;
    tmp = tmp->next, len_command++);
    if (len_command < 2) return;
    write(client->cl_fd, PORT, strlen(PORT));
}

void help(client_t *client)
{
    write(client->cl_fd, HELP_1, strlen(HELP_1));
    write(client->cl_fd, HELP_2, strlen(HELP_2));
    write(client->cl_fd, HELP_3, strlen(HELP_3));
    write(client->cl_fd, HELP_4, strlen(HELP_4));
}
