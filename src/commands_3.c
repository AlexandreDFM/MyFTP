/*
** EPITECH PROJECT, 2023
** B-NWP-400-NCE-4-1-myftp-alexandre-kevin.de-freitas-martins
** File description:
** commands
*/

#include "../include/myftp.h"


void noop(client_t *client)
{
    if (!client->is_logged) return not_logged(client);
    write(client->cl_fd, NOOP, strlen(NOOP));
}

void retr(client_t *client)
{
    if (!client->is_logged) return not_logged(client);
    if (client->buffer[0] == '\0')
        write(client->cl_fd, RETR_FAIL, strlen(RETR_FAIL));
    else
        return;
}

void stor(client_t *client)
{
    if (!client->is_logged) return not_logged(client);
    if (client->buffer[0] == '\0')
        write(client->cl_fd, STOR_FAIL, strlen(STOR_FAIL));
    else
        return;
}

void list(client_t *client)
{
    if (!client->is_logged) return not_logged(client);
    if (client->buffer[0] == '\0')
        write(client->cl_fd, LIST_FAIL, strlen(LIST_FAIL));
    else
        return;
}
