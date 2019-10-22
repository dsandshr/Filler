/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 18:18:49 by dsandshr          #+#    #+#             */
/*   Updated: 2019/10/22 20:33:28 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER
# define FILLER

# include "libft.h"

# define BOT_O -55
# define BOT_X -45

typedef struct	s_play
{
	int		val;
	int		x;
	int		y;
}				t_play;

typedef struct	s_figure
{
	int			width;
	int			height;
	int			size;
	int			x;
	int			y;
	int			chr;
	t_figure	*next;
}				t_figure;

typedef struct	s_bot_inf
{
	int		**map;
	int		width;
	int		height;
	int		player;
	int		enemy;
	int		enemy_size;
	int		enemy_block;
	t_play	*move;
}				t_bot_inf;

t_bot_inf	*get_info(char *line);
int			main(void);
int			fuck_this_bitch(t_bot_inf *bot);

#endif