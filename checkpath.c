/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkpath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 09:29:23 by kamillarazi       #+#    #+#             */
/*   Updated: 2024/07/04 15:36:02 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

static void	checkres(int res, t_game *game)
{
	if (res != 1)
	{
		write(1, "Error! No valid path.", 21);
		exit_point(game);
	}
}

static int	is_valid(int x, int y, t_game *game, int **temp)
{
	if (x >= 0 && x < game->width && y >= 0 && y < game->height
		&& game->map[y][x] != '1' && temp[y][x] != 1)
	{
		return (1);
	}
	return (0);
}

static int	dfs(int x, int y, t_game *game, int **temp)
{
	if (!is_valid(x, y, game, temp))
		return (0);
	if (game->map[y][x] == 'E')
	{
		if (game->collectibles != 0)
			return (0);
		return (1);
	}
	if (game->map[y][x] == 'C')
		game->collectibles--;
	temp[y][x] = 1;
	if (dfs(x + 1, y, game, temp))
		return (1);
	if (dfs(x - 1, y, game, temp))
		return (1);
	if (dfs(x, y + 1, game, temp))
		return (1);
	if (dfs(x, y - 1, game, temp))
		return (1);
	return (0);
}

void	checkpath(t_game *game)
{
	int	i;
	int	**temp;
	int	res;
	int	coll;

	coll = game->collectibles;
	temp = (int **)malloc(game->height * sizeof(int *));
	i = 0;
	while (i < game->height)
	{
		temp[i] = (int *)calloc(game->width, sizeof(int));
		i++;
	}
	res = dfs(game->player_x, game->player_y, game, temp);
	game->collectibles = coll;
	i = 0;
	while (i < game->height)
	{
		free(temp[i]);
		i++;
	}
	free(temp);
	checkres(res, game);
}
