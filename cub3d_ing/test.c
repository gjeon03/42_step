#include "./include/cub3d.h"

int		main(void)
{
	t_info	info;
	int		i;

	//if (!(info = malloc(sizeof(t_info) * 1)))
	//	return (-1);
	if (!(info.map = malloc(sizeof(t_map) * 1)))
		return (-1);
	if (!(info.window = malloc(sizeof(t_window) * 1)))
		return (-1);
	if (!(info.path = malloc(sizeof(t_path) * 1)))
		return (-1);
	info.map->row = 0;
	treat_description("map.cub", &info);
	i = 0;
	printf("test\n");
	printf("==test:%d\n", info.test);
	printf("==row:%d\n", info.map->row);
	printf("==width:%d\n", info.window->width); 
	printf("==height:%d\n", info.window->height); 
	while (i < info.map->row)
		printf("teb=%s\n", info.map->tab[i++]);
	i = 0;
	while (i < 5)
		printf("path=%s\n", info.path->path[i++]);
	free(info.window);
	i = 0;
	//while (i < 5)
	//	free(info->path->path[i++]);
	i = 0;
	//while (i < info->map->row)
	//	free(info->map->tab[i++]);
	free(info.map->tab);
	free(info.map);
	free(info.path);
	//free(info);
	return (0);
}
