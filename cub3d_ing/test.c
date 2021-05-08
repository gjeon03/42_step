#include "./include/cub3d.h"

int		main(void)
{
	t_info	info;
	int		i;

	treat_description("map.cub", &info);
	i = 0;
	while (i < info.map.row)
		printf("%s\n", info.map.tab[i]);
	return (0);
}
