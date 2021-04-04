#include "mlx.h"
#include <math.h>
#include <stdlib.h>

#define mapWidth 24
#define mapHeight 24
#define screenWidth 640
#define screenHeight 480

#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define	K_ESC 53

#define texWidth 64
#define texHeight 64

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

typedef struct	s_info
{
	void		*mlx;
	void		*win;
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	//double		time;
	//double		oldTime;
	double		moveSpeed;
	double		rotSpeed;
	
	t_img		img;
	int			buf[screenHeight][screenWidth];
	int			**texture;
}				t_info;

int worldMap[mapWidth][mapHeight] =
{ 
	{8,8,8,8,8,8,8,8,8,8,8,4,4,6,4,4,6,4,6,4,4,4,6,4},
  {8,0,0,0,0,0,0,0,0,0,8,4,0,0,0,0,0,0,0,0,0,0,0,4},
  {8,0,3,3,0,0,0,0,0,8,8,4,0,0,0,0,0,0,0,0,0,0,0,6},
  {8,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
  {8,0,3,3,0,0,0,0,0,8,8,4,0,0,0,0,0,0,0,0,0,0,0,4},
  {8,0,0,0,0,0,0,0,0,0,8,4,0,0,0,0,0,6,6,6,0,6,4,6},
  {8,8,8,8,0,8,8,8,8,8,8,4,4,4,4,4,4,6,0,0,0,0,0,6},
  {7,7,7,7,0,7,7,7,7,0,8,0,8,0,8,0,8,4,0,4,0,6,0,6},
  {7,7,0,0,0,0,0,0,7,8,0,8,0,8,0,8,8,6,0,0,0,0,0,6},
  {7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,6,0,0,0,0,0,4},
  {7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,6,0,6,0,6,0,6},
  {7,7,0,0,0,0,0,0,7,8,0,8,0,8,0,8,8,6,4,6,0,6,6,6},
  {7,7,7,7,0,7,7,7,7,8,8,4,0,6,8,4,8,3,3,3,0,3,3,3},
  {2,2,2,2,0,2,2,2,2,4,6,4,0,0,6,0,6,3,0,0,0,0,0,3},
  {2,2,0,0,0,0,0,2,2,4,0,0,0,0,0,0,4,3,0,0,0,0,0,3},
  {2,0,0,0,0,0,0,0,2,4,0,0,0,0,0,0,4,3,0,0,0,0,0,3},
  {1,0,0,0,0,0,0,0,1,4,4,4,4,4,6,0,6,3,3,0,0,0,3,3},
  {2,0,0,0,0,0,0,0,2,2,2,1,2,2,2,6,6,0,0,5,0,5,0,5},
  {2,2,0,0,0,0,0,2,2,2,0,0,0,2,2,0,5,0,5,0,0,0,5,5},
  {2,0,0,0,0,0,0,0,2,0,0,0,0,0,2,5,0,5,0,5,0,5,0,5},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
  {2,0,0,0,0,0,0,0,2,0,0,0,0,0,2,5,0,5,0,5,0,5,0,5},
  {2,2,0,0,0,0,0,2,2,2,0,0,0,2,2,0,5,0,5,0,0,0,5,5},
  {2,2,2,2,1,2,2,2,2,2,2,1,2,2,2,5,5,5,5,5,5,5,5,5} 
};

/*void	verLine(t_info *info, int x, int drawS, int drawE, int color)
{
	int	temp;

	temp = drawS;
	while (temp <= drawE)
	{
		mlx_pixel_put(info->mlx, info->win, x, temp, color);
		temp++;
	}
}*/

void	imageDraw(t_info *info)
{
	for (int y = 0; y < screenHeight; y++)
	{
		for (int x = 0; x < screenWidth; x++)
			info->img.data[y * screenWidth + x] = info->buf[y][x];
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

int		calculateAndSaveToMap(t_info *info)
{
	/*for (int x = 0; x < screenWidth; x++)
		for (int y = 0; y < screenHeight; y++)
		{
			info->buf[y][x] = 0xFFFFFF;
			info->buf[screenHeight - y - 1][x] = 0x000000;
		}
	*/
    //int color = info->texture[texNum][texHeight * texY + texX];
	int	color;
	for (int y = 0; y < screenHeight; y++)
	{
		//가장 왼쪽 광선 (x = 0) 및 가장 오른쪽 광선 (x = w)에 대한
		float	rayDirX0 = info->dirX - info->planeX;
		float	rayDirY0 = info->dirY - info->planeY;
		float	rayDirX1 = info->dirX + info->planeX;
		float	rayDirY1 = info->dirY + info->planeY;

		//화면 중앙 (수평선)과 비교한 현재 y위치
		int		p = y - screenHeight / 2;
		
		//카메라의 수직 위치.
		float	posZ = 0.5 * screenHeight;

		//현재 행의 ㄱ카메라에서 바닥까지의 수평 거리
		//0.5는 정확히 바닥과 천장 중간의 z위치이다.
		float	rowDistance = posZ / p;

		//각 x에 대해 추가해야하는 실제 단계 벡터를 계산한다. (카메라 평면에 평행)
		//단계별 추가는 내부 루프에 가중치가 있는 곱셈을 방지한다.
		float	floorStepX = rowDistance * (rayDirX1 - rayDirX0) / screenWidth;
		float	floorStepY = rowDistance * (rayDirY1 - rayDirY0) / screenWidth;

		//가장 왼쪽 열의 실제 좌표. 오른쪽으로 이동하면 업데이트된다.
		float	floorX = info->posX + rowDistance * rayDirX0;
		float	floorY = info->posY + rowDistance * rayDirY0;

		for (int x = 0; x < screenWidth; x++)
		{
			//cell coord는 floorX와 floorY의 정수 부분에서 간단히 얻는다.
			int	cellX = (int)(floorX);
			int	cellY = (int)(floorY);

			//소수 부분에서 텍스처 좌표를 가져온다.
			int	tx = (int)(texWidth * (floorX - cellX) / 2) & (texWidth - 1);
			int	ty = (int)(texHeight * (floorY - cellY) / 2) & (texHeight - 1);

			floorX += floorStepX;
			floorY += floorStepY;

			//텍스처를 선택하고 픽셀을 그린다.
			int	floorTexture = 3;
			int	ceilingTexture = 6;

			//바닥
			color = info->texture[floorTexture][texWidth * ty + tx];
			color = (color << 1) & 8355711; //조금 더 어둡게 만든다.
			info->buf[y][x] = color;

			tx = (int)(texWidth * (floorX - cellX) * 20) & (texWidth - 1);
			ty = (int)(texHeight * (floorY - cellY) * 20) & (texHeight - 1);
			//천장(대칭, screenHeight - y 대신 y - 1)
			color = info->texture[ceilingTexture][texWidth * ty + tx];
			color = (color << 1) & 8355711; //조금 더 어둡게
			//color = 0xDC143C;
			info->buf[screenHeight - y - 1][x] = color;
		}
	}
	for (int x = 0; x < screenWidth; x++)
	{
		double	cameraX = (2 * x / (double)(screenWidth)) - 1;
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
		 * 위는 DDA 알고리즘을 시작하는 부분이다.
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
		
		//벽을 만나 DDA가 완료되었으니 이제 광선의 시작점에서 벽까지의 이동거리를 계산한다.
		//이 거리는 나중에 벽을 얼마나 높게 그릴지 알아내는데 사용된다.
		//
		if (side == 0)
			perpWallDist = (mapX - info->posX + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - info->posY + (1 - stepY) / 2) / rayDirY;
		/*
		 * 현재 위치에서 실제 거리 값으로 사용했을경우 어안렌즈 효과(fisheye effect) 로 모든 벽이 둥글게 보이게 된다고 한다.
		 * 그래서 플레이어 위치까지의 유클리드 거리 대신, 카메라 평면까지의 거리를 사용한다.
		 * mapX - posX + (1 - stepX / 2) 는 광선이 x방향으로 몇 칸이나
		 * 지나갔는지를 나타내는 수이다. (정수일 필요없음.)
		 * 만약 광선의 방향이 x면에 수직이면 이미 정확한 수직리 값이지만
		 * 대부분의 경우 광선의 방향이 있고 이 때 구해진 값은 실제 수직거리보다
		 * 큰 값이므로 rayDirX 로 나줘준다.
		 * y면에 처음 부딪힌 경우에도 같은 방식으로 계산한다.
		 * mapX - posX 가 음수이더라도 역시 음수인 rayDirX로 나누어 계산
		 * 된 값은 항상 양수가 된다.
		 */

		//스크린에 그릴 line의 높이를 계산.
		int	lineHeight = (int)(screenHeight / perpWallDist);
		//거리가 멀어질수록 높이도 낮아진다.
		int drawStart = -lineHeight / 2 + screenHeight / 2;
		if(drawStart < 0)//0보다 작으면 화면 위로 벗어남.
			drawStart = 0;
		int drawEnd = lineHeight / 2 + screenHeight / 2;
		if(drawEnd >= screenHeight)//스크린 높이보다 크면 스크린 아래로 벗어남.
			drawEnd = screenHeight - 1;
		/* 위의 코드는 벽의 높이 계산
		 * 벽을 더 높게 그리거나 낮게 그리거나 하고 싶으면 2 * h 와 같은
		 * 다른 값을 넣을 수도 있다.
		 * h값은 일정한 벽의 높이, 너비 및 깊이를 가진 박스처럼 보이게 해주고,
		 * 값이 클수록 높이가 높은 박스를 만들어준다.
		 * 이렇게 구한 lineHeight(화면에 그려야 할 수직선의 높이)에서,
		 * 실제로 선을 그릴 위치의 시작 및 끝 위치를 알 수 있다.
		 * 벽의 중심은 화면에 중심이 있어야 하고, 이 중심점이 화면 범위 아래에 놓여 있다면
		 * 0으로, 화면 범위 위에 놓여있다면 h - 1으로 덮어씌운다.
		 */

		/*int	color;
		switch (worldMap[mapX][mapY])
		{
			case 1:
				color = 0xFF0000;
				break;
			case 2:
				color = 0x00FF00;
				break;
			case 3:
				color = 0x0000FF;
				break;
			case 4:
				color = 0xFFFFFF;
				break;
			default:
				color = 0x123145;
		}

		//x, y side의 밝기를 달리해줌.(어둡게)
		if (side == 1)
			color = color / 2;
		*/
		//수직으로 선을 그어주는 함수이다.
		//verLine(info, x, drawStart, drawEnd, color);

		int	texNum = worldMap[mapX][mapY] - 1;
		//1을 빼주는 이유는 0번째 텍스쳐도 0, 벽이 없어도 0이기 때문.
		double	wallX;
		if (side == 0)
			wallX = info->posY + perpWallDist * rayDirY;
		else
			wallX = info->posX + perpWallDist * rayDirX;
		wallX -= floor(wallX);
		/*
		 * wallX의 값은 벽의 x면과 부딪힌 경우 (side == 0)
		 * 벽의 y좌표가 된다.
		 * wallX의 값은 텍스처의 x좌표에 대해서만 사용한다.
		 * 부딪힌 곳의 정확한 x,y값 (double)에서 벽의 x, y 값 (int)
		 * 을 빼서 판단할 수 있다.
		 */

		int	texX = (int)(wallX * (double)texWidth);
		//texX 는 texture의 x좌표를 나타낸다.
		if (side == 0 && rayDirX > 0)
			texX = texWidth - texX - 1;
		if (side == 1 && rayDirY < 0)
			texX = texWidth - texX - 1;
		/*
		 * 이전 코드에서 벽의 색상을 선택해 주었다면, 이번 코드는
		 * 벽의 텍스처를 선택해주는 것이다.
		 */
		double step = 1.0 * texHeight / lineHeight;
        // Starting texture coordinate
        double texPos = (drawStart - screenHeight / 2 + lineHeight / 2) * step;
        for (int y = drawStart; y < drawEnd; y++)
        {
            // Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
            int texY = (int)texPos & (texHeight - 1);
            texPos += step;
            color = info->texture[texNum][texHeight * texY + texX];
            // 광선이 벽의 y면에 부딪힌 경우(side == 1).
            // 조명표현을 위해 색상을 더 검게 만든다.
            // 이진수를 2로 나눔으로써 RGB값을 반감시킨다.
            // 시프트 연산을 하고 01111111 01111111 01111111(835711)을 & 연산하면
            // 어두운 값을 줄 수 있다는데 그냥 외워야 쓰것다.
            if (side == 1)
                color = (color >> 1) & 8355711;
            info->buf[y][x] = color;
        }
	}
}

int		key_press(int key, t_info *info)
{
	if (key == KEY_W)
	{
		if(!worldMap[(int)(info->posX + info->dirX * info->moveSpeed)][(int)(info->posY)])
			info->posX += info->dirX * info->moveSpeed;
		if(!worldMap[(int)(info->posX)][(int)(info->posY + info->dirY * info->moveSpeed)])
			info->posY += info->dirY * info->moveSpeed;
	}
	if (key == KEY_S)
	{
		if(!worldMap[(int)(info->posX - info->dirX * info->moveSpeed)][(int)(info->posY)])
			info->posX -= info->dirX * info->moveSpeed;
		if(!worldMap[(int)(info->posX)][(int)(info->posY - info->dirY * info->moveSpeed)])
			info->posY -= info->dirY * info->moveSpeed;
	}
	if (key == KEY_D)
	{
		double oldDirX = info->dirX;
		info->dirX = info->dirX * cos(-info->rotSpeed) - info->dirY * sin(-info->rotSpeed);
		info->dirY = oldDirX * sin(-info->rotSpeed) + info->dirY * cos(-info->rotSpeed);
		double oldPlaneX = info->planeX;
		info->planeX = info->planeX * cos(-info->rotSpeed) - info->planeY * sin(-info->rotSpeed);
		info->planeY = oldPlaneX * sin(-info->rotSpeed) + info->planeY * cos(-info->rotSpeed);
	}
	if (key == KEY_A)
	{
		double oldDirX = info->dirX;
		info->dirX = info->dirX * cos(info->rotSpeed) - info->dirY * sin(info->rotSpeed);
		info->dirY = oldDirX * sin(info->rotSpeed) + info->dirY * cos(info->rotSpeed);
		double oldPlaneX = info->planeX;
		info->planeX = info->planeX * cos(info->rotSpeed) - info->planeY * sin(info->rotSpeed);
		info->planeY = oldPlaneX * sin(info->rotSpeed) + info->planeY * cos(info->rotSpeed);
	}
	if (key == K_ESC)
		exit(0);
	return (0);
}

void	load_image(t_info *info, int *texture, char *path, t_img *img)
{
	img->img = mlx_xpm_file_to_image(info->mlx, path, &img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);
	for (int y = 0; y < img->img_height; y++)
	{
		for (int x = 0; x < img->img_width; x++)
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
	}
	mlx_destroy_image(info->mlx, img->img);
}

void	load_texture(t_info *info)
{
	t_img	img;

	load_image(info, info->texture[0], "textures/eagle.xpm", &img);
    load_image(info, info->texture[1], "textures/redbrick.xpm", &img);
    load_image(info, info->texture[2], "textures/purplestone.xpm", &img);
    load_image(info, info->texture[3], "textures/greystone.xpm", &img);
    load_image(info, info->texture[4], "textures/bluestone.xpm", &img);
    load_image(info, info->texture[5], "textures/mossy.xpm", &img);
    load_image(info, info->texture[6], "textures/wood.xpm", &img);
    load_image(info, info->texture[7], "textures/colorstone.xpm", &img);
}

int		main_loop(t_info *info)
{
	calculateAndSaveToMap(info);
	imageDraw(info);
	return (0);
}

int		main(void)
{
	t_info	info;

	info.posX = 22;//초기 위치
	info.posY = 12;
	info.dirX = -1;//초기 방향
	info.dirY = 0;
	info.planeX = 0;//플레이어의 카메라 평면
	info.planeY = 0.66;
	info.moveSpeed = 0.1;
	info.rotSpeed = 0.1;
	//info.time = 0;//현재 프레임의 시간
	//info.oldTime = 0;//이전 프레임의 시간
	
	/* 
        버퍼를 초기화해준다.
        버퍼는 우리가 띄운 창의 크기와 같다.
        x->screenWidth 로 가면서 화면을 그려내기 때문에
        y값이 버퍼의 앞에 온다.(info.buf는 [y][x] 형태)
    */
    info.texture = (int **)malloc(sizeof(int *) * 8);
    for (int i = 0; i < 9; i++)
        info.texture[i] = (int *)malloc(sizeof(int) * (texHeight * texWidth));

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < texHeight * texWidth; j++)
            info.texture[i][j] = 0;

    /*
        info.texture 변수는 다음과 같이 선언돼 있는데,
            int        texture[8][texHeight * texWidth];
        이것이 의미하는 바는 총 8가지 종류의 텍스쳐를 저장할 수 있고,
        그 크기가 texHeight * texWidth 라는 뜻이다.
    */
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < texHeight * texWidth; j++)
            info.texture[i][j] = 0;


	info.mlx = mlx_init();
	load_texture(&info);
	info.win = mlx_new_window(info.mlx, screenWidth, screenHeight, "step");
	info.img.img = mlx_new_image(info.mlx, screenWidth, screenHeight);
	info.img.data = (int *)mlx_get_data_addr(info.img.img, &info.img.bpp, &info.img.size_l, &info.img.endian);

	mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_hook(info.win, 2, 0, &key_press, &info);
	mlx_loop(info.mlx);
	//return (0);
}
