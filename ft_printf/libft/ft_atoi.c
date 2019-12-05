/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpole <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 14:09:12 by bpole             #+#    #+#             */
/*   Updated: 2019/09/13 16:44:25 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t		i;
	int			sing;
	long long	res;

	i = 0;
	res = 0;
	while (ft_isspace(str[i]))
		i++;
	sing = (str[i] == '-' ? -1 : 1);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
		res = res * 10 + str[i++] - '0';
	if (res > (res * 10))
	{
		if (sing == 1)
			return (-1);
		else
			return (0);
	}
	return (res * sing);
}
