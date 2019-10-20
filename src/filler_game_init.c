/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_game_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:20:13 by dsandshr          #+#    #+#             */
/*   Updated: 2019/10/19 17:41:20 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static t_game_info *full_player_info(t_game_info *g_inf)
{
	game_info->my_poz = malloc(sizeof(int *) * );
	if (ft_strstr(g_inf->map[g_inf->map_poz_y], "O") ||\
		ft_strstr(g_inf->map[g_inf->map_poz_y], "X"))
	{
		if (g_inf->player_number == 1)
		{
			while (g_inf->map[g_inf->map_poz_y][g_inf->map_poz_x] != "O")
				g_inf->map_poz_x++;
			g_inf->my_poz[0] = 
		}
	}
}

static t_game_info *map_info(t_game_info *game_info, int fdd)
{
	char *line;
	int fd;
	int i;

	fd = open("log.log", O_RDWR);
	game_info->map_poz_x = 0;
	game_info->map_poz_y = 0;
	get_next_line(fdd, &line);
	i = ft_atoi(line + 8);
	game_info->map = malloc(sizeof(char *) * i);
	ft_strdel(&line);
	get_next_line(fdd, &line);
	ft_strdel(&line);
	while (game_info->map_poz_y < i)
	{
		get_next_line(fdd, &line);
		game_info->map[game_info->map_poz_y] = ft_strdup(line + 4);
		full_player_info(game_info);
		ft_strdel(&line);
		ft_putstr_fd(game_info->map[game_info->map_poz_y], fd);
		ft_putstr_fd("\n", fd);
		game_info->map_poz_y++;
	}
	close(fd);
	return(game_info);
}

static	t_game_info	*player_info(t_game_info *game_info, char *line)
{
	game_info = (t_game_info *)malloc(sizeof(t_game_info) * 1);
	if (ft_strstr("$$$ exec p1", line))
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

t_game_info	*game_info_init(t_game_info *game_info, char *line, int fdd)
{
	game_info = player_info(game_info, line);
	game_info = map_info(game_info, fdd);
	return (game_info);
}