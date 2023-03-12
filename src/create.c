/*
** EPITECH PROJECT, 2023
** B-NWP-400-NCE-4-1-myftp-alexandre-kevin.de-freitas-martins
** File description:
** create
*/

#include "../include/myftp.h"

struct commands_lines_s *create_commands_lines(char *argument)
{
    struct commands_lines_s *commands_lines =
    malloc(sizeof(struct commands_lines_s));
    commands_lines->argument = strtok(argument, " \r\n");
    commands_lines->next = NULL;
    for (char *token = strtok(NULL, " \r\n"); token != NULL;
    token = strtok(NULL, " \r\n")) {
        struct commands_lines_s *new = malloc(sizeof(struct commands_lines_s));
        new->argument = token;
        new->next = NULL;
        struct commands_lines_s *tmp = commands_lines;
        for (; tmp->next != NULL; tmp = tmp->next);
        tmp->next = new;
    }
    return commands_lines;
}

struct sockaddr_in create_socket_address(int port)
{
    struct sockaddr_in socket_address;
    socket_address.sin_family = AF_INET;
    socket_address.sin_addr.s_addr = INADDR_ANY;
    socket_address.sin_port = htons(port);
    return socket_address;
}

struct commands_s *fill_map(char **fct_names, void **fct_pointers)
{
    struct commands_s *head = malloc(sizeof(struct commands_s));
    head->key = fct_names[0];
    head->command = fct_pointers[0];
    head->next = NULL;
    for (int i = 1; fct_names[i] != NULL; i++) {
        struct commands_s *new = malloc(sizeof(struct commands_s));
        new->key = fct_names[i];
        new->command = fct_pointers[i];
        new->next = head;
        head = new;
    }
    return head;
}

struct client_s create_client(int server_port, int client_socket)
{
    client_t client;
    client.rselect = 0;
    client.len_buffer = 2048;
    client.buffer = malloc(sizeof(char) * client.len_buffer);
    client.cl_fd = client_socket;
    FD_ZERO(&client.read_fds); FD_SET(client_socket, &client.read_fds);
    client.timeout.tv_sec = 0; client.timeout.tv_usec = 0;
    client.socket_address = create_socket_address(server_port);
    client.socket_address_len = sizeof(client.socket_address);
    client.commands_lines = NULL;
    client.is_active = true; client.is_logged = false;
    client.username = NULL; client.password = strdup("");
    return client;
}

void fill_server(server_t *server, int server_port, char *path)
{
    server->pwd = path; server->port = server_port; server->rselect = 0;
    server->socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server->socket_fd < 0) {
        perror("socket_fd"); exit(84);
    }
    char *fct_names[] = {"USER", "PASS", "CWD", "CDUP", "QUIT", "DELE", "PWD",
    "PASV", "PORT", "HELP", "NOOP", "RETR", "STOR", "LIST", NULL};
    void *fct_pointers[] = {&user, &pass, &cwd, &cdup, &quit, &dele, &pwd,
    &pasv, &port, &help, &noop, &retr, &stor, &list, NULL};
    server->commands = fill_map(fct_names, fct_pointers);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        server->clients[i].cl_fd = NO_SOCKET;
    }
    FD_ZERO(&server->read_fds);
    FD_SET(server->socket_fd, &server->read_fds);
    server->timeout.tv_sec = 0; server->timeout.tv_usec = 0;
    server->socket_address = create_socket_address(server_port);
    server->socket_address_len = sizeof(server->socket_address);
}
