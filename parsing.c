/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:38:59 by kamillarazi       #+#    #+#             */
/*   Updated: 2024/07/03 19:54:37 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	putimages(t_game *game, int height, int width)
{
	if (game->map[height][width] == '1')
		mlx_put_image_to_window(game->mlx_connection, game->mlx_window,
			game->wall, width * 64, height * 64);
	if (game->map[height][width] == '0')
		mlx_put_image_to_window(game->mlx_connection, game->mlx_window,
			game->road, width * 64, height * 64);
	if (game->map[height][width] == 'P')
	{
		mlx_put_image_to_window(game->mlx_connection, game->mlx_window,
			game->girl, width * 64, height * 64);
		game->player_x = width;
		game->player_y = height;
	}
	if (game->map[height][width] == 'C')
		mlx_put_image_to_window(game->mlx_connection, game->mlx_window,
			game->collectible, width * 64, height * 64);
	if (game->map[height][width] == 'E')
		mlx_put_image_to_window(game->mlx_connection, game->mlx_window,
			game->exit, width * 64, height * 64);
}

static void	getimages(t_game *game)
{
	int	i;
	int	j;

	i = 64;
	j = 64;
	game->wall = mlx_xpm_file_to_image(game->mlx_connection, "img/wall.xpm", &i,
			&j);
	game->road = mlx_xpm_file_to_image(game->mlx_connection, "img/road.xpm", &i,
			&j);
	game->collectible = mlx_xpm_file_to_image(game->mlx_connection,
			"img/collectible.xpm", &i, &j);
	game->girl = mlx_xpm_file_to_image(game->mlx_connection, "img/kitty.xpm",
			&i, &j);
	game->exit = mlx_xpm_file_to_image(game->mlx_connection, "img/exit.xpm", &i,
			&j);
	if (game->wall == NULL || game->road == NULL || game->collectible == NULL)
	{
		write(1, "Error! No img file.", 20);
		exit_point(game);
	}
	if (game->girl == NULL || game->exit == NULL)
	{
		write(1, "Error! No img file.", 20);
		exit_point(game);
	}
}

void	parsing(t_game *game)
{
	int	height;
	int	width;

	height = 0;
	getimages(game);
	while (height < game->height)
	{
		width = 0;
		while (width < game->width)
		{
			putimages(game, height, width);
			width++;
		}
		height++;
	}
}
