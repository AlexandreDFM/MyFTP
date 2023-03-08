/*
** EPITECH PROJECT, 2023
** B-NWP-400-NCE-4-1-fu_myftp-alexandre-kevin.de-freitas-martins
** File description:
** fu_myftp.h
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
    #include <stdbool.h>

    #define MAX_CLIENTS
    #define FILE_SIZE 1024

typedef struct client_s client_t;

typedef struct map_s {
    char *key;
    void (*command)(struct client_s *client);
    struct map_s *next;
} map_t;

typedef struct client_s {
    int pid;
    char *buffer;
    bool isActive;
    FILE *client_fd;
    size_t len_buffer;
    struct sockaddr_in socket_address;
    int socket_address_len;
    struct map_s *commands;
} client_t;

typedef struct server_s {
    char *filename;
    int port;
    int socket_fd;
    struct sockaddr_in socket_address;
    int socket_address_len;
    int state;
//    client_t client[MAX_CLIENTS];
} server_t;

char *my_read(char *path);
void free_map(map_t *map);
void server_loop(client_t server);
void server(int port, char *path);
void destroy_client(client_t *client);
char *my_read_connected(int socket_fd);
void write_file(int socket_fd, char *filename);
struct sockaddr_in create_socket_address(int port);
struct server_s create_server(int port, char *path);
struct client_s create_client(server_t server, int client_socket);

//////////////////////////COMMANDS//////////////////////////

void cwd(client_t *client);
void quit(client_t *client);
void user(client_t *client);
void pass(client_t *client);
void help(client_t *client);


#endif /*MYFTP_H_*///
