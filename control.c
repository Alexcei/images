#include "filler_visual.h"

static void		color_up(t_data *data)
{
	if (data->camera->color_selection < 3)
		data->camera->color_selection++;
	else
		data->camera->color_selection = 0;
}

static void		view_up(t_data *data)
{
	if (data->camera->view_selection < 2)
		data->camera->view_selection++;
	else
		data->camera->view_selection = 0;
}

static void		polygon_up(t_data *data)
{
	if (!data->camera->polygon)
		data->camera->polygon++;
	else
		data->camera->polygon--;
}

static void		zoom_down(t_data *data)
{
	data->camera->zoom  -= 1;
	if (data->camera->zoom  < 1)
		data->camera->zoom = 1;
}

static void		put_pause(t_data *data)
{
	if (data->pause == 0)
		data->pause = 1;
	else
		data->pause = 0;
	data->camera->zoom  -= 1;
}

int				fdf_hook_keydown(int key, t_data *data)
{
	if (key == MAIN_PAD_ESC)
		exit(EXIT_SUCCESS);
	if (key == 0)
		put_pause(data);
	if (key == MAIN_PAD_C)
		color_up(data);
	if (key == MAIN_PAD_V)
		view_up(data);
	if (key == MAIN_PAD_P)
		polygon_up(data);
	if (key == NUM_PAD_MINUS)
		zoom_down(data);
	if (key == NUM_PAD_PLUS)
		data->camera->zoom  += 1;
	if (key == ARROW_UP)
		data->camera->alpha  += 0.1f;
	if (key == ARROW_DOWN)
		data->camera->alpha  -= 0.1f;
	if (key == ARROW_LEFT)
		data->camera->beta  -= 0.1f;
	if (key == ARROW_RIGHT)
		data->camera->beta  += 0.1f;
	fdf_render(data);
	return (0);
}

/*
int		ft_close(void *param)
{
	(void)param;
	exit(0);
}

void	zoom(int key, t_data *data)
{
	if (key == NUM_PAD_PLUS ||
		key == MAIN_PAD_PLUS ||
		key == MOUSE_SCROLL_UP)
		data->camera->zoom++;
	else if (key == NUM_PAD_MINUS ||
			 key == MAIN_PAD_MINUS ||
			 key == MOUSE_SCROLL_DOWN)
		data->camera->zoom--;
	if (data->camera->zoom < 1)
		data->camera->zoom = 1;
	fdf_render(data);
}

void	move(int key, t_data *data)
{
	if (key == ARROW_LEFT)
		data->camera->x_offset -= 10;
	else if (key == ARROW_RIGHT)
		data->camera->x_offset += 10;
	else if (key == ARROW_UP)
		data->camera->y_offset -= 10;
	else
		data->camera->y_offset += 10;
	fdf_render(data);
}

void	flatten(int key, t_data *data)
{
	if (key == MAIN_PAD_LESS)
		data->camera->z_divisor -= 0.1;
	else if (key == MAIN_PAD_MORE)
		data->camera->z_divisor += 0.1;
	if (data->camera->z_divisor < 0.1)
		data->camera->z_divisor = 0.1;
	else if (data->camera->z_divisor > 10)
		data->camera->z_divisor = 10;
	fdf_render(data);
}

void	change_projection(int key, t_data *data)
{
	data->camera->alpha = 0;
	data->camera->beta = 0;
	data->camera->gamma = 0;
	if (key == MAIN_PAD_I)
		data->camera->view_selection = ISO;
	else if (key == MAIN_PAD_P)
		data->camera->view_selection = PARALLEL;
	fdf_render(data);
}

int			key_press(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (key == MAIN_PAD_ESC)
		exit(0);
	if (key == NUM_PAD_PLUS || key == MAIN_PAD_PLUS
		|| key == NUM_PAD_MINUS || key == MAIN_PAD_MINUS)
		zoom(key, data);
	else if (key == ARROW_LEFT || key == ARROW_RIGHT
			 || key == ARROW_UP || key == ARROW_DOWN)
		move(key, data);
	else if (key == MAIN_PAD_LESS || key == MAIN_PAD_MORE)
		flatten(key, data);
	else if (key == MAIN_PAD_P || key == MAIN_PAD_I)
		change_projection(key, data);
	return (0);
}

int			mouse_press(int button, int x, int y, void *param)
{
	t_data	*data;

	(void)x;
	(void)y;
	data = (t_data *)param;
	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
		zoom(button, data);
	else if (button == MOUSE_LEFT_BUTTON)
		data->mouse->is_pressed = true;
	return (0);
}

int			mouse_release(int button, int x, int y, void *param)
{
	t_data	*data;

	(void)x;
	(void)y;
	(void)button;
	data = (t_data *)param;
	data->mouse->is_pressed = false;
	return (0);
}

int			mouse_move(int x, int y, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	data->mouse->previous_x = data->mouse->x;
	data->mouse->previous_y = data->mouse->y;
	data->mouse->x = x;
	data->mouse->y = y;
	if (data->mouse->is_pressed)
	{
		data->camera->beta += (x - data->mouse->previous_x) * 0.002;
		data->camera->alpha += (y - data->mouse->previous_y) * 0.002;
		fdf_render(data);
	}
	return (0);
}

void		setup_controls(t_data *data)
{
	mlx_hook(data->win, 2, 0, key_press, data);
	mlx_hook(data->win, 17, 0, ft_close, data);
	mlx_hook(data->win, 4, 0, mouse_press, data);
	mlx_hook(data->win, 5, 0, mouse_release, data);
	mlx_hook(data->win, 6, 0, mouse_move, data);
}*/