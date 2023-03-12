/*
** EPITECH PROJECT, 2023
** B-NWP-400-NCE-4-1-myftp-alexandre-kevin.de-freitas-martins
** File description:
** commands
*/

#include "../include/myftp.h"

void user(client_t *client)
{
    if (client->buffer[0] == '\0')
        fprintf(client->client_fd, "530 Please login with USER and PASS.\r\n");
    else
        fprintf(client->client_fd, "331 Please specify the password.\r\n");
}

void pass(client_t *client)
{
    if (client->buffer[0] == '\0')
        fprintf(client->client_fd, "530 Please login with USER and PASS.\r\n");
    else
        fprintf(client->client_fd, "230 Login successful.\r\n");
}

void cwd(client_t *client)
{
    if (client->buffer[0] == '\0')
        fprintf(client->client_fd, "550 Failed to change directory.\r\n");
    else
        fprintf(client->client_fd, "250 Directory successfully changed.\r\n");
}

void cdup(client_t *client)
{
    fprintf(client->client_fd, "200 Directory successfully changed.\r\n");
}

void quit(client_t *client)
{
    fprintf(client->client_fd, "221 Goodbye.\r\n");
    client->is_active = false;
}
