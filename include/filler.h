/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 18:18:49 by dsandshr          #+#    #+#             */
/*   Updated: 2019/10/13 19:34:38 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER
# define FILLER

# include "libft.h"

typedef struct			s_game_info
{
	char				**map;
	char				*me;
	char				*enemy;
	char				figure;
	int					player_number;
	int					*my_poz;
	int					*enemy_poz;
	struct s_game_info	*next;
}						t_game_info;

typedef	struct			s_figure
{
	char				figure;
}						t_figure;

t_game_info	game_info_init(t_game_info *game_info);


#endif