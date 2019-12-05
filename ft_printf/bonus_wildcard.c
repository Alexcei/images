/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_wildcard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpole <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 12:02:15 by bpole             #+#    #+#             */
/*   Updated: 2019/10/27 12:03:15 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		parser_number(t_box *box, t_tab *tab, int *pars)
{
	if ((!*pars || tab->wildcard) && ft_isdigit(box->format[box->i]))
	{
		*pars = 0;
		while (ft_isdigit(box->format[box->i]))
		{
			*pars *= 10;
			*pars += box->format[box->i] - '0';
			box->i++;
		}
	}
}

void		parser_wildcard(t_box *box, t_tab *tab)
{
	int		i;

	if (box->format[box->i] == '*' && ++box->i)
	{
		tab->wildcard = 1;
		if ((i = (int)va_arg(box->av, int)))
		{
			if (i < 0 && tab->dot_prec)
				tab->dot_prec = 0;
			else if (i < 0 && !tab->dot_prec)
			{
				tab->flag_min = 1;
				tab->width = FT_ABS(i);
			}
			else
			{
				if (tab->dot_prec)
					tab->precision = i;
				else
					tab->width = i;
			}
		}
		else
			tab->flag_null = 1;
	}
}
