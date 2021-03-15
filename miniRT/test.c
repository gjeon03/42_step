#include "mlx/mlx.h"
#include <stdio.h>

void	*mlx_ptr;
void	*win_ptr;

int	press_esc_key(int key, void *p)
{
	printf("Key in Win : %d\n",key);
	if (key == 53)
		exit(0);
}

int	mouse_button(int button,int x,int y, void *p)
{
  printf("Mouse_button in Win, button %d at %dx%d.\n",button,x,y);
}

int	mouse_pos(int x, int y, void *p)
{
	printf("Mouse moving in Win, at %dx%d.\n", x, y);
}

int	color_map(void *win,int w,int h)
{
  int	x;
  int	y;
  int	color;

  x = w;
  while (x--)
    {
      y = h;
      while (y--)
        {
          color = (x*255)/w+((((w-x)*255)/w)<<16)+(((y*255)/h)<<8);
	  	  mlx_pixel_put(mlx_ptr,win_ptr,x,y,color);
        }
    }
}

int main()
{
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx_test");
	mlx_key_hook(win_ptr, press_esc_key, win_ptr);
	mlx_mouse_hook(win_ptr, mouse_button, win_ptr);
	//mlx_hook(win_ptr, MotionNotify, PointerMotionMask, mouse_pos, 0);
	color_map(win_ptr, 500, 500);
	mlx_loop(mlx_ptr);
}
