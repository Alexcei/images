/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpole <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 14:29:50 by bpole             #+#    #+#             */
/*   Updated: 2019/09/09 11:55:24 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *d, int c, size_t len)
{
	unsigned char	*buf;
	unsigned char	ch;

	buf = (unsigned char *)d;
	ch = (unsigned char)c;
	while (len-- > 0)
		*buf++ = ch;
	return (d);
}
