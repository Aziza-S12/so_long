/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadritd <asadritd@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 03:13:51 by asadritd          #+#    #+#             */
/*   Updated: 2023/01/16 03:21:47 by asadritd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void    reachables_counting_in_map(t_game *game, int x, int y)
{
    if (game->map_cpy[x][y] == '1')
        return ;
    if (game->map_cpy[x][y] == 'C')
        game->reachble_elements_counter++;
    if (game->map_cpy[x][y] == 'E')
        game->reachble_elements_counter++;
    game->map_cpy[x][y] = '1';
    reachables_counting_in_map(game, x, y + 1);
    reachables_counting_in_map(game, x, y - 1);
    reachables_counting_in_map(game, x + 1, y);
    reachables_counting_in_map(game, x - 1, y);
}

int valid_path(t_game *game)
{
    int x;
    int y;

    x = game->player_x;
    y = game->player_y;
    reachables_counting_in_map(game, x, y);
    if (game->elements_counter != game->reachble_elements_counter)
    {
        ft_printf("Error: No valid path\n");
        return (1);
    }
    return (0);
}