#include "mlx/mlx.h"
#include <stdio.h>

typedef struct	s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct	s_vars
{
	void		*mlx;
	void		*win;
}				t_vars;

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

/*int	key_hook(int keycode, t_vars *vars)
{
	printf("Hello from key_hook!");
}*/

int ft_draw(t_data *data)
{
  int i;
  int j;
  t_vec3  color;

  j = data->height - 1;
  while (j >= 0)
  {
    i = 0;
    ft_putstr_fd("\rScanlines remaining: ", 1);
    ft_putnbr_fd(j, 1);
    ft_putchar_fd(' ', 1);
    while (i < data->width)
    {
      ft_vec3_set_xyz(&color, (float)i / (data->width - 1), (float)j / (data->height - 1), 0.25);
      my_mlx_pixel_put(data, i, data->height - 1 - j, &color);
      i++;
    }
    j--;
  }
  mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
  return (0);
}

int		main(void)
{
	t_vars	vars;
	it_data	img;
	int		i;
	int		j;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1080, 1080, "Hello world!");
	img.img = mlx_new_image(vars.mlx, 1080, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	/*i = -2 * 200;
	while (i <= 2*200)
	{
		j = (i * i)/30;
		while (j <= 200)
		{
			my_mlx_pixel_put(&img, 540 + j, 440 - i, 0x00FF0000);
			my_mlx_pixel_put(&img, 540 - j + 1, 440 - i, 0x00FF0000);
			j++;
		}
		i++;
	}*/
	ft_draw(&img);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	
	//mlx_key_hook(vars.win, key_hook, &vars);
	
	mlx_loop(vars.mlx);
}
