/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadritd <asadritd@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 02:24:31 by asadritd          #+#    #+#             */
/*   Updated: 2023/01/16 02:51:28 by asadritd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int valid_extension_check(char *path)
{
    int len;

    len = ft_strlen(path);
    if (ft_strnstr(path + len - 4, ".ber", 4) == 0)
    {
        ft_printf("Wrong file extension\n");
        exit (0);
        return (1);
    }
    return (0);
}

int valid_characters_check(t_game *game)
{
    int i;
    int j;

    j = 0;
    while (j < game->map_rows_count)
    {
        i = 0;
        while (i < game->map_columns_count)
        {
            if (!ft_strchr("01PCE", game->map[j][i]))
            {
                ft_printf("Wrong characters found\n")
                exit (0);
                return (1);
            }
            i++;
        }
        j++;
    }
    return (0);
}

void    initialise_num_of_elements(t_game *game)
{
    game->players_counter = 0;
    game->colletbls_counter = 0;
    game->exits_counter = 0;
    game->elements_counter = 0;
    game->reachble_elements_counter = 0;
    game->moves_counter = 0;
}

void    counting_elements(t_game *game)
{
    int i;
    int j;

    j = 0;
    while (j < game->map_rows_count)
    {
        i = 0;
        while (i < game->map_columns_count)
        {
            if (game->map[j][i] == 'P')
            {
                game->player_x = j;
                game->player_y = i;
                game->players_counter++;
            }
            else if (game->map[j][i] == 'C')
                game->colletbls_counter++;
            else if (game->map[j][i] == 'E')
                game->exits_counter++;
            i++;
        }
        j++;
    }
    game->elements_counter = game->colletbls_counter + game->exits_counter;
}

int valid_num_of_elements(t_game *game)
{
    initialise_num_of_elements(game);
    counting_elements(game);
    if (game->players_counter != 1 || game->colletbls_counter < 1 || \
    game->exits_counter != 1)
    {
        if (game->players_counter != 1)
            ft_printf("Wrong number of players - more than 1!\n")
        if (game->colletbls_counter < 1)
            ft_printf("No collectibles found!\n")
        if (game->exits_counter != 1)
            ft_printf("Wrong number of exits - more than 1!\n")
        return (1);
    }
    return (0);
}
