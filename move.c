/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:38:53 by kamillarazi       #+#    #+#             */
/*   Updated: 2024/07/01 11:54:21 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	hook_up(t_game *game)
{
	if (game->map[game->player_y - 1][game->player_x] == '0')
	{
		game->map[game->player_y][game->player_x] = '0';
		game->player_y = game->player_y - 1;
		game->map[game->player_y][game->player_x] = 'P';
		game->currentsteps++;
	}
	else if (game->map[game->player_y - 1][game->player_x] == 'C')
	{
		game->currentpoint++;
		game->map[game->player_y][game->player_x] = '0';
		game->player_y = game->player_y - 1;
		game->map[game->player_y][game->player_x] = 'P';
		game->currentsteps++;
	}
	else if (game->map[game->player_y - 1][game->player_x] == 'E')
	{
		if (game->currentpoint == game->collectibles)
			exit_point(game);
	}
}

static void	hook_down(t_game *game)
{
	if (game->map[game->player_y + 1][game->player_x] == '0')
	{
		game->map[game->player_y][game->player_x] = '0';
		game->player_y = game->player_y + 1;
		game->map[game->player_y][game->player_x] = 'P';
		game->currentsteps++;
	}
	else if (game->map[game->player_y + 1][game->player_x] == 'C')
	{
		game->currentpoint++;
		game->map[game->player_y][game->player_x] = '0';
		game->player_y = game->player_y + 1;
		game->map[game->player_y][game->player_x] = 'P';
		game->currentsteps++;
	}
	else if (game->map[game->player_y + 1][game->player_x] == 'E')
	{
		if (game->currentpoint == game->collectibles)
			exit_point(game);
	}
}

static void	hook_right(t_game *game)
{
	if (game->map[game->player_y][game->player_x + 1] == '0')
	{
		game->map[game->player_y][game->player_x] = '0';
		game->player_x = game->player_x + 1;
		game->map[game->player_y][game->player_x] = 'P';
		game->currentsteps++;
	}
	else if (game->map[game->player_y][game->player_x + 1] == 'C')
	{
		game->currentpoint++;
		game->map[game->player_y][game->player_x] = '0';
		game->player_x = game->player_x + 1;
		game->map[game->player_y][game->player_x] = 'P';
		game->currentsteps++;
	}
	else if (game->map[game->player_y][game->player_x + 1] == 'E')
	{
		if (game->currentpoint == game->collectibles)
			exit_point(game);
	}
}

static void	hook_left(t_game *game)
{
	if (game->map[game->player_y][game->player_x - 1] == '0')
	{
		game->map[game->player_y][game->player_x] = '0';
		game->player_x = game->player_x - 1;
		game->map[game->player_y][game->player_x] = 'P';
		game->currentsteps++;
	}
	else if (game->map[game->player_y][game->player_x - 1] == 'C')
	{
		game->currentpoint++;
		game->map[game->player_y][game->player_x] = '0';
		game->player_x = game->player_x - 1;
		game->map[game->player_y][game->player_x] = 'P';
		game->currentsteps++;
	}
	else if (game->map[game->player_y][game->player_x - 1] == 'E')
	{
		if (game->currentpoint == game->collectibles)
			exit_point(game);
	}
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 13 || keycode == 126)
		hook_up(game);
	if (keycode == 1 || keycode == 125)
		hook_down(game);
	if (keycode == 0 || keycode == 123)
		hook_left(game);
	if (keycode == 2 || keycode == 124)
		hook_right(game);
	if (keycode == 53)
		exit_point(game);
	write(1, "Current steps:", 15);
	ft_printf("%d \n", (game->currentsteps));
	parsing(game);
	return (1);
}
