/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fuck_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:11:02 by dsandshr          #+#    #+#             */
/*   Updated: 2019/10/22 21:34:38 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static	void	*get_figure(t_figure *fg)
{
	t_figure	*nextFg;
	char		*line;
	int			y;
	int			x;

	nextFg = fg;
	nextFg->y = 0;
	y = 0;
	while (nextFg->y < fg->height)
	{
		get_next_line(0, &line);
		nextFg->x = 0;
		while (line[nextFg->x])
		{
			if (line[nextFg->x] == '*')
				nextFg->chr = 1;
			else if (line[nextFg->x] == '.')
				nextFg->chr = 0;
			nextFg->x++;
			if (line[nextFg->x + 1])
				
		}
		ft_strdel(&line);
		nextFg->y++;
	}
}

static t_figure *figure_reader(void)
{
	t_figure *fg;
	char *line;
	char *pointer;

	if (!(fg = (t_figure *)malloc(sizeof(t_figure))))
		exit (-1);
	// while (get_next_line(0, &line) == 1)
	// {
	// 	if (ft_strstr("Piece", line))
	// 		break;
	// 	ft_strdel(&line);
	// }
	get_next_line(0, &line);
	pointer = line;
	while (*pointer != ' ')
		pointer++;
	fg->height = ft_atoi(++pointer);
	while (*pointer != ' ')
		pointer++;
	fg->width = ft_atoi(++pointer);
	ft_strdel(&line);
	get_figure(fg);
	return (fg);
}

static void	map_reader(int **map, int y)
{
	char *line;
	char *pointer;
	int i;

	i = 0;
	while (y--)
	{
		get_next_line(0, &line);
		pointer = line;
		while (*pointer)
		{
			if (*pointer == 'o' || *pointer == 'O')
				map[i][pointer - line - 4] = BOT_O;
			else if (*pointer == 'x' || *pointer == 'X')
				map[i][pointer - line - 4] = BOT_X;
			pointer++;
		}
		i++;
		ft_strdel(&line);
	}
}

int fuck_this_bitch(t_bot_inf *bot)
{
	 t_figure *fg;

	bot->move->val = 1;
	map_reader(bot->map, bot->height);
	fg = figure_reader(fg);
	heat_maper()
	return (0);
}