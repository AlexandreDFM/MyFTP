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
    if (client->buffer[0] == '\0')
        write(client->cl_fd, DELE_FAIL, strlen(DELE_FAIL));
    else
        write(client->cl_fd, DELE, strlen(DELE));
}

void pwd(client_t *client)
{
    if (!client->is_logged) return not_logged(client);
    write(client->cl_fd, PWD, strlen(PWD));
}

void pasv(client_t *client)
{
    if (!client->is_logged) return not_logged(client);
    write(client->cl_fd, PASV, strlen(PASV));
}

void port(client_t *client)
{
    if (!client->is_logged) return not_logged(client);
    write(client->cl_fd, PORT, strlen(PORT));
}

void help(client_t *client)
{
    write(client->cl_fd, HELP, strlen(HELP));
    write(client->cl_fd, HELP_2, strlen(HELP_2));
    write(client->cl_fd, HELP_3, strlen(HELP_3));
}
