/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 00:10:30 by gjeon             #+#    #+#             */
/*   Updated: 2021/05/27 00:18:18 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include "../utiles/libft/libft.h"
# include "mlx.h"
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

# define T_W 64
# define T_H 64

typedef struct			s_player
{
	double				dirx;
	double				diry;
	double				planex;
	double				planey;
	double				movespeed;
	double				rotspeed;
}						t_player;

typedef struct			s_img
{
	void				*img;
	int					*data;
	int					size_l;
	int					bpp;
	int					endian;
	int					img_width;
	int					img_height;
}						t_img;

typedef struct			s_key
{
	int					w;
	int					up;
	int					down;
	int					a;
	int					s;
	int					d;
	int					l;
	int					r;
}						t_key;

typedef struct			s_config
{
	int					width;
	int					height;
	int					f_color;
	int					c_color;
	double				posx;
	double				posy;
	char				dir;
	int					dir_flag;
	int					sprite_count;
}						t_config;

typedef struct			s_map
{
	int					row;
	char				**tab;
	int					map_flag;
}						t_map;

typedef struct			s_rgb
{
	int					r;
	int					g;
	int					b;
	unsigned int		color;
}						t_rgb;

typedef struct			s_sprite
{
	double				transformx;
	double				transformy;
	int					spritescreenx;
	int					vmovescreen;
	int					s_height;
	int					drawstarty;
	int					drawendy;
	int					s_width;
	int					drawstartx;
	int					drawendx;
	int					texx;
	int					texy;
	int					stripe;
	int					y;
	int					d;
	int					c;
}						t_sprite;

typedef struct			s_sprites
{
	double				x;
	double				y;
	struct s_sprites	*next;
}						t_sprites;

typedef struct			s_ray
{
	double				camerax;
	double				raydirx;
	double				raydiry;
	int					mapx;
	int					mapy;
	double				sidedistx;
	double				sidedisty;
	double				deltadistx;
	double				deltadisty;
	double				perpwalldist;
	int					stepx;
	int					stepy;
	int					side;
	int					drawstart;
	int					drawend;
	int					lineheight;
	int					color;
	int					hit;
	int					texy;
	int					texx;
	double				wallx;
	double				step;
	double				texpos;
}						t_ray;

typedef struct			s_pair
{
	double				first;
	int					second;
}						t_pair;

typedef struct			s_info
{
	void				*mlx;
	void				*win;
	t_map				map;
	t_img				img;
	t_key				key;
	t_player			player;
	t_sprites			*sprites;
	t_sprite			sprite;
	t_config			config;
	t_ray				ray;
	t_rgb				rgb;
	int					**buf;
	double				*zbuffer;
	int					**texture;
	char				**path;
	int					save;
}						t_info;

int						check_file_name(char *file_name);
int						treat_description(char *file_name, t_info *info);
int						*screen_check(t_info *info);
void					verify_params(t_info *info);

int						is_space(char c);
int						is_map_character(char c);
int						save_map(char *line, int gnl_return, t_info *info);
int						is_type_identifier(char a, char b,
		char *line, t_info *info);
int						parse_line(char *line, int gnl_return, t_info *info);

int						check_map(t_info *info);
int						check_space_sround_position(t_info *info, int i, int j);
int						treat_description(char *file_name, t_info *info);
int						map_error(t_info *info, int i, int j);
int						set_map(t_info *info, char *save);
void					map_free(t_info *info);

int						config_resolution(char *line, t_info *info);
int						file_exists(char *file_name);
int						config_path(int index, char *line, t_info *info);
int						config_color(char location, char *line, t_info *info);

int						key_press(int k, t_info *info);
int						key_release(int k, t_info *info);

int						print_error(char *str, t_info *info);
int						cub_close(t_info *info);

int						get_next_line(int fd, char **line);

int						load_image(t_info *info, int *texture,
		char *path, t_img *img);
int						load_texture(t_info *info);
void					texture_free(t_info *info, int index);

t_sprites				*order_find(t_sprites *sprites, int s_order);
void					sprites_lts(int x, int y, t_info *info);
t_sprites				*sprite_ltsnew(int x, int y);
void					lstadd_back(t_sprites **lst, t_sprites *new);
void					lstclear(t_sprites **lst);

int						main_loop(t_info *info);
void					info_set(t_info *info);

void					image_draw(t_info *info);
void					start_dir(t_info *info);
void					start_dir2(t_info *info);

void					key_update(t_info *info);
void					player_movforward(t_info *info);
void					player_movback(t_info *info);
void					player_movleft(t_info *info);
void					player_movright(t_info *info);
void					player_rotleft(t_info *info);
void					player_rotright(t_info *info);

int						raycast(t_info *info);
void					ray_init(t_info *info, int x);
void					dist_calculation(t_info *info);
void					dda_algorithm(t_info *info);
void					wallcalculation(t_info *info);
void					print_texture(t_info *info, int x);
int						get_text_id(t_info *info);
void					celling_floot(t_info *info);

int						draw_sprites(t_info *info);
void					sprite_xy(t_info *info, t_sprite *sprite);
void					sprite_camera(t_info *info,
		t_sprite *sprite, int s_order);
int						sort_sprites(int *order, double *dist, int amount);
void					sort_order(t_pair *orders, int amount);
void					pix_sprites(t_info *info, t_sprite *sprite);

double					*zbuffer_malloc(t_info *info);
int						**buf_malloc(t_info *info);
void					malloc_clear(t_info *info);
void					buf_free(t_info *info);
int						info_malloc(t_info *info);

int						take_screenshot(t_info *info);
int						bmp_data(int fd, t_info *info, int padsize);
int						bmp_header(int fd, int h, int w, int padsize);
void					int_to_char(unsigned char *c, int i);
void					save_bmp(t_info *info, char *str);

void					path_free(t_info *info, int index);

#endif
