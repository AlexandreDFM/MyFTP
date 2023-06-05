/*
** EPITECH PROJECT, 2023
** B-NWP-400-NCE-4-1-myftp-alexandre-kevin.de-freitas-martins
** File description:
** not_logged.c
*/

#include "../../include/myftp.h"

void not_logged(client_t *client)
{
    write(client->cl_fd, NOT_LOGGED, strlen(NOT_LOGGED));
}
