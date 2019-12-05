/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpole <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 11:59:34 by bpole             #+#    #+#             */
/*   Updated: 2019/09/13 16:45:16 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	size_t	len;
	int		sing;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sing = (n < 0 ? 1 : 0);
	n = FT_ABS(n);
	len = ft_intlen(n) + sing;
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (sing)
		str[0] = '-';
	return (str);
}
