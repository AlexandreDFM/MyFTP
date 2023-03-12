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
    #include <stdbool.h>
    #include <sys/types.h>
    #include <netinet/in.h>
    #include <sys/select.h>
    #include <sys/socket.h>
    #include <arpa/inet.h>

    #define MAX_CLIENTS
    #define FILE_SIZE 1024
    #define USERNAME "Anonymous"
    #define PASSWORD "\n"

typedef struct client_s client_t;

typedef struct linked_list_s {
    void *data;
    struct linked_list_s *next;
} linked_list_t;

typedef struct commands_s {
    char *key;
    void (*command)(struct client_s *client);
    struct commands_s *next;
} commands_t;

typedef struct commands_lines_s {
    char *argument;
    struct commands_lines_s *next;
} commands_lines_t;

typedef struct client_s {
    int pid;
    int rselect;
    char *buffer;
    bool is_active;
    bool is_logged;
    fd_set read_fds;
    FILE *client_fd;
    size_t len_buffer;
    int cl_fd_socket;
    int socket_address_len;
    struct timeval timeout;
    struct commands_s *commands;
    struct sockaddr_in socket_address;
    struct commands_lines_s *commands_lines;
} client_t;

typedef struct server_s {
    int port;
    char *pwd;
    int rselect;
    int socket_fd;
    fd_set read_fds;
    int socket_address_len;
    struct timeval timeout;
    struct sockaddr_in socket_address;
} server_t;

char *my_read(char *path);
void free_map(commands_t *map);
void server(int port, char *path);
char *my_read_connected(int socket_fd);
void write_file(int socket_fd, char *filename);

//////////////////////////CREATE/////////////////////////////
struct sockaddr_in create_socket_address(int port);
struct server_s create_server(int port, char *path);
struct commands_lines_s *create_commands_lines(char *argument);
struct client_s create_client(int server_port, int client_socket);

//////////////////////////FREES//////////////////////////////
void free_commands_lines(commands_lines_t *commands_lines);

//////////////////////////DESTROY////////////////////////////
void destroy_client(client_t *client);


//////////////////////////LOOPS//////////////////////////////
void server_loop(server_t *server);

//////////////////////////COMMANDS//////////////////////////

/////////////////COMMANDS_1/////////////////
void user(client_t *client);
void pass(client_t *client);
void cwd(client_t *client);
void cdup(client_t *client);
void quit(client_t *client);

/////////////////COMMANDS_2/////////////////
void dele(client_t *client);
void pwd(client_t *client);
void pasv(client_t *client);
void port(client_t *client);
void help(client_t *client);

/////////////////COMMANDS_3/////////////////
void noop(client_t *client);
void retr(client_t *client);
void stor(client_t *client);
void list(client_t *client);

//////////////////////////UTILS/////////////////////////////


#endif /*MYFTP_H_*///
