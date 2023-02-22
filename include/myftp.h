/*
** EPITECH PROJECT, 2023
** B-NWP-400-NCE-4-1-myftp-alexandre-kevin.de-freitas-martins
** File description:
** myftp.h
*/
#ifndef MYFTP_H_
    #define MYFTP_H_
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <netinet/in.h>
    #include <sys/socket.h>
    #include <arpa/inet.h>

    #define MAX_CLIENTS 10

typedef struct client_s {
    int socket_fd;
    struct sockaddr_in socket_address;
    int socket_address_len;
    int pid;
} client_t;

typedef struct server_s {
    int socket_fd;
    struct sockaddr_in socket_address;
    int socket_address_len;
    int state;
    client_t client[MAX_CLIENTS];
} server_t;

void server(int port, char *path);

#endif /*MYFTP_H_*///
