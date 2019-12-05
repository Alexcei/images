/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpole <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 11:57:03 by bpole             #+#    #+#             */
/*   Updated: 2019/11/19 21:17:09 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct		s_box
{
	const char		*format;
	char			*str;
	int				res;
	int				fd;
	int				i;
	va_list			av;

}					t_box;

typedef struct		s_tab
{
	int				len;
	int				width;
	int				sign;
	int				precision;
	int				dot_prec;
	int				flag_min;
	int				flag_plus;
	int				flag_space;
	int				flag_null;
	int				flag_grid;
	int				modifier_h;
	int				modifier_l;
	int				modifier_big_l;
	int				wildcard;
	unsigned long	n;
	long			decimal;
}					t_tab;

int					ft_printf(const char *format, ...);
int					ft_fprintf(int fd, const char *format, ...);
void				parser(t_box *box, t_tab *tab);
void				output_s(t_box *box, t_tab *tab);
void				output_c(t_box *box, t_tab *tab);
void				output_p(t_box *box, t_tab *tab);
void				output_persent(t_box *box, t_tab *tab);
void				output_d(t_box *box, t_tab *tab);
void				output_u(t_box *box, t_tab *tab);
void				output_o(t_box *box, t_tab *tab);
void				output_x(t_box *box, t_tab *tab, char x);
void				output_f(t_box *box, t_tab *tab);
void				parser_wildcard(t_box *box, t_tab *tab);
void				parser_number(t_box *box, t_tab *tab, int *pars);

int					ft_figure_len(unsigned long n, unsigned rank);
void				ft_figure_put(t_box *box,
								unsigned long n, unsigned rank, char c);
void				ft_putchar_count(t_box *box, char c);
void				ft_putstr_count(t_box *box, char *s);
void				put_sign(t_box *box, t_tab *tab);

#endif
