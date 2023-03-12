/*
** EPITECH PROJECT, 2023
** B-NWP-400-NCE-4-1-myftp-alexandre-kevin.de-freitas-martins
** File description:
** destroy
*/

#include "../include/myftp.h"

void destroy_client(client_t *client)
{
    if (client->cl_fd == NO_SOCKET) return;
    free(client->pwd);
    free(client->buffer);
    close(client->cl_fd);
    client->cl_fd = NO_SOCKET;
}

void destroy_server(server_t *server)
{
    for (int i = 0; i < MAX_CLIENTS; i++)
        destroy_client(&server->clients[i]);
    free_map(server->commands);
    free(server->pwd);
    close(server->socket_fd);
}
