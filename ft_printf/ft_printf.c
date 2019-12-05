/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpole <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 11:29:06 by bpole             #+#    #+#             */
/*   Updated: 2019/11/02 16:30:55 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	t_box	box;
	t_tab	tab;

	ft_bzero(&box, sizeof(t_box));
	box.fd = 1;
	box.format = format;
	va_start(box.av, format);
	parser(&box, &tab);
	va_end(box.av);
	return (box.res);
}

void		ft_figure_put(t_box *box, unsigned long n, unsigned rank, char c)
{
	if (n >= rank)
		ft_figure_put(box, n / rank, rank, c);
	n = n % rank;
	n += n < 10 ? '0' : c - 10;
	ft_putchar_count(box, (char)n);
}

int			ft_figure_len(unsigned long n, unsigned rank)
{
	if (n >= rank)
		return (ft_figure_len(n / rank, rank) + 1);
	return (1);
}

void		ft_putstr_count(t_box *box, char *s)
{
	int		len;

	len = ft_strlen(s);
	write(box->fd, &*s, len);
	box->res += len;
}

void		ft_putchar_count(t_box *box, char c)
{
	write(box->fd, &c, 1);
	box->res++;
}
