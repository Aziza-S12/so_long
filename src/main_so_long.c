/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_so_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadritd <asadritd@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:30:12 by asadritd          #+#    #+#             */
/*   Updated: 2023/01/16 03:28:18 by asadritd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	initial_the_game(t_game *game)
{
	game->mlx = mlx_init();
	game->tile_dimension = 64;
	game->window = mlx_new_window(game->mlx, 500, 500, "so_long");
	//mlx_loop(game->mlx);
}

int	closing_window(t_game *game)
{
	mlx_destroy_image(game->mlx, game->image);
	mlx_destroy_window(game->mlx, game->window);
	ft_printf("Game exited");
	exit(0);
	return (0);
}

int main(void)
{
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	mlx_loop(mlx_ptr);
}

// int main(int argc, char **argv)
// {
// 	t_game	game;

// 	if (argc != 2)
// 	{
// 		ft_printf("Error: Number of arguments should be 1\n");
// 		return (0);
// 	}
// 	initial_the_game(&game);
// 	argv = 0;
// 	return (0);
	

// }