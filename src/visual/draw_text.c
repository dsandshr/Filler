/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 19:50:11 by tlorine           #+#    #+#             */
/*   Updated: 2019/11/08 17:35:34 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_vis.h"

void	draw_load(t_vis_info *info, int i)
{
	SDL_Rect rect;

	rect.h = 100;
	rect.w = i + 100;
	rect.x = 0;
	rect.y = 590;
	SDL_SetRenderDrawColor(info->render, 0, 85, 138, 1);
	SDL_RenderClear(info->render);
	SDL_SetRenderDrawColor(info->render, 255, 255, 255, 1);
	SDL_RenderFillRect(info->render, &rect);
}

void	draw_rgb_line(t_vis_info *info, SDL_Rect line, int rgb)
{
	int i;
	int r;
	int g;
	int b;

	i = 255;
	while (i != -1)
	{
		r = rgb == 1 ? i : 0;
		g = rgb == 2 ? i : 0;
		b = rgb == 3 ? i : 0;
		SDL_SetRenderDrawColor(info->render, r, g, b, 1);
		SDL_RenderFillRect(info->render, &line);
		line.x++;
		i--;
	}
}

void	draw_line_color(t_vis_info *info, int player)
{
	SDL_Rect line;

	line.h = 10;
	line.x = player == 1 ? 255 : 1210;
	line.y = 305;
	line.w = 1;
	draw_rgb_line(info, line, 1);
	line.y = line.y + 10;
	line.x = player == 1 ? 255 : 1210;
	draw_rgb_line(info, line, 2);
	line.y = line.y + 10;
	line.x = player == 1 ? 255 : 1210;
	draw_rgb_line(info, line, 3);
}

void	draw_rect(t_vis_info *info, SDL_Color color1, SDL_Color color2)
{
	SDL_Rect player1;
	SDL_Rect player2;

	player1.h = 255;
	player1.w = 255;
	player1.x = 255;
	player1.y = 50;
	player2.h = 255;
	player2.w = 255;
	player2.x = 1210;
	player2.y = 50;
	SDL_SetRenderDrawColor(info->render, color1.r, color1.g, color1.b, 1);
	SDL_RenderFillRect(info->render, &player1);
	SDL_SetRenderDrawColor(info->render, color2.r, color2.g, color2.b, 1);
	SDL_RenderFillRect(info->render, &player2);
	draw_line_color(info, 1);
	draw_line_color(info, 2);
}
