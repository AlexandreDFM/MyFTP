/*
** EPITECH PROJECT, 2023
** B-NWP-400-NCE-4-1-myftp-alexandre-kevin.de-freitas-martins
** File description:
** cdup.c
*/

#include "../../include/myftp.h"

void cdup(client_t *client)
{
    if (!client->is_logged) return not_logged(client);
    write(client->cl_fd, CDUP, strlen(CDUP));
    chdir("..");
    if (client->pwd != NULL) free(client->pwd);
    client->pwd = strdup(getcwd(NULL, 0));
}
