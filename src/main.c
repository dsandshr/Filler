/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 19:05:19 by dsandshr          #+#    #+#             */
/*   Updated: 2019/10/19 17:02:50 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	main(void)
{
	t_game_info	*g_info;
	char *line;
	int i;
	int fd;

	fd = open("doc.log", O_RDWR);
	i = 0;
	g_info = NULL;
	g_info = game_info_init(g_info, line, fd);
	while (1)
	{
		while (get_next_line(fd, &line) == 1 && i != 1)
		{
			if (ft_strstr(line, "$$$"))
			{
				++i;
				break;
			}
			ft_strdel(&line);
		}
		exit (1);
	}
	exit (1);
}
