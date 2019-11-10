/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list_step2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 19:17:50 by tlorine           #+#    #+#             */
/*   Updated: 2019/11/10 13:22:30 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_vis.h"

void	list_creator(char **line, int *h, t_step_list **list, t_vis_info *info)
{
	if (ft_strstr(*line, "Plateau"))
	{
		*h = *h == 0 ? ft_atoi(*line + 8) : *h;
		ft_strdel(line);
		if (add_step(list, *h) != 1)
		{
			ft_strdel(line);
			quit_visual(info, *list);
		}
	}
}
