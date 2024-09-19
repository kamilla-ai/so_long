/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:37:13 by kamillarazi       #+#    #+#             */
/*   Updated: 2024/07/04 14:53:32 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	checkwalls(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->width)
	{
		if (game->map[0][i] != '1' || game->map[game->height - 1][i] != '1')
		{
			write(1, "Error! Incomplete walls.", 25);
			exit_point(game);
		}
		i++;
	}
	i = 0;
	while (i < game->height)
	{
		if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
		{
			write(1, "Error! Incomplete walls.", 25);
			exit_point(game);
		}
		i++;
	}
}

static void	checkthechar(t_game *game, char c)
{
	if (c == 'C')
		game->collectibles++;
	else if (c == 'P')
	{
		game->players++;
		if (game->players != 1)
		{
			write(1, "Error! Many or no players.", 26);
			exit_point(game);
		}
	}
	else if (c == 'E')
	{
		game->exits++;
		if (game->exits != 1)
		{
			write(1, "Error! Many or no exits.", 24);
			exit_point(game);
		}
	}
	else if (c != '0' && c != '1')
	{
		write(1, "Error! Extra char in map.", 26);
		exit_point(game);
	}
}

static void	checkcomponents(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			checkthechar(game, game->map[i][j]);
			j++;
		}
		i++;
	}
}

void	checkmap(t_game *game)
{
	checkwalls(game);
	checkcomponents(game);
	if (game->collectibles < 1)
	{
		ft_printf("Error! No collectibles.");
		exit_point(game);
	}
	return ;
}
