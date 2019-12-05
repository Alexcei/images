/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpole <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 21:17:39 by bpole             #+#    #+#             */
/*   Updated: 2019/11/19 21:17:40 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_fprintf(int fd, const char *format, ...)
{
	t_box	box;
	t_tab	tab;

	ft_bzero(&box, sizeof(t_box));
	box.fd = fd;
	box.format = format;
	va_start(box.av, format);
	parser(&box, &tab);
	va_end(box.av);
	return (box.res);
}
