#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include "../utiles/libft/libft.h"
//# include "../utiles/get_next_line/get_next_line.h"
//# include "mlx"
# include <fcntl.h>

# define O_MAX 256
# define BUFFER_SIZE 200

# define WIN_TITLE "cub3D"
# define KEY_ESC 53
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_L 123
# define KEY_R 124

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
}				t_mlx;

typedef struct	s_window
{
	int			width;
	int			height;
}				t_window;

typedef struct	s_img
{
	void		*img;
}				t_img;

typedef struct	s_key
{
	int			w;
	int			a;
	int			s;
	int			d;
	int			l;
	int			r;
}				t_key;

typedef struct	s_path
{
	char		*path[5];
}				t_path;

typedef struct	s_color
{
	int			f_color;
	int			c_color;
}				t_color;

typedef struct	s_map
{
	int			row;
	int			col;
	char		**tab;
}				t_map;

typedef struct	s_info
{
	int			test;
	t_mlx		mlx;
	t_map		*map;
	t_window	*window;
	t_color		color;
	t_path		*path;
}				t_info;

int		check_file_name(char *file_name);
int		treat_description(char *file_name, t_info *info);

int		is_space(char c);
int		is_map_character(char c);
int		save_map(char *line, int gnl_return, t_info *info);
int		is_type_identifier(char a, char b, char *line, t_info *info);
int		parse_line(char *line, int gnl_return, t_info *info);

void	check_map(t_info *info);
int		check_space_sround_position(t_info *info, int i, int j);
int		set_map(t_info *info, char *save);

int		config_resolution(char *line, t_info *info);
int 	file_exists(char *file_name);
int		config_path(int index, char *line, t_info *info);
int		config_color(char location, char *line, t_info *info);

int		key_press(int key, t_info *info);
int		key_release(int key, t_info *info);

int		print_error(char *str);

int		get_next_line(int fd, char **line);
# endif
