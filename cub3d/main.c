#include "mlx.h"
#include <math.h>

#define screenWidth 640
#define screenHeight 480
#define mapWidth 24
#define mapheight 24

//Event Key
#define X_EVENT_KEY_PRESS 2
#define X_EVENT_KEY_EXIT 17

//direction
#define KEY_F 126
#define KEY_B 125
#define KEY_L 123
#define KEY_R 124

//keyboard ESC
#define K_ESC 53

typedef struct	s_info
{
	double		playerPositionX;
	double		playerPositionY;
	double		directionVectorX;
	double		directionVectorY;
	double		planeX;
	double		planeY;
	double		moveSpeed;
	double		rotSpeed;
	void		*mlx;
	void		*win;
	void		*img;
	int			*data;
	int			bpp;
	int			size_l;
	int			endian;
}				t_info;

typedef struct	s_vec3
{
	double		x;
	double		y;
	double		z;
}				t_vec3;

typedef struct	s_color
{
	t_vec3		color;
	int			int_color;
}				t_color;

int	worldMap[mapWidth][mapHeight]
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

int	main_loop(t_info *info)
{
	//현재 프레임 시간.
	//double time = 0;
	//이전 프레임 시간.
	//double oldTime = 0;
	//현재 프레임의 시간 - 이전 프레임의 시간 : 이동거리 결정 및 fps 측정
	
	//화면 생성 후 게임 루프 시작.
	//while 문은 전체 프레임을 그려내고 입력을 읽는 역할을 한다.
	int	x;

	x = 0;
	while (x < screenWidth)
	{
		/*
		광선의 시작점은 playerPositionX,Y 이다.
		directionVectorX,Y는 플레이어의 초기 방향벡터.
		planeX와 Y는 카메라 평면.
		아래 for 문은 ray의 위치(postion) 및 방향(direction)계산.
		*/
		
		//cameraX는 for문의 x값이 카메라 평면 상에 있을 때의 x좌표.
		double	cameraX = (2 * x / (double)(screenWidth)) - 1;
		//cameraPlaneX = 0; cameraPlaneY = 0.66; dirVecX = -1; dirVecY = 0;
		//광선의 방향은 방향벡터 + 카메라 평면 * 배수.
		double	rayDirectionX = info->directionVectorX + info->planX * cameraX;
		double	rayDirectionY = info->directionVectorY + info->planY * cameraY;
		
		//DDAgorithm
		//현재 player가 위치한 맵 내 위치.
		int	mapX = (int)(info->playerPositionX);
		int	mapY = (int)(info->playerPositionY);

		//현재 위치에서 다음 x사이드 또는 y사이드까지의 거리.
		//이를 이하 '첫번째 x면 및 y면' 이라고 부를것.
		double	sideDistX;
		double	sideDistY;

		//deltaDistX 는 첫 번째 x면에서 그 다음 x면까지의 광선의 이동거리.
		//이 경우 x는 1만큼 이동.
		//abs함수는 정수 절대값
		//fabs함수는 실수 절대값
		double	deltaDistX = fabs(1 / rayDirestionX);
		//deltaDistY는 첫 번째 y면에서 그 다음 y면까지의 광선의 이동거리.
		//이 경우 y는 1만큼 이동.
		double	deltaDistY = fabs(1 / rayDirectionY);

		//광선의 이동거리를 계산할때 사용할 변수.
		double	perpWallDist;

		//DDAgorithm은 반복문을 실행할 때마다 x, y방향으로 딱 한 칸씩 점프.
		//광선의 방향에 따라 어느 방향으로 건너뛰는지 달라짐.
		//그 정보는 stepX, Y에 +1, -1 둘 중 하나로 저장됨.
		int	stepX;
		int	stepY;

		/*
		hit은 벽과 부딪혔는지 판별하기 위한 변수이다.
		부딪힌다는 것은 루프를 종료하기 위한 조건이 됨.
		만약 벽에 부딪혔는데 그게 x면에 부딪힌 거라면 side = 0이다.
		y면에 부딪혔다면 1이됨.
		한편 x면, y면은 어떤 칸의 경계가 되는 선을 의미함.
		*/
		int	hit = 0;
		int	side;
	}
}

int	main(void)
{
	double	posX = 22, posY = 12;//시작 위치
	double	dirX = -1, dirY = 0;//초기 방향 벡터
	double	planeX = 0, planeY = 0.66;//카메라 평면의 2d 레이 캐스터 버전? 플레이어의 카메라 평면?

	double	time = 0;//현재 프레임 시간
	double	oldTime = 0;//이전 프레임 시간

	t_info	info;
	t_color	rgb;
	
	info.mlx = mlx_init();
	info.win = mlx_new_window(info.mlx, screenWidth, screenHeight, "test");
	//app.img = mlx_new_image(app.mlx, screenWidth, screenHeight);
	
	mlx_loop_hook(info.mlx, *main_loop, &app);
	mlx_hook(info.win, X_EVENT_KEY_PRESS, 0, &key_press, &info);
	mlx_loop(info.mlx);
}
