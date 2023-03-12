/*
** EPITECH PROJECT, 2023
** B-NWP-400-NCE-4-1-myftp-alexandre-kevin.de-freitas-martins
** File description:
** client
*/

#include "../include/myftp.h"

void handle_new_client(server_t *s)
{
    int client_socket = accept(s->socket_fd,
    (struct sockaddr *)&s->socket_address,
    (socklen_t *)&s->socket_address_len);
    if (client_socket < 0) {
        perror("accept"); return;
    }
    int actual_client = 0;
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (s->clients[i].cl_fd == NO_SOCKET) {
            actual_client = i;
            s->clients[i] = create_client(s->port, client_socket, s->pwd);
            break;
        }
    }
    printf("Connection from %s:%d\n",
    inet_ntoa(s->clients[actual_client].socket_address.sin_addr),
    ntohs(s->clients[actual_client].socket_address.sin_port));
    write(s->clients[actual_client].cl_fd,
    "220 Welcome to my_ftp\r\n", 23);
}

void check_fct(server_t *server, client_t *cl)
{
    bool isCommand = false;
    cl->commands_lines = create_commands_lines(cl->buffer);
    for (commands_t *tmp = server->commands; tmp != NULL; tmp = tmp->next) {
        if (strncmp(tmp->key, cl->buffer, strlen(tmp->key)) == 0) {
            tmp->command(cl); isCommand = true; break;
        }
    }
    if (isCommand == false) write(cl->cl_fd, "500 Unknown command.\r\n", 22);
    free_commands_lines(cl->commands_lines); cl->commands_lines = NULL;
}

void client_management(server_t *server, client_t *client)
{
    memset(client->buffer, 0, 1024);
    if (read(client->cl_fd, client->buffer, 1024) > 0) {
        check_fct(server, client);
    }
}
