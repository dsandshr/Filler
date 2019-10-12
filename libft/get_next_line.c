/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 16:31:21 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/12 16:22:57 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list		*ft_find_fd_to_lst(t_list *beg, int fd)
{
	if (beg)
		while (beg)
		{
			if ((*(int *)beg->content) == fd)
				return (beg);
			beg = beg->next;
		}
	return (NULL);
}

static int			ft_line_fill(char **line, t_list *elem)
{
	void			*tmp;
	char			*back_n;
	size_t			len;

	back_n = ft_memchr(elem->content + 4, '\n', elem->content_size - 4);
	(*line) = ft_strsub(elem->content + 4, 0,
	ft_strnlen(elem->content + 4, '\n'));
	if (!(*line))
		return (-1);
	len = ft_memnlen(elem->content + 4, '\n', elem->content_size - 4) + 1;
	tmp = elem->content;
	if (len == elem->content_size - 4)
	{
		elem->content = ft_memsub(tmp, 0, 4);
		elem->content_size = 4;
	}
	else
	{
		elem->content_size = (elem->content_size - len);
		elem->content = ft_memnjoin(tmp, back_n + 1, 4, elem->content_size - 4);
	}
	ft_memdel(&tmp);
	return (elem->content ? 1 : -1);
}

static ssize_t		ft_read_write(t_list *elem)
{
	ssize_t			t_byte_read;
	char			*buf;
	void			*tmp;

	tmp = NULL;
	buf = ft_memalloc(BUFF_SIZE);
	if (buf)
	{
		t_byte_read = read(*(int *)elem->content, buf, BUFF_SIZE);
		if (!t_byte_read || t_byte_read == -1)
		{
			ft_strdel(&buf);
			return (t_byte_read ? -1 : 0);
		}
		tmp = elem->content;
		elem->content = ft_memnjoin(tmp, buf, elem->content_size, t_byte_read);
		elem->content_size += t_byte_read;
		ft_memdel(&tmp);
		ft_strdel(&buf);
		return (elem->content ? t_byte_read : -1);
	}
	return (-1);
}

static int			ft_build_line(t_list *elem, char **line)
{
	char			*back_n;
	ssize_t			t_byte_read;

	t_byte_read = -2;
	while (1)
	{
		if ((back_n = ft_memchr(elem->content + 4, '\n',
		elem->content_size - 4)))
			return (ft_line_fill(line, elem));
		else if (!t_byte_read)
		{
			if (elem->content_size <= 4)
				return (0);
			(*line) = ft_strsub(elem->content + 4, 0, elem->content_size - 4);
			ft_lstreplace(&elem, (int *)elem->content, 4);
			return ((!(*line) || !elem->content) ? -1 : 1);
		}
		else
		{
			t_byte_read = ft_read_write(elem);
			if (t_byte_read == -1)
				return (-1);
		}
	}
}

int					get_next_line(const int fd, char **line, char signal)
{
	static t_list	*beg;
	t_list			*tmp;

	if (signal)
	{
		ft_lstdel(&beg, ft_lstfreeone);
		return (0);
	}
	if (fd >= 0 && fd < FD_MAX && BUFF_SIZE > 0 && line)
	{
		if (!(tmp = ft_find_fd_to_lst(beg, fd)))
		{
			tmp = ft_lstnew(&fd, 4);
			if (!tmp)
				return (-1);
			ft_lstadd_end(&beg, tmp);
		}
		return (ft_build_line(tmp, line));
	}
	return (-1);
}
