/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 13:18:30 by dsandshr          #+#    #+#             */
/*   Updated: 2019/08/17 14:51:59 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(const char *s1, size_t n)
{
	char	*str;
	char	*s2;
	size_t	len;

	len = ft_strlen(s1);
	len = (len > n ? n : len);
	str = (char*)malloc(sizeof(char) * (len + 1));
	if ((s2 = str))
	{
		while (len--)
			*s2++ = *s1++;
		*s2 = '\0';
	}
	return (str);
}
