/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 18:18:49 by dsandshr          #+#    #+#             */
/*   Updated: 2019/10/20 16:37:11 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER
# define FILLER

# include "libft.h"

# define BOT_O -33
# define BOT_X -77

typedef struct	s_play
{
	int		val;
	int		x;
	int		y;
}				t_play;

typedef struct	s_figure
{
	int		*coords;
	int		width;
	int		height;
	int		size;
}				t_figure;

typedef struct	s_bot_inf
{
	int		**map;
	int		width;
	int		height;
	int		player;
	int		enemy;
	int		enemy_size;
	int		enemy_blocked;
	t_play	*move;
}				t_bot_inf;

int				main(void);
t_bot_inf		get_info (char *line);
int				fuck_this_bitch(t_bot_inf *bot);

#endif