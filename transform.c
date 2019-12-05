#include "filler_visual.h"

static void		rotate(t_dot *dot, double alpha, double beta)
{
	double		x;
	double		y;

	x = dot->x;
	y = dot->y;
	dot->x = cos(beta) * x + sin(beta) * dot->z;
	dot->z = -sin(beta) * x + cos(beta) * dot->z;
	dot->y = cos(alpha) * y - sin(alpha) * dot->z;
	dot->z = sin(alpha) * y + cos(alpha) * dot->z;
}

t_dot			transformations(t_dot dot, t_data *data)
{
	dot.x -= (data->width - 1) / 2;
	dot.y -= (data->height - 1) / 2;
	dot.z -= (data->z_min + data->z_max) / 2;
	if (data->camera->view_selection == TOP)
		rotate(&dot, 0, 0);
	else if (data->camera->view_selection == ISO)
	{
		dot.x = (dot.x - dot.y) * cos(1);
		dot.y = (dot.x + dot.y) * sin(1.1) - dot.z;
	}
	else if (data->camera->view_selection == FREE)
		rotate(&dot, data->camera->alpha, data->camera->beta);
	dot.x *= data->camera->zoom;
	dot.y *= data->camera->zoom;
	dot.x += data->camera->x_offset;
	dot.y += data->camera->y_offset;
	return (dot);
}