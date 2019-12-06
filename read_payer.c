#include "filler_visual.h"

static char		*get_player(t_fil *fil)
{
	char 	**arr;
	char 	*player;
	int 	i;

	i = 0;
	arr = ft_double_split(fil->line, '/', '.');
	if (!arr)
		print_error(fil, "error_read_player");
	while (arr[i])
		i++;
	if (i < 2)
		print_error(fil, "error_read_player");
	player = ft_strdup(arr[i - 2]);
	ft_free_char_arr(&arr);
	return (player);
}

void		fdf_read_player(t_fil *fil)
{
	while (!fil->play_two)
	{
		get_next_line(fil->fd, &fil->line);
		if (!fil->line)
			print_error(fil, "error_read_player");
		if (ft_strnequ(fil->line, "$$$ exec p1", 11))
			fil->play_one = get_player(fil);
		else if (ft_strnequ(fil->line, "$$$ exec p2", 11))
			fil->play_two = get_player(fil);
		ft_strdel(&fil->line);
	}
	fil->n_play = 1;
}