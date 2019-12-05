/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_c_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpole <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 12:16:47 by bpole             #+#    #+#             */
/*   Updated: 2019/10/27 12:16:56 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		put_width(t_box *box, t_tab *tab)
{
	while (tab->width--)
	{
		if (tab->flag_null && !tab->flag_min)
			ft_putchar_count(box, '0');
		else
			ft_putchar_count(box, ' ');
	}
}

void			output_s(t_box *box, t_tab *tab)
{
	char		*s;

	if ((s = va_arg(box->av, char*)))
		box->str = ft_strdup(s);
	else
		box->str = ft_strdup("(null)");
	tab->len = ft_strlen(box->str);
	if (tab->dot_prec && tab->len > tab->precision)
	{
		box->str[tab->precision] = '\0';
		tab->len = tab->precision;
	}
	if (tab->width > tab->len)
		tab->width -= tab->len;
	else
		tab->width = 0;
	box->res += tab->len;
	if (tab->flag_min)
		write(box->fd, box->str, tab->len);
	put_width(box, tab);
	if (!tab->flag_min)
		write(box->fd, box->str, tab->len);
	free(box->str);
}

void			output_c(t_box *box, t_tab *tab)
{
	char		s;

	s = (char)va_arg(box->av, char*);
	if (tab->width > 0)
		tab->width--;
	if (tab->flag_min)
		ft_putchar_count(box, s);
	put_width(box, tab);
	if (!tab->flag_min)
		ft_putchar_count(box, s);
}
