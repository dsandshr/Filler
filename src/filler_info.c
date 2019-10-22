/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:45:08 by dsandshr          #+#    #+#             */
/*   Updated: 2019/10/22 15:40:10 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	**full_map_info(int x, int y)
{
	int		**map;

	if (!(map = (int **)malloc(sizeof(int *) * y)))
		exit (-1);
	while (y--)
	{
		if (!(map[y] = (int *)malloc(sizeof(int) * x)))
			exit (-1);
		ft_bzero(map[y], sizeof(int) * x);
	}
	return (map);
}

static void	init_map(t_bot_inf *bot)
{
	char *line;
	char *pointer;

	get_next_line(0, &line);
	pointer = line;
	while (*pointer != ' ')
		pointer++;
	bot->height = ft_atoi(++pointer);
	while (*pointer != ' ')
		pointer++;
	bot->width = ft_atoi(++pointer);
	ft_strdel(&line);
	bot->map = full_map_info(bot->width, bot->height);
}

static void	init_player(t_bot_inf *bot, char *line)
{
	while (*line != 'p')
		line++;
	if (*++line == '1')
	{
		bot->player = BOT_O;
		bot->enemy = BOT_X;
	}
	else
	{
		bot->player = BOT_X;
		bot->enemy = BOT_O;
	}
}

t_bot_inf	*get_info(char *line)
{
	t_bot_inf *bot;

	if (!(bot = (t_bot_inf *)malloc(sizeof(t_bot_inf))))
		exit (-1);
	init_player(bot, line);
	init_map(bot);
	if (!(bot->move = (t_play *)malloc(sizeof(t_bot_inf))))
		exit (-1);
	bot->move->val = 0;
	bot->move->x = 0;
	bot->move->y = 0;
	bot->enemy_block = 0;
	bot->enemy_size = 0;
	return (bot);
}