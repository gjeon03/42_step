#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include "../utiles/libft/libft.h"
//# include "../utiles/get_next_line/get_next_line.h"
# include "mlx"
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

# define DIR_CH "NSEW"

# define T_WIDTH 64
# define T_HEIGTH 64

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
}				t_mlx;

typedef struct	s_window
{
	int			width;
	int			height;
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	double		moveSpeed;
	double		rotSpeed;
	int			dir_flag;
	int			sprite_count;
}				t_window;

typedef struct	s_img
{
	int			x;
	void		*img;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
	int			img_width;
	int			img_height;
}				t_img;

typedef struct	s_tex
{
	void		*img;
	char		*data;
	int			bpp;
	int			endian;
	int			size_l;
	int			img_width;
	int			img_height;

}				t_tex;

typedef struct	s_key
{
	int			w;
	int			a;
	int			s;
	int			d;
	int			l;
	int			r;
}				t_key;

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
	int			map_flag;
}				t_map;

typedef struct	s_sprite
{
	double		x;
	double		y;
	int			texture;
	int			numSprites;
}				t_sprite;

typedef struct	s_ray
{
	double		cameraX;
	double		rayDirX;
	double		rayDirY;
	int			mapX;
	int			mapY;
	double		sideDistX;
	double		sideDistY;
	double		deltaDistX;
	double		deltaDistY;
	double		perpWallDist;
	int			stepX;
	int			stepY;
	int			side;
	int			drawStart;
	int			drawEnd;
	int			lineHeight
	int			color;
	int			hit;
}				t_ray;

typedef struct	s_pair
{
	double		first;
	int			second;
}				t_pair;

typedef struct	s_info
{
	void		*mlx;
	void		*win;
	t_map		*map;
	t_window	*window;
	t_color		*color;
	t_img		*img;
	t_key		key;
	double		*zBuffer;
	int			*buf;
	int			**texture;
	char		**path;
	t_tex		tex[5];
}				t_info;

int		check_file_name(char *file_name);
int		treat_description(char *file_name, t_info *info);

int		is_space(char c);
int		is_map_character(char c);
int		save_map(char *line, int gnl_return, t_info *info);
int		is_type_identifier(char a, char b, char *line, t_info *info);
int		parse_line(char *line, int gnl_return, t_info *info);

int		check_map(t_info *info);
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

void	load_image(t_info *info, int *texture, char *path, t_img *img);
int		load_texture(t_info *info);
# endif
