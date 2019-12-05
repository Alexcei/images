/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpole <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:49:54 by bpole             #+#    #+#             */
/*   Updated: 2019/09/11 22:16:44 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*res;

	i = 0;
	if (s1 && s2)
	{
		res = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		if (res)
		{
			while (*s1)
				res[i++] = *s1++;
			while (*s2)
				res[i++] = *s2++;
			return (res);
		}
	}
	return (NULL);
}
