/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 17:45:05 by tlorine           #+#    #+#             */
/*   Updated: 2019/11/08 17:35:41 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_vis.h"

t_commands	*init_commands(t_step_list *step)
{
	t_commands *com;

	com = (t_commands *)malloc(sizeof(t_commands));
	com->speed = 50;
	com->run = 1;
	com->next = 1;
	com->pause = 0;
	com->new = step;
	return (com);
}

void		init_crlist(int *height, char **line, t_step_list **list, int *i)
{
	*i = 0;
	*height = 0;
	*line = NULL;
	*list = NULL;
}
