/*
** EPITECH PROJECT, 2023
** B-NWP-400-NCE-4-1-myftp-alexandre-kevin.de-freitas-martins
** File description:
** commands
*/

#include "../include/myftp.h"

void dele(client_t *client)
{
    if (!client->is_logged) return not_logged(client);
    if (client->buffer[0] == '\0')
        write(client->cl_fd, "550 Failed to delete file.\r\n", 28);
    else
        write(client->cl_fd, "250 Delete operation successful.\r\n", 34);
}

void pwd(client_t *client)
{
    if (!client->is_logged) return not_logged(client);
    write(client->cl_fd, "257 \"/\" is current directory.\r\n", 31);
}

void pasv(client_t *client)
{
    if (!client->is_logged) return not_logged(client);
    write(client->cl_fd,
    "227 Entering Passive Mode (127,0,0,1,0,0).\r\n", 42);
}

void port(client_t *client)
{
    if (!client->is_logged) return not_logged(client);
    write(client->cl_fd, "200 PORT command successful.\r\n", 29);
}

void help(client_t *client)
{
    write(client->cl_fd,
    "214-The following commands are recognized.\r\n", 42);
    write(client->cl_fd, "214-USER PASS CWD CDUP QUIT DELE PWD PASV"
    "PORT HELP NOOP RETR STOR\r\n", 66);
    write(client->cl_fd, "214 HELP NOOP RETR STOR\r\n", 24);
}
