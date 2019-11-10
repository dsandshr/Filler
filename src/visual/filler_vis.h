/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_vis.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 19:25:58 by tlorine           #+#    #+#             */
/*   Updated: 2019/11/10 13:39:36 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_VIS_H
# define FILLER_VIS_H

# include "stdlib.h"
# include "SDL.h"
# include "../../libft/include/libft.h"

# define WIDTH 1720
# define HEIGHT 1280
# define FREE_ELEM(x) free(x), x = NULL, 0

typedef struct			s_step_list
{
	char				**map;
	int					height;
	struct s_step_list	*next;
	struct s_step_list	*back;
}						t_step_list;

typedef struct			s_vis_info
{
	void				*window;
	void				*render;
}						t_vis_info;

typedef struct			s_commands
{
	short				run;
	short				next;
	short				pause;
	int					speed;
	t_step_list			*new;
}						t_commands;

typedef struct			s_col_pl
{
	SDL_Color			player1;
	SDL_Color			player2;
}						t_col_pl;

void					free_list(t_step_list **list, int height);
t_step_list				*create_list_step(t_vis_info *info, t_col_pl *col);
void					write_game(t_step_list *list);
void					write_game_back(t_step_list *list);
void					draw_map\
						(t_vis_info *info, t_step_list *step, t_col_pl *col);
void					draw_load\
						(t_vis_info *info, int i);
void					quit_visual(t_vis_info *info, t_step_list *step);
void					draw_rect\
						(t_vis_info *info, SDL_Color color1, SDL_Color color2);
t_commands				*init_commands(t_step_list *step);
void					init_crlist\
						(int *height, char **line, t_step_list **list, int *i);
void					color_selection(t_col_pl *col, t_vis_info *info);
void					list_creator\
						(char **line, int *height, \
						t_step_list **list, t_vis_info *info);
int						add_step(t_step_list **list, int height);

#endif
