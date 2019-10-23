/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 18:18:49 by dsandshr          #+#    #+#             */
/*   Updated: 2019/10/23 17:23:28 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"

# define O_PLAYER -33
# define X_PLAYER -77

typedef struct	s_play
{
	int		val;
	int		x;
	int		y;
}				t_play;

typedef struct	s_piece
{
	int		*coords;
	int		width;
	int		height;
	int		size;
}				t_piece;

typedef struct	s_filler
{
	int		**board;
	int		width;
	int		height;
	int		player;
	int		opponent;
	int		opp_size;
	int		opp_blocked;
	t_play	*move;
}				t_filler;

int			main(void);
t_filler	*init_bot(char *player_line);
int			fuck_actions(t_filler *bot);
void		heat_map(t_filler *bot);
void		find_move(t_filler *bot, const t_piece *token);
char		*read_input(void);

#endif