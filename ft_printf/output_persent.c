/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_persent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpole <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 12:25:08 by bpole             #+#    #+#             */
/*   Updated: 2019/10/27 12:25:35 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	output_persent(t_box *box, t_tab *tab)
{
	tab->len = 1;
	if (tab->width > 0)
		tab->width--;
	if (tab->flag_min)
	{
		ft_putchar_count(box, '%');
		while (tab->width--)
			ft_putchar_count(box, ' ');
	}
	else
	{
		while (tab->width--)
		{
			if (tab->flag_null)
				ft_putchar_count(box, '0');
			else
				ft_putchar_count(box, ' ');
		}
		ft_putchar_count(box, '%');
	}
}
