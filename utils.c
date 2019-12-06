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