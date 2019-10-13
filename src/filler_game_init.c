/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_game_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:20:13 by dsandshr          #+#    #+#             */
/*   Updated: 2019/10/13 19:56:41 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static	t_game_info	player_info(t_game_info *game_info)
{
	char *line;
	game_info = (t_game_info *)malloc(sizeof(t_game_info) * 1);
	while (get_next_line(0, &line) == 1)
	{
		if (ft_strcmp("$$$ exec p1 : [players/dsandshr.filler]", *line) == 0)
		{
			*game_info->me = "O";
			*game_info->enemy = "X";
			*game_info->player_number = 1;
		}
		else
		{
			*game_info->me = "X";
			*game_info->enemy = "O";
			*game_info->player_number = 2;
		}
		ft_strdel(line);
		line = NULL;
	}
}

t_game_info	game_info_init(t_game_info *game_info)
{
	*game_info = player_info(*game_info);
}