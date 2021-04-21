#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <./libft/libft.h>
# include "mlx"

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
	char		**path;
}				t_path;

int		check_file_name(char *file_name);
int		treat_description(char *file_name, t_info *info);
int		is_space(char c);
int		is_map_character(char c);
int		save_map(char *line, int gnl_return);
int		is_type_identifier(char a, char b, char *line);
int		parse_line(char *line, t_info *info, int gnl_return);

int		config_resolution(char *line, t_info *info);
int 	file_exists(char *file_name);
int		config_path(int index, char *line, t_info *info);
int		config_color(char location, char *line, t_info *info);

int		key_press(int key, t_info *info);
int		key_release(int key, t_info *info);

# endif
