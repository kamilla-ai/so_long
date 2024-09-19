/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:39:23 by kamillarazi       #+#    #+#             */
/*   Updated: 2024/07/04 15:27:22 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "gnl/get_next_line.h"
# include "minilibx/mlx.h"
# include <fcntl.h>
# include <unistd.h>

typedef struct s_game
{
	void	*mlx_connection;
	void	*mlx_window;
	int		fd;
	int		width;
	int		height;
	char	**map;
	int		currentpoint;
	int		currentsteps;
	int		maxsteps;
	int		collectibles;
	int		players;
	int		exits;
	void	*collectible;
	void	*exit;
	void	*girl;
	void	*road;
	void	*wall;
	int		player_x;
	int		player_y;
}			t_game;

void		readthemap(t_game *game, char *mapname);
void		checkmap(t_game *game);
void		checkpath(t_game *game);
void		parsing(t_game *game);
int			exit_point(t_game *game);
int			key_hook(int keycode, t_game *game);

#endif