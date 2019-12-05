/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpole <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 22:47:47 by bpole             #+#    #+#             */
/*   Updated: 2019/09/12 11:51:04 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	start;
	size_t	finish;
	char	*res;

	if (!s)
		return (NULL);
	start = 0;
	finish = ft_strlen(s);
	while (ft_isblank(s[start]) || s[start] == '\n')
		start++;
	while (finish && (ft_isblank(s[finish - 1]) || s[finish - 1] == '\n'))
		finish--;
	if (start > finish)
		return (ft_strnew(0));
	res = ft_strnew(finish - start);
	if (!res)
		return (NULL);
	i = 0;
	while (start < finish)
		res[i++] = s[start++];
	return (res);
}
