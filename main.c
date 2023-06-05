/*
** EPITECH PROJECT, 2023
** B-NWP-400-NCE-4-1-fu_myftp-alexandre-kevin.de-freitas-martins
** File description:
** main.c
*/

#include "./include/myftp.h"

server_t *get_server(void)
{
    static server_t server;
    return (&server);
}

void sig_handler(int signum)
{
    (void)signum;
    server_t *server = get_server();
    printf("\n");
    destroy_server(server);
    printf("Server closed.\n");
    exit(0);
}

void print_usage(void)
{
    printf("USAGE: ./myftp port path\n");
    printf("       port is the port number on which the server socket"
    "listens\n");
    printf("       path is the path to the home directory for the "
    "Anonymous user\n");
}

int main(int argc, char **argv)
{
    if (argc == 2 && strcmp(argv[1], "-help") == 0) {
        print_usage(); return 0;
    }
    if (argc != 3) return (84);
    if (atoi(argv[1]) < 1024 || atoi(argv[1]) > 65535) {
        printf("Port must be between 1024 and 65535\n");
        return 84;
    }
    if (chdir(argv[2]) == -1) {
        printf("Invalid path\n");
        return 84;
    }
    signal(SIGINT, sig_handler);
    server(atoi(argv[1]), argv[2]);
    return 0;
}
