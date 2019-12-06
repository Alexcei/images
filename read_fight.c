#include "filler_visual.h"

static int 		get_coord_plat(t_fil *fil)
{
	int 	i;

	i = 0;
	while (fil->line[i] && !ft_isdigit(fil->line[i]))
		i++;
	if (fil->line[i] && ft_isdigit(fil->line[i]))
		fil->h_plat = ft_atoi(fil->line + i);
	while (fil->line[i] && ft_isdigit(fil->line[i]))
		i++;
	while (fil->line[i] && !ft_isdigit(fil->line[i]))
		i++;
	if (fil->line[i] && ft_isdigit(fil->line[i]))
		fil->w_plat = ft_atoi(fil->line + i);
	if (fil->h_plat && fil->w_plat)
		return (1);
	return (0);
}

static int 		creat_plateau(t_fil *fil, int i)
{
	char	**arr;

	if (i == 0)
		return (1);
	if (!(arr = ft_strsplit(fil->line, ' ')))
		return (0);
	if (!arr[1] || ((int)ft_strlen(arr[1]) != fil->w_plat))
		return (0);
	if (!(fil->plat[i - 1] = ft_strdup(arr[1])))
		return (0);
	ft_free_char_arr(&arr);
	return (1);
}

int			ft_read_fil(t_fil *fil)
{
	int 	i;

	if (get_next_line(fil->fd, &fil->line) <= 0)
		print_error(fil, "read_end");
	if (!fil->line)
		print_error(fil, "error_read_fight");
	if (!ft_strnequ(fil->line, "Plateau", 7))
		return (0);
	if (!get_coord_plat(fil))
		print_error(fil, "error_read_plateau");
	ft_strdel(&fil->line);
	if (!(fil->plat = (char **) ft_memalloc(sizeof(char *) * (fil->h_plat + 1))))
		print_error(fil, "error_malloc_read_plateau");
	i = 0;
	while (i < fil->h_plat + 1)
	{
		get_next_line(fil->fd, &fil->line);
		if (!fil->line || !creat_plateau(fil, i))
			print_error(fil, "error_read_plateau");
		ft_strdel(&fil->line);
		i++;
	}
	return (1);
}