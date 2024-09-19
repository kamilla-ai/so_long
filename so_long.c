/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:39:05 by kamillarazi       #+#    #+#             */
/*   Updated: 2024/07/04 19:56:07 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*initialize(void *b, size_t length)
{
	int				c;
	unsigned char	*p;

	c = 0;
	p = (unsigned char *)b;
	while (length--)
		*p++ = (unsigned char)c;
	return (b);
}

int	exit_point(t_game *game)
{
	int	line;

	line = 0;
	if (game->mlx_window)
	{
		mlx_destroy_window(game->mlx_connection, game->mlx_window);
	}
	free(game->mlx_connection);
	while (line < game->height)
		free(game->map[line++]);
	free(game->map);
	exit(0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac < 2)
	{
		return (0);
	}
	initialize(&game, sizeof(t_game));
	readthemap(&game, av[1]);
	checkmap(&game);
	game.mlx_connection = mlx_init();
	game.mlx_window = mlx_new_window(game.mlx_connection, game.width * 64,
			game.height * 64, "My game");
	parsing(&game);
	checkpath(&game);
	mlx_key_hook(game.mlx_window, key_hook, &game);
	mlx_hook(game.mlx_window, 17, 0, (void *)exit, 0);
	mlx_loop(game.mlx_connection);
}
