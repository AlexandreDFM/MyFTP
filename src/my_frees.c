/*
** EPITECH PROJECT, 2023
** B-NWP-400-NCE-4-1-myftp-alexandre-kevin.de-freitas-martins
** File description:
** my_frees
*/

#include "../include/myftp.h"

void free_map(commands_t *map)
{
    if (map->next != NULL)
        free_map(map->next);
    free(map);
}

void my_free_datas(struct linked_list_s *list)
{
    if (list->next != NULL)
        my_free_datas(list->next);
    free(list);
}

void free_commands_lines(commands_lines_t *commands_lines)
{
    if (commands_lines->next != NULL)
        free_commands_lines(commands_lines->next);
    free(commands_lines);
}
