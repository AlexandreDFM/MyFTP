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
    write(client->cl_fd, "200 NOOP command successful.\r\n", 29);
}

void retr(client_t *client)
{
    if (!client->is_logged) return not_logged(client);
    if (client->buffer[0] == '\0')
        write(client->cl_fd, "550 Failed to open file.\r\n", 26);
    else
        return;
}

void stor(client_t *client)
{
    if (!client->is_logged) return not_logged(client);
    if (client->buffer[0] == '\0')
        write(client->cl_fd, "550 Failed to open file.\r\n", 26);
    else
        return;
}

void list(client_t *client)
{
    if (!client->is_logged) return not_logged(client);
    if (client->buffer[0] == '\0')
        write(client->cl_fd, "550 Failed to open file.\r\n", 26);
    else
        return;
}
