/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_game_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:20:13 by dsandshr          #+#    #+#             */
/*   Updated: 2019/10/16 20:03:07 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static t_game_info *map_info(t_game_info *game_info)
{
	char *line;
	int fd;
	//int i;

	fd = open("log.log", O_RDWR);
	game_info->map_poz_x = 0;
	game_info->map_poz_y = 0;
	get_next_line(0, &line);
	//i = ft_atoi(line + 8);
	game_info->map = malloc(sizeof(char *) * ft_atoi(line + 8));
	ft_strdel(&line);
	get_next_line(0, &line);
	ft_strdel(&line);
	while (get_next_line(0, &line) == 1)
	{
		game_info->map[game_info->map_poz_y] = ft_strdup(line + 4);
		ft_strdel(&line);
		ft_putstr_fd(game_info->map[game_info->map_poz_y], fd);
		ft_putstr_fd("\n", fd);
		game_info->map_poz_y++;
	}
	close(fd);
	return(game_info);
}

static	t_game_info	*player_info(t_game_info *game_info)
{
	char *line;

	game_info = (t_game_info *)malloc(sizeof(t_game_info) * 1);
	get_next_line(0, &line);
	if (ft_strcmp("p1", line) == 0)
	{
		game_info->me = "O";
		game_info->enemy = "X";
		game_info->player_number = 1;
	}
	else
	{
		game_info->me = "X";
		game_info->enemy = "O";
		game_info->player_number = 2;
	}
	ft_strdel(&line);
	return(game_info);
}

t_game_info	*game_info_init(t_game_info *game_info)
{
	game_info = player_info(game_info);
	game_info = map_info(game_info);
	return (game_info);
}