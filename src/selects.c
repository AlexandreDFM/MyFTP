/*
** EPITECH PROJECT, 2023
** B-NWP-400-NCE-4-1-myftp-alexandre-kevin.de-freitas-martins
** File description:
** selects
*/

#include "../include/myftp.h"

void server_select(server_t *s)
{
    FD_ZERO(&s->read_fds);
    FD_SET(s->socket_fd, &s->read_fds);
    s->timeout.tv_sec = 2;
    s->timeout.tv_usec = 0;
    s->rselect = select(s->socket_fd + 1, &s->read_fds, NULL, NULL,
    &s->timeout);
}

void client_select(client_t *c)
{
    FD_ZERO(&c->read_fds);
    FD_SET(c->cl_fd, &c->read_fds);
    c->timeout.tv_sec = 2;
    c->timeout.tv_usec = 0;
    c->rselect = select(c->cl_fd + 1, &c->read_fds, NULL, NULL,
    &c->timeout);
}
