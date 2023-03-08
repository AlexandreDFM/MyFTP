/*
** EPITECH PROJECT, 2023
** B-NWP-400-NCE-4-1-myftp-alexandre-kevin.de-freitas-martins
** File description:
** my_read.c
*/

#include "../include/myftp.h"

char *my_read(char *path)
{
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        printf("Error while opening file\n"); exit(84);
    }
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);
    char *file_content = malloc(sizeof(char) * (file_size + 1));
    if (file_content == NULL) {
        printf("Error while allocating memory\n"); exit(84);
    }
    fread(file_content, sizeof(char), file_size, file);
    file_content[file_size] = '\0';
    fclose(file);
    return file_content;
}

char *my_read_connected(int socket_fd)
{
    char *buffer = malloc(sizeof(char) * 1024);
    if (buffer == NULL) {
        printf("Error while allocating memory\n"); exit(84);
    }
    read(socket_fd, buffer, 1024);
    return buffer;
}
