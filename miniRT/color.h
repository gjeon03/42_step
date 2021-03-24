#ifndef COLOR_H
# define COLOR_H

# include "vec3.h"

void	write_color(t_color *rgb, color c)
{
	int	r;
	int	g;
	int	b;

	r = 255.999 * c.x;
	g = 255.999 * c.y;
	b = 255.999 * c.z;
	rgb->color.x = r * 256 * 256;
	rgb->color.y = g * 256;
	rgb->color.z = b;
	rgb->int_color = rgb->color.x + rgb->color.y + rgb->color.z;
}

#endif
