/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 19:05:19 by dsandshr          #+#    #+#             */
/*   Updated: 2019/10/22 17:58:22 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void			cleanup(t_bot_inf *bot)
{
	int				i;

	i = bot->height;
	while (i--)
		free(bot->map[i]);
	free(bot->map);
	free(bot->move);
	free(bot);
}

int					main(void)
{
	t_bot_inf		*bot;
	char			*line;
	int				done;
	int				fd;
	int x;
	int y;

	fd = open("log.log", O_RDWR);
	bot = NULL;
	done = 0;
	x = y = 0;
	while (!done)
	{
		if (get_next_line(0, &line) == 1)
		{
			if (!bot)
				bot = get_info(line);
			ft_strdel(&line);
			done = fuck_this_bitch(bot);
			while (y < bot->height)
			{
				x = 0;
				while (x < bot->width)
				{
					ft_putnbr_fd(bot->map[y][x], fd);
					ft_putstr_fd(" ", fd);
					x++;
				}
				ft_putstr_fd("\n", fd);
				y++;
			}
		}
	}
	cleanup(bot);
	return (0);
}