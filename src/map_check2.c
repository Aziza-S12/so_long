/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadritd <asadritd@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 02:25:51 by asadritd          #+#    #+#             */
/*   Updated: 2023/01/16 03:09:35 by asadritd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int rectangular_map_check(t_game *game)
{
    int i;

    i = 1;
    while (i < game->map_rows_count)
    {
        if (ft_strlen(game->map[0]) != ft_strlen(game->map[i]))
        {
            ft_printf("Map is not rectangular\n");
            return (1);
        }
        i++;
    }
    return (0);
}

int upper_lower_wall_check(t_game *game)
{
    int i;

    i = 0;
    while (i < (game->map_columns_count - 1))
    {
        if (game->map[0][i] != '1')
        {
            ft_printf("Gap in the upper wall\n");
            exit (0);
            return (1);
        }
        i++;
    }
    i = 0;
    while (i < (map->map_columns_count - 1))
    {
        if (game->map[game->map_rows_count - 1][i] != '1')
        {
            ft_printf("Gap in the lower wall\n");
            exit (0);
            return (1);
        }
        i++;
    }
    return (0);
}

int side_walls_check(t_game *game)
{
    int i;

    i = 0;
    while (i < game->map_rows_count)
    {
        if (game->map[i][0] != '1' || \
        game->map[i][game->map_columns_count - 1] != '1')
        {
            ft_printf("Gap in the side wall\n");
            exit (0);
            return (1);
        }
        i++;
    }
    return (0);
}

int all_map_checks(t_game *game, char *path)
{
    int i;

    i = 0;
    i += valid_extension_check(path);
    i += valid_characters_check(game);
    i += valid_num_of_elements(game);
    i += rectangular_map_check(game);
    i += upper_lower_wall_check(game);
    i += side_walls_check(game);
    if (i == 0)
        return (0);
    return (1);
}
