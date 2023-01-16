/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_display_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadritd <asadritd@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:57:05 by asadritd          #+#    #+#             */
/*   Updated: 2023/01/16 02:20:28 by asadritd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	mallocing_maps(t_game *game)
{
	game->map = malloc(sizeof(char *) * (game->map_rows_count + 1));
	if (!(game->map))
		exit(0);
	game->map_cpy = malloc(sizeof(char *) * (game->map_rows_count + 1));
	if (!(game->map_cpy))
		exit(0);
}

void	reading_map(t_game *game, char *map_file)
{
	int		fd;
	int		rows_num;
	char	*line;

	rows_num = 0;
	fd = open(map_file, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
	{
		ft_printf("No file to read");
		exit (0);
	}
	free (line);
	game->map_columns_count = ft_strlen(line) - 1;
	while (line != 0)
	{
		line = get_next_line(fd);
		rows_num++;
		free(line);
	}
	game->map_rows_count = rows_num;
	close(fd);
	mallocing_maps(game);
}

void	map_filling(t_game *game, char *map_file)
{
	int		fd;
	char	*line;
	char	*line2;
	int		row_index;

	row_index = 1;
	fd = open(map_file, O_RDONLY);
	line = get_next_line(fd);
	line2 = ft_strdup(line);
	game->map[0] = line;
	game->map_cpy[0] = line2;
	while (line != 0)
	{
		line = get_next_line(fd);
		if (line)
		{
			line2 = ft_strdup(line);
			game->map_cpy[row_index] = line2;
		}
		game->map[row_index] = line;
		row_index++;
	}
	close[fd];
}

char	*display_tile(t_game *game, int j, int i)
{
	char	*tile_path;

	tile_path = 0;
	if (game->map[j][i] == '0')
		tile_path = "./images/blue_space.xpm/";
	else if (game->map[j][i] == '1')
		tile_path = "";
	else if (game->map[j][i] == 'P')
		tile_path = "";
	else if (game->map[j][i] == 'C')
		tile_path = "";
	else if (game->map[j][i] == 'E')
		tile_path = "";
	return (tile_path);
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