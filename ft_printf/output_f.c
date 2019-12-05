/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpole <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 12:17:10 by bpole             #+#    #+#             */
/*   Updated: 2019/10/27 12:40:15 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static double		ft_pow(double n, int pow)
{
	return (pow ? n * ft_pow(n, pow - 1) : 1);
}

static void			ft_put_decimal(t_box *box, t_tab *tab, long decimal)
{
	tab->precision -= ft_figure_len(decimal, 10);
	if (!decimal)
		tab->precision++;
	while (tab->precision-- > 0)
		ft_putchar_count(box, '0');
	if (decimal)
	{
		if (decimal >= 10)
			ft_put_decimal(box, tab, decimal / 10);
		decimal %= 10;
		ft_putchar_count(box, (char)(decimal + '0'));
	}
}

static void			put_secondary(t_box *box, t_tab *tab)
{
	if (tab->flag_null && !tab->flag_min)
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
	ft_figure_put(box, tab->n, 10, 97);
	if (tab->flag_grid || tab->precision)
		ft_putchar_count(box, '.');
	ft_put_decimal(box, tab, tab->decimal);
	while (tab->width-- > 0)
		ft_putchar_count(box, ' ');
}

void				output_f(t_box *box, t_tab *tab)
{
	double long		n;
	double long		decimal;

	if (tab->modifier_big_l)
		n = (double long)va_arg(box->av, double long);
	else
		n = (double)va_arg(box->av, double);
	if (n < 0 && ++tab->sign)
		n *= -1;
	if (!tab->dot_prec)
		tab->precision = 6;
	decimal = (n - (long)n) * ft_pow(10, tab->precision + 1);
	decimal = ((long)decimal % 10 > 4) ? (decimal) / 10 + 1 : decimal / 10;
	tab->n = (long)n + (long)(decimal / ft_pow(10, tab->precision));
	tab->decimal = (long)decimal % (long)ft_pow(10, tab->precision);
	tab->len = ft_figure_len(tab->n, 10);
	tab->width -= tab->len + tab->precision;
	if (tab->flag_grid || tab->precision)
		tab->width--;
	if (tab->flag_space || tab->flag_plus || tab->sign)
		tab->width--;
	put_secondary(box, tab);
}
