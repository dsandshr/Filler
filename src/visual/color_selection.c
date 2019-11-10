/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_selection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 18:17:32 by tlorine           #+#    #+#             */
/*   Updated: 2019/11/08 17:35:25 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_vis.h"

void	color_coords(SDL_Event event, t_col_pl *col)
{
	if ((event.motion.x >= 255 && event.motion.x <= 510) \
	&& (event.motion.y >= 305 && event.motion.y <= 305 + 10))
		col->player1.r = 255 - event.motion.x;
	if ((event.motion.x >= 255 && event.motion.x <= 510) \
	&& (event.motion.y >= 315 && event.motion.y <= 315 + 10))
		col->player1.g = 255 - event.motion.x;
	if ((event.motion.x >= 255 && event.motion.x <= 510) \
	&& (event.motion.y >= 325 && event.motion.y <= 325 + 10))
		col->player1.b = 255 - event.motion.x;
	if ((event.motion.x >= 1210 && event.motion.x <= 1465) \
	&& (event.motion.y >= 305 && event.motion.y <= 305 + 10))
		col->player2.r = 1210 - event.motion.x;
	if ((event.motion.x >= 1210 && event.motion.x <= 1465) \
	&& (event.motion.y >= 315 && event.motion.y <= 315 + 10))
		col->player2.g = 1210 - event.motion.x;
	if ((event.motion.x >= 1210 && event.motion.x <= 1465) \
	&& (event.motion.y >= 325 && event.motion.y <= 325 + 10))
		col->player2.b = 1210 - event.motion.x;
}

void	color_selection(t_col_pl *col, t_vis_info *info)
{
	SDL_Event event;

	while (1)
	{
		if (SDL_PollEvent(&event))
		{
			if (event.key.keysym.sym == SDLK_SPACE)
				break ;
			else if (event.button.button == SDL_BUTTON_LEFT)
				color_coords(event, col);
		}
		draw_load(info, 1620);
		draw_rect(info, col->player1, col->player2);
		SDL_RenderPresent(info->render);
	}
}
