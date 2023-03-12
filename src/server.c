/*
** EPITECH PROJECT, 2023
** B-NWP-400-NCE-4-1-fu_myftp-alexandre-kevin.de-freitas-martins
** File description:
** server.c
*/

#include "../include/myftp.h"

void check_fct(client_t *cl)
{
    bool isCommand = false;
    cl->commands_lines = create_commands_lines(cl->buffer);
    for (commands_t *tmp = cl->commands; tmp != NULL; tmp = tmp->next) {
        if (strncmp(tmp->key, cl->buffer, strlen(tmp->key)) == 0) {
            tmp->command(cl); isCommand = true; break;
        }
    }
    if (isCommand == false) fprintf(cl->client_fd, "500 Unknown command.\r\n");
    free_commands_lines(cl->commands_lines); cl->commands_lines = NULL;
}

void client_management(client_t c)
{
    for (; c.is_active == true &&
    getline(&c.buffer, &c.len_buffer, c.client_fd) > 0;) {
        c.rselect = select(c.cl_fd_socket + 1, &c.read_fds, NULL, NULL,
        &c.timeout);
        check_fct(&c);
    }
    printf("Client disconnected.\n");
    destroy_client(&c);
}

void server_loop(server_t *s)
{
    for (;;) {
        s->rselect = select(s->socket_fd + 1, &s->read_fds, NULL,
        NULL, &s->timeout);
        if (s->rselect == -1 || FD_ISSET(s->socket_fd, &s->read_fds) <= 0) {
            printf("Personne %d %d \n", s->rselect, FD_ISSET(s->socket_fd,
            &s->read_fds)); s->timeout.tv_sec = 2; s->timeout.tv_usec = 0;
            FD_ZERO(&s->read_fds); FD_SET(s->socket_fd, &s->read_fds);
            continue;
        }
        int client_socket = accept(s->socket_fd,
        (struct sockaddr *)&s->socket_address,
        (socklen_t *)&s->socket_address_len);
        if (client_socket < 0) {
            perror("accept"); exit(84);
        } client_t c = create_client(s->port, client_socket);
        printf("Connection from %s:%d\n", inet_ntoa(c.socket_address.sin_addr),
        ntohs(c.socket_address.sin_port));
        fprintf(c.client_fd, "220 Welcome to my_ftp\r\n");
        client_management(c);
    }
}

void server(int port, char *path)
{
    server_t server = create_server(port, path);
    if (bind(server.socket_fd, (struct sockaddr *)&server.socket_address,
    sizeof(server.socket_address)) < 0) {
        perror("bind"); exit(84);
    }
    if (listen(server.socket_fd, 20) < 0) {
        perror("Error too much connexions"); exit(84);
    }
    server_loop(&server); printf("Server closed.\n");
    destroy_server(&server);
}
