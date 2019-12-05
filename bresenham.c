#include "filler_visual.h"

static void		paint_point(int x, int y, t_data *data, int color_default)
{
	int			color[4] = {0xFFFFFF, 0xFF0000, 0x00FF00, 0x0000FF};
	int			i;

	i = x + y * WIDTH;
	if (0 < x && x < WIDTH && 0 < y && y < HEIGHT)
	{
		if (color_default)
			((int *)(data->data_addr))[i] = color_default;
		else
			((int *)(data->data_addr))[i] = color[data->camera->color_selection];
	}
}

void			render_line(t_dot a, t_dot b, t_data *data)
{
	double		x_step;
	double		y_step;
	int 		max;

	x_step = b.x - a.x;
	y_step = b.y - a.y;
	max = MAX(MOD(x_step), MOD(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		paint_point((int)a.x, (int)a.y, data, a.color);
		a.x += x_step;
		a.y += y_step;
	}
}

static void		paint_plane(int x, int y, t_data *data, int color_default)
{
	int			color[4] = {0x999999, 0x990000, 0x009900, 0x000099};
	int			i;

	i = x + y * WIDTH;
	if (0 < x && x < WIDTH && 0 < y && y < HEIGHT)
	{
		if (color_default)
			((int *)(data->data_addr))[i] = color_default;
		else
			((int *)(data->data_addr))[i] = color[data->camera->color_selection];
	}
}

static void		render_line_plane(t_dot a, t_dot b, t_data *data)
{
	double 		x_step;
	double 		y_step;
	int 		max;

	x_step = b.x - a.x;
	y_step = b.y - a.y;
	max = MAX(MOD(x_step), MOD(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		paint_plane((int)a.x, (int)a.y, data, data->color_tmp);
		a.x += x_step;
		a.y += y_step;
	}
}

void			render_plane(t_dot a, t_dot b, t_dot c, t_data *data)
{
	double		x_step;
	double		y_step;
	int			max;

	x_step = b.x - a.x;
	y_step = b.y - a.y;
	max = MAX(MOD(x_step), MOD(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		render_line_plane(a, c, data);
		a.x += x_step;
		a.y += y_step;
	}
}