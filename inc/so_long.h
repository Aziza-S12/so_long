/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadritd <asadritd@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:59:58 by asadritd          #+#    #+#             */
/*   Updated: 2023/01/09 17:25:03 by asadritd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

typedef	struct the_game 
{
	void	*mlx;
	void	*window;
	void	*floor;
	void	**wall;
	void	*image;
	char	**map;
	char	**map_cpy;
	int		moves_counter;
	int		colletbls_counter;
	int		elems_counter;
	int		reachble_counter;
	int		players_counter;
	int		exits_counter;
	int		map_columns_count;
	int		map_rows_count;
	int		tile_dimension;
	int		player_x;
	int		player_y;
}				t_game;


#endif