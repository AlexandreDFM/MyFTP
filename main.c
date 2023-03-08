/*
** EPITECH PROJECT, 2023
** B-NWP-400-NCE-4-1-fu_myftp-alexandre-kevin.de-freitas-martins
** File description:
** main.c
*/

#include "./include/myftp.h"

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
    server(atoi(argv[1]), argv[2]);
    return 0;
}
