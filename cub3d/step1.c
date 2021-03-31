#include "mlx.h"
#include <math.h>

#define mapWidth 24
#define mapHeight 24
#define screenWidth 640
#define screenHeight 480

typedef struct	s_img
{
	void		*img;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
	int			img_width;
	int			img_height;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
}				t_mlx;

typedef struct	s_info
{
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	double		time;
	double		oldTime;
}				t_info;

int worldMap[mapWidth][mapHeight] =
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int		main_loop(t_info *info)
{
	for (int x = 0; x < screenWidth; x++)
	{
		double	cameraX = 2 * x / double(screenWdith) - 1;
		double	rayDirX = info->dirX + info->planeX * cameraX;
		double	rayDirY = info->dirY + info->planeY * cameraX;
		//광선의 방향은 (방향벡터) + (카메라 평면 * 배수)
		
		//현재 플레이어가 위치한 맵 내 위치
		int	mapX = (int)info->posX;
		int	mapY = (int)info->posY;

		//현재 위치에서 다음 x사이드 또는 y사이드까지의 거리
		double	sideDistX;
		double	sideDistY;

		//deltaDistX 는 첫 번째 x면에서 그 다음 x면까지의 광선의 이동거리.
		//fabs : 실수 절대값
		double	deltaDistX = fabs(1 / rayDirX);
		double	deltaDistY = fabs(1 / rayDirY);
		//광선의 이동거리를 계산할때 사용할 변수
		double	perpWallDist;

		//DDAgorithm은 반복문을 실행할 때마다 x, y 방향으로 딱 한 칸씩 점프.
		//광선의 방향에 따라 어느 방향으로 건너뛰는지 달라짐.
		//그 정보는 stepX, Y에 +1, -1 둘 중 하나로 저장됨.
		int	stepX;
		int	stepY;

		//hit는 벽과 부딪혔는지 판별하기 위한 변수
		//부딪힌다는 것은 루플르 종료하기 위한 조건이 됨.
		//x 면에 부딪히면 side = 0
		//y 면에 부딪히면 side = 1
		//x, y 면은 두개의 칸의 경계가 되는 선을 의미함.
		int	hit = 0;
		int	side;

		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (info->posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - info->posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (info->posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - info->posY) * deltaDistY;
		}
		/*
		 * 위는 DDA알고리즘을 시작하기 전 초기값을 구해주는 식이다.
		 * x방향 rayDirX 의 값이 양수라면 stepX의 값은 1, 음수면 -1
		 * rayDirX 의 값이 0이면, stepX는 사용되지 않으므로 어떤 값이든 상관 없음
		 *
		 * sideDistX 의 값은, rayDirX의 값이 양수일 경우, '광선의 시작점부터 오른쪽으로 이동하다 처음 만나는 x면까지의 거리'이다.
		 * 반대로 음수일 경우는 왼쪽으로 이동하다 처음 만나는 x면까지의 거리
		 * sideDistY 의 값도 마찬가지이다. (시작점 기준 위쪽, 아래쪽)
		 */

		while (hit == 0)
		{
			if (sideDistX < sideDistY)//sideDistX가 더 작으면 x면에 부딪힌게 된다.
			{
				sideDistX += deltaDistX;
				mapX += stepX;//1, -1 중 하나
				side = 0;//x면에 부딪히면 0
			}
			else//sideDistX 가 더 크다면 y면에 부딪힌게 된다.
			{
				sideDistY += deltaDistY;
				mapY += stepY;//1, -1 중 하나
				side = 1;//y면에 부딪히면 1
			}
			if (worldMap[mapX][mapY] > 0)
				hit = 1;
		}
		/*
		 * DDA 알고리즘을 시작하는 부분이다.
		 * 이 while 반복문은 벽에 부딪힐 때까지 매번 한 칸(square)씩 광선을 이동시키는 루프이다.
		 * 반복할 때마다 stepX 를 사용하면 x방향으로 한 칸 또는 stepY를 사용하면 y방향으로 한 칸 점프한다. 항상 딱 한 칸씩만 점프한다.
		 * 만약 광선의 방향이 x축 방향과 완전히 일치한다면, (y 방향이 바뀌지는 않을테니) 반복문을 돌 때 x방향으로만 한 칸씩 점프하면 된다.
		 * 만약 광선이 y축 방향으로 아주 조금 기울어져 있으면 x방향으로 엄청 많이 점프하고 나서야 y방향으로 1칸 점프할 것이다.
		 * 만약 광선의 방향이 y축 방향과 완전히 일치한다면, x방향으로는 점프할 필요가 없는 식으로 반복문이 진행된다.
		 * 광선이 점프할 때마다 sideDistX, sideDistY는 deltaDistX, deltaDistY가 더해지면서 값이 업데이트 된다.
		 * 광선이 점프할 때마다 mapX, mapY는 stepX, stepY가 더해지면서 값이 업데이트 된다.
		 *
		 * 광선이 벽에 부딪히면 루프가 종료된다.
		 * 이때, 변수 side의 값이 0이면 벽의 x면에, 1이면 벽의 y면에 부딪혔다는 것을 알 수 있고, 또 mapX, mapY로 어떤 벽이랑 부딪힌 건지도 알 수 있다.
		 */

		if (side == 0)
			perpWallDist = (mapX - info->posX + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - info->posY + (1 - stepY) / 2) / rayDirY;

	}
}

int		main(void)
{
	t_mlx	mlx;
	t_img	img;
	t_info	info;

	info.posX = 22;//초기 위치
	info.posY = 12;
	info.dirX = -1;//초기 방향
	info.dirY = 0;
	info.planeX = 0;//플레이어의 카메라 평면
	info.palneY = 0.66;
	info.time = 0;//현재 프레임의 시간
	info.oldTime = 0;//이전 프레임의 시간

	mlx.mlx = mlx_info();
	mlx.win = mlx_new_window(mlx.mlx, screenWidth, screenHeight, "step");
	img.img = mlx_new_image(mlx.mlx, screenWidth, screenHeight);
	img.data = (int *)mlx_get_data_addr(img.img, &img.bpp, &img.size_l, &img.endian);

	mlx_loop_hook(mlx.mlx, *main_loop, &mlx);
	imageDraw(img);
	mlx_hook(mlx.win, 2, 0, &key_press, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
