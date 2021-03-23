#ifndef COLOR_H
# define COLOR_H

# include "vec3.h"

void	write_color(t_mlx *app, t_vec3 c)
{
	int	r;
	int	g;
	int	b;

	r = 255.999 * c.x;
	g = 255.999 * c.y;
	b = 255.999 * c.z;

	app->color.x = r * 256 * 256;
	app->color.y = g * 256;
	app->color.z = b;
	app->int_color = app->color.x + app->color.y + app->color.z;
}

#endif
