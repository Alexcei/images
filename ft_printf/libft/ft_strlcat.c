/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpole <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 23:04:29 by bpole             #+#    #+#             */
/*   Updated: 2019/09/13 15:36:34 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dest;
	size_t	len_src;

	len_src = ft_strlen(src);
	len_dest = ft_strlen(dest);
	i = len_dest;
	if (len_dest >= size)
		return (len_src + size);
	while (*src && len_dest < size - 1)
		dest[len_dest++] = *src++;
	dest[len_dest] = '\0';
	return (len_src + i);
}
