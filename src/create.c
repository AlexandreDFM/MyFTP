/*
** EPITECH PROJECT, 2023
** B-NWP-400-NCE-4-1-myftp-alexandre-kevin.de-freitas-martins
** File description:
** create
*/

#include "../include/myftp.h"

struct sockaddr_in create_socket_address(int port)
{
    struct sockaddr_in socket_address;
    socket_address.sin_family = AF_INET;
    socket_address.sin_addr.s_addr = INADDR_ANY;
    socket_address.sin_port = htons(port);
    return socket_address;
}

struct map_s *fill_map(char **fct_names, void **fct_pointers)
{
    struct map_s *head = malloc(sizeof(struct map_s));
    head->key = fct_names[0];
    head->command = fct_pointers[0];
    head->next = NULL;
    for (int i = 1; fct_names[i] != NULL; i++) {
        struct map_s *new = malloc(sizeof(struct map_s));
        new->key = fct_names[i];
        new->command = fct_pointers[i];
        new->next = head;
        head = new;
    }
    return head;
}

struct client_s create_client(server_t server, int server_socket)
{
    client_t client;
    client.len_buffer = 2048;
    client.buffer = malloc(sizeof(char) * client.len_buffer);
    client.client_fd = fdopen(server_socket, "r+");
    client.socket_address = create_socket_address(server.port);
    client.socket_address_len = sizeof(client.socket_address);
    char *fct_names[] = {"USER", "PASS", "CWD", "QUIT", "HELP", NULL};
    void *fct_pointers[] = {&user, &pass, &cwd, &quit, &help, NULL};
    client.commands = fill_map(fct_names, fct_pointers);
    return client;
}

struct server_s create_server(int port, char *path)
{
    server_t server;
    server.port = port;
    server.filename = path;
    server.socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server.socket_fd < 0) {
        perror("socket_fd"); exit(84);
    }
    if (setsockopt(server.socket_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
    &(int){1}, sizeof(int)) < 0) {
        perror("setsockopt"); exit(84);
    }
    server.socket_address = create_socket_address(port);
    server.socket_address_len = sizeof(server.socket_address);
    return server;
}
