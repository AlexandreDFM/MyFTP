/*
** EPITECH PROJECT, 2023
** B-NWP-400-NCE-4-1-myftp-alexandre-kevin.de-freitas-martins
** File description:
** commands
*/

#include "../include/myftp.h"

void user(client_t *client)
{
    int len_command = 0;
    for (commands_lines_t *tmp = client->commands_lines; tmp; tmp = tmp->next,
    len_command++);
    if (len_command == 0) {
        not_logged(client); return;
    }
    len_command = 0;
    if (client->username != NULL) {
        free(client->username); client->username = NULL;
    }
    for (commands_lines_t *tmp = client->commands_lines; tmp; tmp = tmp->next,
    len_command++) {
        if (len_command == 1) client->username = strdup(tmp->argument);
        if (len_command >= 2) return not_logged(client);
    }
    write(client->cl_fd, "331 Please specify the password.\r\n", 34);
}

void pass(client_t *client)
{
    if (client->password != NULL) {
        free(client->password); client->password = strdup("");
    }
    int len_command = 0;
    for (commands_lines_t *tmp = client->commands_lines; tmp;
    tmp = tmp->next, len_command++) {
        if (len_command == 1) {
            free(client->password); client->password = strdup(tmp->argument);
        }
        if (len_command >= 2) return not_logged(client);
    }
    if (strcmp(client->username, USERNAME) == 0 &&
    strcmp(client->password, PASSWORD) == 0) {
        write(client->cl_fd, "230 Login successful.\r\n", 23);
        client->is_logged = true;
    } else {
        write(client->cl_fd, "530 Login or password incorrect.\r\n", 34);
    }
}

void cwd(client_t *client)
{
    if (!client->is_logged) return not_logged(client);
    if (client->buffer[0] == '\0')
        write(client->cl_fd, "550 Failed to change directory.\r\n", 33);
    else
        write(client->cl_fd, "250 Directory successfully changed.\r\n", 37);
}

void cdup(client_t *client)
{
    if (!client->is_logged) return not_logged(client);
    write(client->cl_fd, "200 Directory successfully changed.\r\n", 37);
}

void quit(client_t *client)
{
    if (!client->is_logged) return not_logged(client);
    write(client->cl_fd, "221 Goodbye.\r\n", 14);
    printf("Client disconnected.\n");
    destroy_client(client);
}
