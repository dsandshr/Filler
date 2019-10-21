/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 19:05:19 by dsandshr          #+#    #+#             */
/*   Updated: 2019/10/20 16:31:24 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void			cleanup(t_bot_inf *bot)
{
	int				i;

	i = bot->height;
	while (i--)
		free(bot->board[i]);
	free(bot->board);
	free(bot->move);
	free(bot);
}

int					main(void)
{
	t_bot_inf		*bot;
	char			*line;
	int				done;

	bot = NULL;
	done = 0;
	while (!done)
		if (get_next_line(0, &line) == 1)
		{
			if (!bot)
				bot = get_info(line);
			ft_strdel(&line);
			done = fuck_this_bitch(bot);
		}
	cleanup(bot);
	return (0);
}