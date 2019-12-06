#include "filler_visual.h"

static void		free_all_fil(t_fil *fil)
{
	if (fil->plat)
		ft_free_char_arr(&fil->plat);
	if (fil->map)
		ft_free_int_arr(&fil->map, fil->h_plat);
}

static void		set_dot(t_data *data, int height, int wigth)
{
	data->dot[height * data->width + wigth].z = - data->fil->map[height][wigth];
	data->dot[height * data->width + wigth].x = (double)wigth;
	data->dot[height * data->width + wigth].y = (double)height;
	if ((data->fil->plat[height][wigth] == 'x' ||
		data->fil->plat[height][wigth] == 'X') &&
		++data->fil->score_one)
		data->dot[height * data->width + wigth].color = PLAYER1;
	else if ((data->fil->plat[height][wigth] == 'o' ||
			data->fil->plat[height][wigth] == 'O') &&
			++data->fil->score_two)
		data->dot[height * data->width + wigth].color = PLAYER2;
	else
		data->dot[height * data->width + wigth].color = 0;
}

void			ft_creat_fdf(t_data *data)
{
	int 	height;
	int 	wigth;

	data->width = data->fil->w_plat;
	data->height = data->fil->h_plat;
	if (!data->camera->zoom)
		data->camera->zoom = FT_MIN(WIDTH / data->width / 2, HEIGHT / data->height / 2);
	data->size = data->width * data->height;
	data->dot = (t_dot*)ft_memalloc(sizeof(t_dot) * data->size);
	data->fil->score_one = 0;
	data->fil->score_two = 0;
	height = 0;
	while (height < data->height)
	{
		wigth = 0;
		while(wigth < data->width)
		{
			set_dot(data, height, wigth);
			wigth++;
		}
		height++;
	}
}

static void		ft_creat_image(t_data *data)
{
	int 		i;

	i = 1;
	if (!(ft_creat_heat_map(data->fil)))
		print_error(data->fil, "error_memory_head_map");
	ft_put_players_on_heat_map(data->fil);
	while (ft_fill_heat_map(data->fil, i))
		i++;
	ft_creat_fdf(data);
}

void		print_score(t_data *data)
{
	int 	len_one;
	int 	len_two;

	len_one = ft_strlen(data->fil->play_one);
	len_two = ft_strlen(data->fil->play_two);
	mlx_string_put(data->mlx, data->win, (WIDTH / 2) - len_one * 10 - 110, (HEIGHT / 8),
				   0x0FFFFFF, ft_itoa(data->fil->score_one));
	mlx_string_put(data->mlx, data->win, (WIDTH / 2) - len_one * 10 - 50, (HEIGHT / 8),
				   PLAYER1, data->fil->play_one);
	mlx_string_put(data->mlx, data->win, (WIDTH / 2) - 30, (HEIGHT / 8),
				   0x0FFFFFF, "&");
	mlx_string_put(data->mlx, data->win, (WIDTH / 2) , (HEIGHT / 8),
				   PLAYER2, data->fil->play_two);
	mlx_string_put(data->mlx, data->win, (WIDTH / 2) + len_two * 10 + 20, (HEIGHT / 8),
				   0x0FFFFFF, ft_itoa(data->fil->score_two));
}

void		print_final(t_data *data)
{
	char	*str;
	int 	len_one;
	int 	len_two;

	len_one = ft_strlen(data->fil->play_one);
	len_two = ft_strlen(data->fil->play_two);
	str = "IS WIN";
	if (data->fil->score_one > data->fil->score_two)
		mlx_string_put(data->mlx, data->win, (WIDTH / 2) - 60 - len_one * 10,
				(HEIGHT / 8) + 30, PLAYER1, data->fil->play_one);
	else
		mlx_string_put(data->mlx, data->win, (WIDTH / 2) - 60 - len_two * 10,
							   (HEIGHT / 8) + 30, PLAYER2, data->fil->play_two);
	mlx_string_put(data->mlx, data->win, (WIDTH / 2) - 50, (HEIGHT / 8) + 30,
				   0x0FFFFFF, str);
}

int				fdf_loop_key_hook(t_data *data)
{
	char	*str;

	if (data->pause == 0)
	{
		while (!data->fil->read && !ft_read_fil(data->fil))
		{
			if (data->fil->plat)
			{
				ft_creat_image(data);
				free_all_fil(data->fil);
			}
		}
	}
	fdf_render(data);
	sleep(10);
	print_score(data);
	if (data->pause == 1)
	{
		str = "PAUSE";
		mlx_string_put(data->mlx, data->win, (WIDTH / 5) - 10, (HEIGHT / 2) - 10,
					   0x0FFFFFF, str);
	}
	if (data->fil->read)
		print_final(data);
	return (0);
}