#ifndef FILLER_VISUAL_H
# define FILLER_VISUAL_H

#include "ft_printf/ft_printf.h"
#include <mlx.h>
#include <math.h>

# define HEIGHT			1080
# define WIDTH			1920
# define SIZE 			HEIGHT * WIDTH

# define TEXT_COLOR			0xEAEAEA
# define BACKGROUND			0xA0B0C0

# define RED			    0xFF0000
# define BLUE			    0x0000FF
# define WHITE 		   		0xFFFFFF

# define FT_MIN(a, b) (a < b ? a : b)
# define MAX(a, b) (a > b ? a : b)
# define MOD(a) (a < 0 ? -a : a)

# define MOUSE_LEFT_BUTTON	1
# define MOUSE_SCROLL_UP	4
# define MOUSE_SCROLL_DOWN	5

# define ARROW_UP			126
# define ARROW_DOWN			125
# define ARROW_LEFT			123
# define ARROW_RIGHT		124

# define NUM_PAD_PLUS		69
# define NUM_PAD_MINUS		78

# define MAIN_PAD_ESC		53
# define MAIN_PAD_I			34
# define MAIN_PAD_P			35
# define MAIN_PAD_PLUS		24
# define MAIN_PAD_MINUS		27
# define MAIN_PAD_LESS		43
# define MAIN_PAD_MORE		47

# define MAIN_PAD_C			8
# define MAIN_PAD_V			9
# define MAIN_PAD_P			35

typedef enum
{
	TOP,
	ISO,
	FREE
}	t_projection;

typedef struct		s_mouse
{
	char			is_pressed;
	int				x;
	int				y;
	int				previous_x;
	int				previous_y;
}					t_mouse;

typedef struct		s_camera
{
	int				zoom;
	double			alpha;
	double			beta;
	double 			gamma;
	double			x_offset;
	double			y_offset;
	double			z_divisor;
	int 			polygon;
	int				color_selection;
	int				view_selection;
}					t_camera;

typedef struct		s_dot
{
	double			x;
	double			y;
	double			z;
	int 			color;
}					t_dot;

typedef struct	s_fil
{
	char 		*play_one;
	char 		*play_two;
	int 		fd;
	char 		**plat;
	int 		w_plat;
	int 		h_plat;
	char 		**pie;
	int 		w_pie;
	int 		h_pie;
	int			n_play;
	int 		x_out;
	int 		y_out;
	char		*line;
	int 		**map;
	int 		score;
	int 		w_plat_tmp;
	int 		h_plat_tmp;
	int 		w_pie_tmp;
	int 		h_pie_tmp;
	int 		h_fil;
	int 		w_fil;
	int 		flag;
	int			count_enemy;
	int 		last_count_enemy;
	int 		read;
}				t_fil;

typedef struct		s_data
{
	t_camera		*camera;
	t_mouse 		*mouse;
	t_fil			*fil;
	t_dot			*dot;
	int 			max_i;
	int 			color_tmp;
	int				width;
	int				height;
	int 			size;
	int 			pause;
	int				z_min;
	int				z_max;
	void			*mlx;
	void			*win;
	void			*img;
	char			*data_addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}					t_data;

/*
**					bresenham.c
*/
void				render_line(t_dot a, t_dot b, t_data *data);
void				render_plane(t_dot a, t_dot b, t_dot c, t_data *data);


/*
**					control.c
*/
int					fdf_hook_keydown(int key, t_data *data);

/*
**					double_split.c
*/
char				**ft_double_split(char const *s, char c1, char c2);

/*
**					head_map.c
*/
void				ft_put_players_on_heat_map(t_fil *fil);
int					ft_creat_heat_map(t_fil *fil);
int					ft_fill_heat_map(t_fil *fil, int i);

/*
**					read_figth.c
*/
int					ft_read_fil(t_fil *fil);

/*
**					render.c
*/
void				fdf_render(t_data *data);

/*
**					transformations.c
*/
t_dot				transformations(t_dot dot, t_data *data);

/*
**					utils.c
*/
void				print_error(t_fil *fil, char *message);
void				ft_free_char_arr(char ***arr);
int					ft_word_count(char const *str, char c);
int					ft_atoi_base(const char *str, int base);


void				ft_free_int_arr(int ***arr, int h);
int					ft_is_enemy_fil(t_fil *fil, char c);
int					ft_is_i_fil(t_fil *fil, char c);

#endif
