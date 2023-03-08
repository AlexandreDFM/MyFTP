/*
** EPITECH PROJECT, 2023
** B-NWP-400-NCE-4-1-fu_myftp-alexandre-kevin.de-freitas-martins
** File description:
** server.c
*/

#include "../include/myftp.h"

void check_fct(client_t cl)
{
    for (map_t *tmp = cl.commands; tmp != NULL; tmp = tmp->next) {
        if (strncmp(tmp->key, cl.buffer,
        strlen(tmp->key)) == 0) {
            tmp->command(&cl);
            break;
        }
    }
}

void client_management(client_t cl)
{
    for (; getline(&cl.buffer, &cl.len_buffer, cl.client_fd) > 0
    && cl.isActive == true;) {
        check_fct(cl);
    }
    destroy_client(&cl);
    exit(0);
}

void server_loop(client_t client)
{
    client_management(client);
}

void server(int port, char *path)
{
    server_t server = create_server(port, path);
    if (bind(server.socket_fd, (struct sockaddr *)&server.socket_address,
    sizeof(server.socket_address)) < 0) {
        perror("build"); exit(84);
    }
    if (listen(server.socket_fd, 3) < 0) {
        perror("Error too much connexions"); exit(84);
    }
    int client_socket = accept(server.socket_fd,
    (struct sockaddr *)&server.socket_address,
    (socklen_t *)&server.socket_address_len);
    if (client_socket < 0) {
        perror("accept"); exit(84);
    }
    client_t client = create_client(server, client_socket);
    printf("Connection from %s:%d\n",
    inet_ntoa(client.socket_address.sin_addr),
    ntohs(client.socket_address.sin_port));
    fprintf(client.client_fd, "220 Welcome to my_ftp\n");
    while (1) server_loop(client);
}
