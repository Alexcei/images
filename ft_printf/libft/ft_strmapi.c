/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpole <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:58:50 by bpole             #+#    #+#             */
/*   Updated: 2019/09/11 20:17:50 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	i = -1;
	res = NULL;
	if (s && f)
	{
		res = ft_strnew(ft_strlen(s));
		if (res)
		{
			while (s[++i])
				res[i] = f(i, s[i]);
			res[i] = '\0';
		}
	}
	return (res);
}
