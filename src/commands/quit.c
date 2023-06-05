/*
** EPITECH PROJECT, 2023
** B-NWP-400-NCE-4-1-myftp-alexandre-kevin.de-freitas-martins
** File description:
** quit.c
*/

#include "../../include/myftp.h"

void quit(client_t *client)
{
    if (!client->is_logged) return not_logged(client);
    write(client->cl_fd, QUIT, strlen(QUIT));
    printf("Client disconnected.\n");
    destroy_client(client);
}
