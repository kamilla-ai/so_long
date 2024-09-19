/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:38:47 by kamillarazi       #+#    #+#             */
/*   Updated: 2024/07/03 19:53:04 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	getwidth(char *line)
{
	int	width;

	width = 0;
	while (line[width] != '\0')
		width++;
	return (width);
}

static int	putline(t_game *game, char *line)
{
	char	**map;
	int		i;

	i = 0;
	if (line == NULL || line[0] == '\n')
		return (0);
	game->height++;
	map = (char **)malloc(sizeof(char *) * (game->height));
	if (map == NULL)
		return (0);
	while (i < game->height - 1)
	{
		map[i] = game->map[i];
		i++;
	}
	map[i] = line;
	if (game->map)
		free(game->map);
	game->map = map;
	return (1);
}

void	readthemap(t_game *game, char *mapname)
{
	game->fd = open(mapname, O_RDONLY);
	if (game->fd == -1)
	{
		write(1, "Error! No map file.", 20);
		exit_point(game);
	}
	while (1)
	{
		if (!putline(game, get_next_line(game->fd)))
			break ;
	}
	if (game->height == 0)
	{
		write(1, "Error! Map is empty.", 21);
		exit_point(game);
	}
	game->width = getwidth(game->map[0]) - 1;
	if (game->height == game->width)
	{
		write(1, "Error! Squared map is not allowed.", 35);
		exit_point(game);
	}
	close(game->fd);
}
