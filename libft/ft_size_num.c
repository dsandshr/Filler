/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 09:52:40 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/12 16:29:01 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_size_num(int a)
{
	size_t len;

	len = 0;
	if (a == 0)
		len = 1;
	while (a)
	{
		++len;
		a /= 10;
	}
	return (len);
}
