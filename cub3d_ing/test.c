#include "./include/cub3d.h"

int		main(void)
{
	t_info	*info;
	int		i;

	if (!(info = malloc(sizeof(t_info) * 1)))
		return (-1);
	if (!(info->map = malloc(sizeof(t_map) * 1)))
		return (-1);
	treat_description("map.cub", info);
	i = 0;
	printf("test\n");
	printf("==%d\n", info->test);
	printf("==%d\n", info->map->row);
	while (i < info->map->row)
		printf("%s\n", info->map->tab[i++]);
	free(info->map);
	free(info);
	return (0);
}
