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
    fprintf(client->client_fd, "200 NOOP command successful.\r\n");
}

void retr(client_t *client)
{
    if (!client->is_logged) return not_logged(client);
    if (client->buffer[0] == '\0')
        fprintf(client->client_fd, "550 Failed to open file.\r\n");
    else
        return;
}

void stor(client_t *client)
{
    if (!client->is_logged) return not_logged(client);
    if (client->buffer[0] == '\0')
        fprintf(client->client_fd, "550 Failed to open file.\r\n");
    else
        return;
}

void list(client_t *client)
{
    if (!client->is_logged) return not_logged(client);
    if (client->buffer[0] == '\0')
        fprintf(client->client_fd, "550 Failed to open file.\r\n");
    else
        return;
}
