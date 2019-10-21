/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 16:32:08 by dsandshr          #+#    #+#             */
/*   Updated: 2019/10/20 18:26:23 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	*get_coords(t_figure *fg)
{
	char	*line;
	char	*pointer;
	int		*coords;
	int		y;

	if (!(coords = (int *)malloc(sizeof(int) * fg->height * fg->width)))
		exit(-1);
	y = 0;
	fg->size = 0;
	while (y < fg->height)
	{
		if (!(get_next_line(0, &line) == 1))
			exit(-1);
		pointer = line;
		while (*pointer)
		{
			if (*pointer == '*')
				coords[fg->size++] = 
		}
	}
}

static t_figure	*get_figure(void)
{
	t_figure	*fg;
	char		*line;
	char		*pointer;

	if (!(fg = (t_figure *)malloc(sizeof(t_figure))))
		exit (-1);
	if (!(get_next_line(0, &line) == 1))
		exit (-1);
	pointer = line;
	while (*pointer != ' ')
		pointer++
	fg->height = ft_atoi(++pointer);
	while (*pointer != ' ')
		pointer++;
	fg->width = ft_atoi(++pointer);
	ft_strdel(&line);
	fg->coords = get_coords(fg);
}

static void	map_read(int y, int **map)
{
	char *line;
	char *pointer;
	int poz_y;

	poz_y = 0;
	while (y--)
	{
		if (!(get_next_line(0, &line) == 1))
			exit (-1)
		pointer = line;
		while (*pointer)
		{
			if (*pointer == 'o' || *pointer == 'O')
				map[poz_y][pointer - line - 4] = BOT_O;
			if (*pointer == 'x' || *pointer == 'X')
				map[poz_y][pointer - line - 4] = BOT_X;
			++pointer;
		}
		++poz_y;
		ft_strdel(&line);
	}
}

int	fuck_this_bitch(t_bot_inf *bot)
{
	t_figure *fg;

	bot->move->val = 0xffff;
	map_read(bot->height, bot->map);
	fg = get_figure()
}