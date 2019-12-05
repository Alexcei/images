/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpole <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:36:28 by bpole             #+#    #+#             */
/*   Updated: 2019/09/10 17:41:57 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	size_t	len;

	ch = (char)c;
	len = ft_strlen(s);
	while (s[len] != ch && len)
		len--;
	if (s[len] == ch)
		return ((char*)s + len);
	return (NULL);
}
