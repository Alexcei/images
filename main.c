#include "filler_visual.h"

static int		fdf_close(void *data)
{
	(void)data;
	exit(EXIT_SUCCESS);
}

static int		fdf_init(t_data *data, t_mouse  *mouse,t_camera *camera, t_fil *fil)
{
	ft_bzero(camera, sizeof(t_camera));
	ft_bzero(mouse, sizeof(t_mouse));
	ft_bzero(data, sizeof(t_data));
	ft_bzero(fil, sizeof(t_fil));
	data->camera = camera;
	data->mouse = mouse;
	data->fil = fil;
	if (!(data->mlx = mlx_init()) ||
		!(data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "FDF")) ||
		!(data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT)))
		return (0);
	data->data_addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
										&data->size_line, &data->endian);
	data->camera->x_offset = WIDTH / 2;
	data->camera->y_offset = HEIGHT / 2;
	data->camera->polygon = 1;
	return (1);
}

int				main(void)
{
	t_camera	camera;
	t_mouse 	mouse;
	t_data		data;
	t_fil		fil;

	//sleep(10);

	if (!fdf_init(&data, &mouse, &camera, &fil))
		print_error(&fil, "error: initialization");
	//data.fil->fd = open("t2", O_RDONLY);
	fdf_read_player(&fil);
	mlx_key_hook(data.win, fdf_hook_keydown, &data);
	mlx_hook(data.win, 17, 0, fdf_close, &data);
	mlx_hook(data.win, 4, 0, fdf_mouse_press, &data);
	mlx_hook(data.win, 5, 0, fdf_mouse_release, &data);
	mlx_hook(data.win, 6, 0, fdf_mouse_move, &data);
	mlx_loop_hook(data.mlx, fdf_loop_key_hook, &data);
	mlx_loop(&data.mlx);
	return 0;
}