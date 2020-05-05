#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "./libft/libft.h"
int main(void)
{
	int fd;
	char *line;
	size_t i = 0;

	fd = open("cheli.txt", O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		ft_putendl(line);
		i++;
	}
	ft_putnbr(i);
	close(fd);
	return(0);
}
