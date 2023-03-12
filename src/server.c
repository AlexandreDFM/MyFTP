/*
** EPITECH PROJECT, 2023
** B-NWP-400-NCE-4-1-fu_myftp-alexandre-kevin.de-freitas-martins
** File description:
** server.c
*/

#include "../include/myftp.h"

void server_loop(server_t *s)
{
    server_select(s);
    if (s->rselect > 0 && FD_ISSET(s->socket_fd, &s->read_fds))
        handle_new_client(s);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (s->clients[i].cl_fd != NO_SOCKET)
            client_select(&s->clients[i]);
        else
            continue;
        if (s->clients[i].rselect == -1) continue;
        if (FD_ISSET(s->clients[i].cl_fd, &s->clients[i].read_fds))
            client_management(s, &s->clients[i]);
    }
}

void server(int port, char *path)
{
    server_t *server = get_server();
    fill_server(server, port, path);
    if (bind(server->socket_fd, (struct sockaddr *)&server->socket_address,
    sizeof(server->socket_address)) < 0) {
        perror("bind"); exit(84);
    }
    if (listen(server->socket_fd, 20) < 0) {
        perror("Error too much connexions"); exit(84);
    }
    for (;;) {
        server_loop(server);
    }
}
