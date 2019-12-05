/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpole <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 20:31:31 by bpole             #+#    #+#             */
/*   Updated: 2019/09/09 13:57:55 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	ch;

	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	ch = (unsigned char)c;
	while (n-- > 0)
	{
		*d++ = *s;
		if (ch == *s++)
			return (d);
	}
	return (NULL);
}
