/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_visual.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 15:16:13 by dsandshr          #+#    #+#             */
/*   Updated: 2019/10/27 18:46:43 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_VISUAL_H
# define FILLER_VISUAL_H

# include "SDL.h"
# include "filler.h"

# define SCR_W 1280
# define SCR_H 1024

typedef struct	s_game
{
	char			**map;
	char			*player1;
	char			*player2;
	int				map_y;
	int				map_x;
	int				plateu;
	struct s_game	*prev;
	struct s_game	*next;
}				t_game;



#endif