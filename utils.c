#include "filler_visual.h"

void			print_error(t_fil *fil, char *message)
{
	fil->read = 1;
	ft_putendl_fd(message, 2);
	//exit(1);
}

void			ft_free_char_arr(char ***arr)
{
	int			i;

	i = 0;
	if (*arr)
	{
		while ((*arr)[i])
			ft_strdel(&((*arr)[i++]));
		free(*arr);
		*arr = NULL;
	}
}

int				ft_word_count(char const *str, char c)
{
	int			tr;
	int			res;

	tr = 0;
	res = 0;
	while (*str)
	{
		if (*str != c && tr == 0)
			res++;
		tr = (*str++ != c ? 1 : 0);
	}
	return (res);
}

static int		nbr_inbase(char c, int base)
{
	if (base <= 10)
		return (c >= '0' && c <= '9');
	return ((c >= '0' && c <= '9') || (c >= 'A' && c <= ('A' + base - 10))
			||	(c >= 'a' && c <= ('a' + base - 10)));
}

int				ft_atoi_base(const char *str, int base)
{
	size_t		i;
	int			sing;
	long long	res;

	if (!str[0] || (base < 2 || base > 16))
		return (0);
	i = 0;
	res = 0;
	while (ft_isspace(str[i]))
		i++;
	sing = (str[i] == '-' ? -1 : 1);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && nbr_inbase(str[i], base))
	{
		if (str[i] >= 'A' && 'F' >= str[i])
			res = (res * base) + (str[i] - 'A' + 10);
		else if (str[i] >= 'a' && 'f' >= str[i])
			res = (res * base) + (str[i] - 'a' + 10);
		else
			res = (res * base) + (str[i] - '0');
		i += 1;
	}
	return (res * sing);
}

void			ft_free_int_arr(int ***arr, int h)
{
	int			i;

	i = 0;
	if (*arr)
	{
		while (i < h)
			ft_memdel((void*)&((*arr)[i++]));
		free(*arr);
		*arr = NULL;
	}
}

int		ft_is_enemy_fil(t_fil *fil, char c)
{
	if (fil->n_play == 1)
	{
		if (c == 'x' || c == 'X')
			return (1);
	}
	if (fil->n_play == 2)
	{
		if (c == 'o' || c == 'O')
			return (1);
	}
	return (0);
}

int		ft_is_i_fil(t_fil *fil, char c)
{
	if (fil->n_play == 1)
	{
		if (c == 'o' || c == 'O')
			return (1);
	}
	if (fil->n_play == 2)
	{
		if (c == 'x' || c == 'X')
			return (1);
	}
	return (0);
}