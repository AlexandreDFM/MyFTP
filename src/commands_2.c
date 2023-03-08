/*
** EPITECH PROJECT, 2023
** B-NWP-400-NCE-4-1-myftp-alexandre-kevin.de-freitas-martins
** File description:
** commands
*/

#include "../include/myftp.h"

void dele(client_t *client)
{
    if (client->buffer[0] == '\0')
        fprintf(client->client_fd, "550 Failed to delete file.\r");
    else
        fprintf(client->client_fd, "250 Delete operation successful.\r");
}

void pwd(client_t *client)
{
    fprintf(client->client_fd, "257 \"/\" is current directory.\r");
}

void pasv(client_t *client)
{
    fprintf(client->client_fd, "227 Entering Passive Mode (127,0,0,1,0,0).\r");
}

void port(client_t *client)
{
    fprintf(client->client_fd, "200 PORT command successful.\r");
}

void help(client_t *client)
{
    fprintf(client->client_fd, "214-The following commands are recognized.\r");
    fprintf(client->client_fd, "214-USER PASS CWD CDUP QUIT DELE PWD PASV"
    "PORT HELP NOOP RETR STOR\r");
    fprintf(client->client_fd, "214 HELP NOOP RETR STOR\r");
}