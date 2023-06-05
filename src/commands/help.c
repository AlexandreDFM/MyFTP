/*
** EPITECH PROJECT, 2023
** B-NWP-400-NCE-4-1-myftp-alexandre-kevin.de-freitas-martins
** File description:
** help.c
*/

#include "../../include/myftp.h"

void help(client_t *client)
{
    write(client->cl_fd, HELP_1, strlen(HELP_1));
    write(client->cl_fd, HELP_2, strlen(HELP_2));
    write(client->cl_fd, HELP_3, strlen(HELP_3));
    write(client->cl_fd, HELP_4, strlen(HELP_4));
}
