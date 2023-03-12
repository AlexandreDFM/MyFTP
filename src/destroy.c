/*
** EPITECH PROJECT, 2023
** B-NWP-400-NCE-4-1-myftp-alexandre-kevin.de-freitas-martins
** File description:
** destroy
*/

#include "../include/myftp.h"

void destroy_client(client_t *client)
{
    fclose(client->client_fd);
    free(client->buffer);
    free_map(client->commands);
    close(client->cl_fd_socket);
}

void destroy_server(server_t *server)
{
    close(server->socket_fd);
}
