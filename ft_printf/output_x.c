/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpole <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 12:27:31 by bpole             #+#    #+#             */
/*   Updated: 2019/10/27 12:28:48 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			get_figure(t_box *box, t_tab *tab)
{
	unsigned long	n;

	if (tab->modifier_l == 1)
		n = (unsigned long)va_arg(box->av, unsigned long int);
	else if (tab->modifier_l > 1)
		n = (unsigned long long)va_arg(box->av, unsigned long long int);
	else if (tab->modifier_h == 1)
		n = (unsigned short)va_arg(box->av, unsigned int);
	else if (tab->modifier_h > 1)
		n = (unsigned char)va_arg(box->av, unsigned int);
	else
		n = (unsigned int)va_arg(box->av, unsigned int);
	tab->n = (unsigned long)n;
	tab->len = ft_figure_len(tab->n, 16);
	if (n == 0 && tab->dot_prec)
	{
		tab->precision++;
		tab->width++;
	}
}

static void			put_secondary(t_box *box, t_tab *tab, char x)
{
	if (tab->dot_prec)
		tab->flag_null = 0;
	if (tab->flag_grid)
		tab->width -= 2;
	if (!tab->flag_min && !tab->flag_null)
	{
		while (tab->width-- > 0)
			ft_putchar_count(box, ' ');
	}
	if (tab->flag_grid)
	{
		if (x == 'x')
			ft_putstr_count(box, "0x");
		else
			ft_putstr_count(box, "0X");
	}
	while (tab->flag_null && tab->width-- > 0)
		ft_putchar_count(box, '0');
	while (tab->precision-- > 0)
		ft_putchar_count(box, '0');
}

void				output_x(t_box *box, t_tab *tab, char x)
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
	if (tab->n == 0)
		tab->flag_grid = 0;
	put_secondary(box, tab, x);
	if (tab->n || !tab->dot_prec)
		ft_figure_put(box, tab->n, 16, (char)(x - 23));
	while (tab->flag_min && tab->width-- > 0)
		ft_putchar_count(box, ' ');
}
