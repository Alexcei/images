/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpole <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 12:25:41 by bpole             #+#    #+#             */
/*   Updated: 2019/10/27 12:27:17 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		get_figure(t_box *box, t_tab *tab)
{
	if (tab->modifier_l == 1)
		tab->n = (unsigned long int)va_arg(box->av, unsigned long int);
	else if (tab->modifier_l > 1)
		tab->n = (unsigned long long int)va_arg(box->av, unsigned long long);
	else if (tab->modifier_h == 1)
		tab->n = (unsigned short)va_arg(box->av, unsigned int);
	else if (tab->modifier_h > 1)
		tab->n = (unsigned char)va_arg(box->av, unsigned int);
	else
		tab->n = (unsigned int)va_arg(box->av, unsigned int);
	tab->len = ft_figure_len(tab->n, 10);
	if (tab->n == 0 && tab->dot_prec)
	{
		tab->precision++;
		tab->width++;
	}
}

static void		put_secondary(t_box *box, t_tab *tab)
{
	if (tab->flag_null && !tab->dot_prec)
	{
		while (tab->width-- > 0)
			ft_putchar_count(box, '0');
	}
	else
	{
		if (!tab->flag_min)
		{
			while (tab->width-- > 0)
				ft_putchar_count(box, ' ');
		}
	}
	while (tab->precision-- > 0)
		ft_putchar_count(box, '0');
}

void			output_u(t_box *box, t_tab *tab)
{
	get_figure(box, tab);
	if (tab->precision > tab->len)
	{
		tab->width -= tab->precision;
		tab->precision -= tab->len;
	}
	else
	{
		tab->width -= tab->len;
		tab->precision -= tab->len;
	}
	put_secondary(box, tab);
	if (tab->n || !tab->dot_prec)
		ft_figure_put(box, tab->n, 10, 97);
	if (tab->flag_min)
	{
		while (tab->width-- > 0)
			ft_putchar_count(box, ' ');
	}
}
