/*
** EPITECH PROJECT, 2023
** B-NWP-400-NCE-4-1-myftp-alexandre-kevin.de-freitas-martins
** File description:
** pwd.c
*/

#include "../../include/myftp.h"

void pwd(client_t *client)
{
    if (!client->is_logged) return not_logged(client);
    write(client->cl_fd, PWD_CODE, strlen(PWD_CODE));
    write(client->cl_fd, client->pwd, strlen(client->pwd));
    write(client->cl_fd, PWD_MESSAGE, strlen(PWD_MESSAGE));
}
