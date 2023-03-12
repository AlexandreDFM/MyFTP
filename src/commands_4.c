/*
** EPITECH PROJECT, 2023
** B-NWP-400-NCE-4-1-myftp-alexandre-kevin.de-freitas-martins
** File description:
** commands
*/

#include "../include/myftp.h"

void not_logged(client_t *client)
{
    fprintf(client->client_fd, "530 Please login with USER and PASS.\r\n");
}
