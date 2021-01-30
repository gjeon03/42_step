#include "get_next_line.h"
#include <stdio.h>

int		get_next_line(int fd, char **line);

int	main()
{
	int		ret;
	int		fd;
	char	*line;
	
	fd = open("test.txt", O_RDONLY);
	while ((ret = (get_next_line(fd, &line)) > 0))
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s\n", line);
	free(line);
	//system("leaks a.out > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");
	return (0);
}
