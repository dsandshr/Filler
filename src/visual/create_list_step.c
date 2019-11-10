/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list_step.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 19:47:08 by tlorine           #+#    #+#             */
/*   Updated: 2019/11/10 13:23:09 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_vis.h"

char		**free_map(char **map, int height)
{
	while (height != -1)
	{
		ft_strdel(&map[height]);
		height--;
	}
	free(map);
	map = NULL;
	return (map);
}

void		free_list(t_step_list **list, int height)
{
	t_step_list	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		(*list)->map = free_map((*list)->map, height);
		FREE_ELEM(*list);
		*list = tmp;
	}
}

char		**create_map(int height)
{
	char	*line;
	char	**map;
	int		i;

	i = 0;
	map = (char **)malloc(sizeof(char *) * (height + 1));
	if (get_next_line(0, &line) != 1)
		return (free_map(map, i - 1));
	else
		ft_strdel(&line);
	while (i < height)
	{
		if (get_next_line(0, &line) != 1)
		{
			free_map(map, i - 1);
			return (NULL);
		}
		map[i] = ft_strdup(line + 4);
		ft_strdel(&line);
		i++;
	}
	map[i] = NULL;
	return (map);
}

int			add_step(t_step_list **list, int height)
{
	t_step_list	*new_elem;
	t_step_list	*tmp;

	tmp = *list;
	new_elem = (t_step_list *)malloc(sizeof(t_step_list));
	if (*list == NULL)
	{
		if (!(new_elem->map = create_map(height)))
			return (FREE_ELEM(new_elem));
		new_elem->next = NULL;
		new_elem->back = NULL;
		new_elem->height = height;
		*list = new_elem;
		return (1);
	}
	while (tmp->next)
		tmp = tmp->next;
	if (!(new_elem->map = create_map(height)))
		return (FREE_ELEM(new_elem));
	new_elem->height = height;
	new_elem->back = tmp;
	new_elem->next = NULL;
	tmp->next = new_elem;
	return (1);
}

t_step_list	*create_list_step(t_vis_info *info, t_col_pl *col)
{
	char		*line;
	t_step_list	*list;
	SDL_Event	event;
	int			height;
	int			i;

	init_crlist(&height, &line, &list, &i);
	while (1)
	{
		if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
			quit_visual(info, list);
		if (get_next_line(0, &line) != 1)
			quit_visual(info, list);
		else if (line != NULL && ft_strstr(line, "fin:"))
			break ;
		else if (line != NULL)
			list_creator(&line, &height, &list, info);
		draw_load(info, i);
		SDL_RenderPresent(info->render);
		i = i > 1720 ? 0 : i + 1;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	color_selection(col, info);
	return (list);
}
