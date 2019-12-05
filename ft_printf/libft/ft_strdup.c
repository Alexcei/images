/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpole <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 13:16:39 by bpole             #+#    #+#             */
/*   Updated: 2019/09/14 11:01:03 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*res;

	res = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!res)
		return (NULL);
	return (ft_strcpy(res, s1));
}
