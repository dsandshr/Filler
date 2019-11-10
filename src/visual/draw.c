/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 20:01:04 by tlorine           #+#    #+#             */
/*   Updated: 2019/11/08 17:35:37 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_vis.h"

void	draw_color(char c, t_vis_info *info, t_col_pl *col)
{
	if (c == '.')
		SDL_SetRenderDrawColor(info->render, 178, 235, 237, 1);
	else if (c == 'x')
		SDL_SetRenderDrawColor(info->render, 255, 255, 255, 1);
	else if (c == 'X')
		SDL_SetRenderDrawColor(info->render, col->player2.r, \
		col->player2.g, col->player2.b, 1);
	else if (c == 'O')
		SDL_SetRenderDrawColor(info->render, col->player1.r, \
		col->player1.g, col->player1.b, 1);
	else if (c == 'o')
		SDL_SetRenderDrawColor(info->render, 255, 255, 255, 1);
}

void	search_size(t_step_list *step, int *x, int *y)
{
	int	i;

	i = 0;
	while (step->map[0][i])
	{
		i++;
	}
	*x = 1000 / i;
	*y = 1000 / step->height;
}

void	draw_rp(SDL_Rect rect, t_vis_info *info, t_col_pl *col, char ch)
{
	if (ch != '.')
	{
		draw_color(ch, info, col);
		SDL_RenderFillRect(info->render, &rect);
		SDL_SetRenderDrawColor(info->render, 255, 255, 255, 1);
		SDL_RenderDrawRect(info->render, &rect);
	}
}

void	draw_map(t_vis_info *info, t_step_list *step, t_col_pl *col)
{
	int			size_x;
	int			size_y;
	int			x;
	int			y;
	SDL_Rect	rect;

	y = 0;
	x = 0;
	search_size(step, &size_x, &size_y);
	rect.h = size_y;
	rect.w = size_x;
	while (step->map[y] != NULL)
	{
		while (step->map[y][x] != '\0')
		{
			rect.x = 360 + (x * size_x);
			rect.y = 140 + (y * size_y);
			draw_rp(rect, info, col, step->map[y][x]);
			x++;
		}
		y++;
		x = 0;
	}
}
