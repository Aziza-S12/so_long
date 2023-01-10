/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_display_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadritd <asadritd@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:57:05 by asadritd          #+#    #+#             */
/*   Updated: 2023/01/10 13:27:47 by asadritd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	*display_tile(t_game *game, int j, int i)
{
	char	*tile_path;

	tile_path = 0;
	if (game->map[j][i] == '1')
		tile_path = "./images/blue_space.xpm/";
}

void	display_map(t_game *game)
{
	int		i;
	int		j;
	int		x;
	int		y;
	char	*tile_path;

	j = 0;
	y = 0;
	while (j < game->map_rows_count)
	{
		i = 0;
		x = 0;
		while ((game->map[j][i] != '\n') && (game->map[j][i] != '\0'))
		{
			tile_path = display_tile(game, j, i);
			game->image = mlx_xpm_file_to_image(game->mlx, tile_path, &game->tile_dimension, \
			&game->tile_dimension);
			mlx_put_image_to_window(game->mlx, game->window, game->image, x, y);
			x = x + game->tile_dimension;
			i++;
		}
		j++;
		y = y + game->tile_dimension;
	}
}