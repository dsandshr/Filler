/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 16:21:23 by smorty            #+#    #+#             */
/*   Updated: 2019/10/23 17:25:38 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	cleanup(t_filler *bot)
{
	int i;

	i = bot->height;
	while (i--)
		free(bot->board[i]);
	free(bot->board);
	free(bot->move);
	free(bot);
}

int			main(void)
{
	t_filler		*bot;
	char			*buf;
	int				done;

	bot = NULL;
	done = 0;
	while (!done)
		if ((buf = read_input()))
		{
			if (!bot)
				bot = init_bot(buf);
			free(buf);
			done = fuck_actions(bot);
		}
	cleanup(bot);
	return (0);
}
