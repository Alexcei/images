/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_i_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpole <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 12:20:18 by bpole             #+#    #+#             */
/*   Updated: 2019/10/27 12:22:13 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			get_figure(t_box *box, t_tab *tab)
{
	long long int	n;

	if (tab->modifier_l == 1)
		n = (long)va_arg(box->av, long int);
	else if (tab->modifier_l > 1)
		n = (long long)va_arg(box->av, long long int);
	else if (tab->modifier_h == 1)
		n = (short)va_arg(box->av, int);
	else if (tab->modifier_h > 1)
		n = (signed char)va_arg(box->av, int);
	else
		n = (int)va_arg(box->av, int);
	if (n < 0 && ++tab->sign)
		tab->n = (unsigned long)n * -1;
	else
		tab->n = (unsigned long)n;
	tab->len = ft_figure_len(tab->n, 10);
	if (n == 0 && tab->dot_prec)
	{
		tab->precision++;
		tab->width++;
	}
}

void				put_sign(t_box *box, t_tab *tab)
{
	if (tab->flag_plus && !tab->sign)
		ft_putchar_count(box, '+');
	if (tab->sign)
		ft_putchar_count(box, '-');
	else if (tab->flag_space && !tab->flag_plus)
		ft_putchar_count(box, ' ');
}

static void			put_secondary(t_box *box, t_tab *tab)
{
	if (tab->flag_space || tab->flag_plus || tab->sign)
		tab->width--;
	if (tab->flag_null && !tab->dot_prec)
	{
		put_sign(box, tab);
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
		put_sign(box, tab);
	}
	while (tab->precision-- > 0)
		ft_putchar_count(box, '0');
}

void				output_d(t_box *box, t_tab *tab)
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
	if (tab->flag_min)
		tab->flag_null = 0;
	put_secondary(box, tab);
	if (tab->n || !tab->dot_prec)
		ft_figure_put(box, tab->n, 10, 97);
	if (tab->flag_min)
	{
		while (tab->width-- > 0)
			ft_putchar_count(box, ' ');
	}
}
