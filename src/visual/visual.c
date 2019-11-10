/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:56:17 by tlorine           #+#    #+#             */
/*   Updated: 2019/11/08 17:35:47 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_vis.h"

t_vis_info	*init_sdl(void)
{
	t_vis_info	*info;

	if ((SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS)) < 0)
		exit(1);
	info = (t_vis_info *)malloc(sizeof(t_vis_info));
	info->window = SDL_CreateWindow("VisualFiller", \
	SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, \
	WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	if (info->window == NULL)
	{
		free(info);
		exit(1);
	}
	info->render = SDL_CreateRenderer(info->window, -1, \
	SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	return (info);
}

void		quit_visual(t_vis_info *info, t_step_list *step)
{
	free_list(&step, step->height);
	SDL_DestroyWindow(info->window);
	SDL_DestroyRenderer(info->render);
	SDL_Quit();
	exit(1);
}

void		hook_event(SDL_Event event, t_commands *com, t_step_list **step)
{
	if (event.type == SDL_QUIT)
		com->run = 0;
	else if (event.type == SDL_KEYDOWN)
	{
		if (event.key.keysym.sym == SDLK_UP && com->speed > 0)
			com->speed = com->speed - 50;
		else if (event.key.keysym.sym == SDLK_DOWN && com->speed < 350)
			com->speed = com->speed + 50;
		else if (event.key.keysym.sym == SDLK_RIGHT)
			com->next = 1;
		else if (event.key.keysym.sym == SDLK_LEFT)
			com->next = 0;
		else if (event.key.keysym.sym == SDLK_SPACE)
			com->pause = com->pause == 0 ? 1 : 0;
		else if (event.key.keysym.sym == SDLK_TAB)
			*step = com->new;
	}
}

int			loop(t_vis_info *info, t_step_list *step, t_col_pl *col)
{
	SDL_Event	event;
	t_commands	*com;

	com = init_commands(step);
	while (com->run)
	{
		if (SDL_PollEvent(&event))
			hook_event(event, com, &step);
		if (!com->pause)
		{
			SDL_SetRenderDrawColor(info->render, 0, 85, 138, 1);
			SDL_RenderClear(info->render);
			draw_map(info, step, col);
			SDL_RenderPresent(info->render);
			if (step->next != NULL && com->next)
				step = step->next;
			else if (step->back != NULL && com->next == 0)
				step = step->back;
			SDL_Delay(com->speed);
		}
	}
	return (0);
}

int			main(void)
{
	t_vis_info	*info;
	t_step_list	*step;
	t_col_pl	*col;

	col = (t_col_pl *)malloc(sizeof(t_col_pl));
	info = init_sdl();
	step = create_list_step(info, col);
	loop(info, step, col);
	free(col);
	col = NULL;
	quit_visual(info, step);
}
