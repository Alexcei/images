/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpole <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 18:45:57 by bpole             #+#    #+#             */
/*   Updated: 2019/09/11 19:53:44 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*res;
	size_t	i;

	i = 0;
	res = NULL;
	if (f && s)
	{
		res = ft_strnew(ft_strlen(s));
		if (res)
		{
			while (*s)
				res[i++] = f(*s++);
			res[i] = '\0';
		}
	}
	return (res);
}
