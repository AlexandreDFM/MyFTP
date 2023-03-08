/*
** EPITECH PROJECT, 2023
** B-NWP-400-NCE-4-1-myftp-alexandre-kevin.de-freitas-martins
** File description:
** my_frees
*/

#include "../include/myftp.h"

void free_map(map_t *map)
{
    if (map->next != NULL)
        free_map(map->next);
    free(map);
}
