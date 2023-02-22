/*
** EPITECH PROJECT, 2023
** B-NWP-400-NCE-4-1-myftp-alexandre-kevin.de-freitas-martins
** File description:
** server.c
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

void server_loop(client_t client)
{
    char hello[] = "Hello World!!!\n";
    int new_socket = accept(client.socket_fd,
    (struct sockaddr *)&client.socket_address,
    (socklen_t *)&client.socket_address_len);
    send(new_socket, hello, strlen(hello), 0);
    printf("Connection from %s:%d\n",
    inet_ntoa(client.socket_address.sin_addr),
    ntohs(client.socket_address.sin_port));
    close(new_socket); return;
}

void server(int port, char *path)
{
    (void)path; client_t client;
    client.socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client.socket_fd < 0) {
        printf("Error while creating socket\n"); exit(84);
    }
    if (setsockopt(client.socket_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
    &(int){1}, sizeof(int)) < 0) {
        printf("Error while setting socket options\n"); exit(84);
    }
    client.socket_address = create_socket_address(port);
    client.socket_address_len = sizeof(client.socket_address);
    if (bind(client.socket_fd, (struct sockaddr *)&client.socket_address,
    sizeof(client.socket_address)) < 0) {
        printf("Error while binding socket\n"); exit(84);
    }
    for (;listen(client.socket_fd, 3) >= 0;) server_loop(client);
}
