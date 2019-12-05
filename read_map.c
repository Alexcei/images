#include "filler_visual.h"

static int		get_color(char *str)
{
	int 		i;

	i = 0;
	while (str[i] && str[i] != ',')
		i++;
	if (str + i + 3)
		return (ft_atoi_base(str + i + 3, 16));
	return (0);
}

static void		creat_arr(t_data *data, char *coords)
{
	char 		**arr;
	int 		i;

	i = 0;
	arr = ft_strsplit(coords, ' ');
	data->dot = (t_dot*)ft_memalloc(sizeof(t_dot) * data->size);
	while (arr[i])
	{
		data->dot[i].x = i % data->width;
		data->dot[i].y = i / data->width;
		if (ft_strchr(arr[i], ','))
			data->dot[i].color = get_color(arr[i]);
		data->dot[i].z = ft_atoi(arr[i]);
		//data->dot[i].z_start = data->dot[i].z;
		if (data->dot[i].z > data->z_max)
			data->z_max = data->dot[i].z;
		if (data->dot[i].z < data->z_min)
			data->z_min = data->dot[i].z;
		i++;
	}
	ft_free_char_arr(&arr);
	ft_strdel(&coords);
}

static void		ft_strjoin_and_free(char **mutable, char *str)
{
	char 		*tmp;

	tmp = *mutable;
	*mutable = ft_strjoin(*mutable, str);
	ft_strdel(&tmp);
}

int 			fdf_read_map(int fd, t_data *data)
{
	char 		*line;
	char 		*coords;

	line = NULL;
	coords = ft_strnew(0);
	while (get_next_line(fd, &line))
	{
		if (!line)
			return (0);
		if (!data->width)
			data->width = ft_word_count(line, ' ');
		if (!data->width || data->width != ft_word_count(line, ' '))
			return (0);
		ft_strjoin_and_free(&coords, line);
		ft_strjoin_and_free(&coords, " ");
		data->height++;
		ft_strdel(&line);
	}
	if (!(data->size = data->width * data->height))
		return (0);
	data->camera->zoom = FT_MIN(WIDTH / data->width / 2, HEIGHT / data->height / 2);
	creat_arr(data, coords);
	return (1);
}