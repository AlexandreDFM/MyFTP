/*
** EPITECH PROJECT, 2023
** B-NWP-400-NCE-4-1-myftp-alexandre-kevin.de-freitas-martins
** File description:
** my_write.c
*/

#include "../include/myftp.h"

void write_file(int socket_fd, char *filename)
{
    char buffer[FILE_SIZE]; int fd = 0;
    FILE *fp = fopen(filename, "w");
    while (1) {
        fd = write(socket_fd, buffer, FILE_SIZE);
        if (fd <= 0) break;
        fprintf(fp, "%s", buffer);
        bzero(buffer, FILE_SIZE);
    }
    return;
}
