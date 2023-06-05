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
    #include <signal.h>

    #define MAX_CLIENTS 20
    #define FILE_SIZE 1024
    #define NO_SOCKET -1
    #define USERNAME "Anonymous"
    #define PASSWORD ""

    #define USER "331 Please specify the password.\r\n"
    #define PASS "230 Login successful.\r\n"
    #define PASS_FAIL "530 Login or password incorrect.\r\n"
    #define CWD "250 Directory successfully changed.\r\n"
    #define CWD_FAIL "550 Failed to change directory.\r\n"
    #define CDUP "200 Directory successfully changed.\r\n"
    #define CDUP_FAIL "550 Failed to change directory.\r\n"
    #define QUIT "221 Goodbye.\r\n"
    #define DELE "250 Requested file action okay, completed.\r\n"
    #define DELE_FAIL "550 Failed to delete file.\r\n"
    #define PWD_CODE "257 "
    #define PWD_MESSAGE " is current directory.\r\n"
    #define PASV "227 Entering Passive Mode (127,0,0,1,0,20).\r\n"
    #define PORT "200 PORT commands successful.\r\n"
    #define HELP_1 "214-The following commands are recognized.\r\n"
    #define HELP_2 "214-USER PASS CWD CDUP QUIT DELE PWD"
    #define HELP_3 " PASV PORT HELP NOOP RETR STOR\r\n"
    #define HELP_4 "214 HELP NOOP RETR STOR\r\n"
    #define NOOP "200 NOOP commands successful.\r\n"
    #define RETR "150 File status okay; about to open data connection.\r\n"
    #define RETR_FAIL "550 Failed to open file.\r\n"
    #define STOR "150 File status okay; about to open data connection.\r\n"
    #define STOR_FAIL "550 Failed to open file.\r\n"
    #define LIST "150 Here comes the directory listing.\r\n"
    #define LIST_FAIL "550 Failed to open directory.\r\n"
    #define NOT_LOGGED "530 Please login with USER and PASS.\r\n"

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
    int rselect;
    char *pwd;
    char *buffer;
    char *username;
    char *password;
    bool is_active;
    bool is_logged;
    fd_set read_fds;
    size_t len_buffer;
    int cl_fd;
    int socket_address_len;
    struct timeval timeout;
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

    struct commands_s *commands;

    struct client_s clients[MAX_CLIENTS];
} server_t;

char *my_read(char *path);
server_t *get_server(void);
void free_map(commands_t *map);
void server(int port, char *path);
void sig_handler(int signum);
char *my_read_connected(int socket_fd);
void write_file(int socket_fd, char *filename);
void server_select(server_t *s);
void client_select(client_t *c);
void check_fct(server_t *server, client_t *cl);
void client_management(server_t *server, client_t *client);
void handle_new_client(server_t *s);

//////////////////////////CREATE/////////////////////////////
struct sockaddr_in create_socket_address(int port);
void fill_server(server_t *server, int port, char *path);
struct commands_lines_s *create_commands_lines(char *argument);
struct client_s create_client(int server_port, int client_socket, char *path);

//////////////////////////FREES//////////////////////////////
void free_commands_lines(commands_lines_t *commands_lines);

//////////////////////////DESTROY////////////////////////////
void destroy_client(client_t *client);
void destroy_server(server_t *server);

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

/////////////////COMMANDS_4/////////////////
void not_logged(client_t *client);

//////////////////////////UTILS/////////////////////////////


#endif /*MYFTP_H_*///
