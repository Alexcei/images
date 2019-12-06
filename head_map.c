#include "filler_visual.h"

void			ft_put_players_on_heat_map(t_fil *fil)
{
	int			w;
	int 		h;

	fil->count_enemy = 0;
	h = 0;
	while (h < fil->h_plat)
	{
		w = 0;
		while (w < fil->w_plat)
		{

			if (ft_is_enemy_fil(fil, fil->plat[h][w]))
			{
				fil->count_enemy++;
				fil->map[h][w] = 1;
			}
			else
				fil->map[h][w] = 0;
			w++;
		}
		h++;
	}
}

int				ft_creat_heat_map(t_fil *fil)
{
	int 		i;

	i = 0;
	if (!(fil->map = (int**)ft_memalloc(sizeof(int*) * fil->h_plat)))
		return (0);
	while (i < fil->h_plat)
	{
		if (!(fil->map[i] = (int *)ft_memalloc(sizeof(int) * fil->w_plat)))
			return (0);
		i++;
	}
	return (1);
}

static int		filling_out_head_map(t_fil *fil, int h, int w)
{
	int 		res;

	res = 0;
	if (h > 0 && fil->map[h - 1][w] == 0 && ++res)
		fil->map[h - 1][w] += fil->map[h][w] + 1;
	if (h < fil->h_plat - 1 && fil->map[h + 1][w] == 0 && ++res)
		fil->map[h + 1][w] += fil->map[h][w] + 1;
	if (w > 0 && fil->map[h][w - 1] == 0 && ++res)
		fil->map[h][w - 1] += fil->map[h][w] + 1;
	if (w < fil->w_plat - 1 && fil->map[h][w + 1] == 0 && ++res)
		fil->map[h][w + 1] += fil->map[h][w] + 1;
	return (res);
}

int				ft_fill_heat_map(t_fil *fil, int i)
{
	int			w;
	int 		h;
	int 		res;

	h = 0;
	res = 0;
	while (h < fil->h_plat)
	{
		w = 0;
		while (w < fil->w_plat)
		{
			if (fil->map[h][w] == i)
			{
				res += filling_out_head_map(fil, h, w);
			}
			w++;
		}
		h++;
	}
	return (res);
}