#include "./libft/libft.h"
#include "get_next_me.h"

int main(int argc, char **argv)
{
	int		a;
	char	*me;
	size_t i;

	if(argc < 1)
		return (0);
	a = open(argv[1], O_RDONLY);
	while(get_next_me(a, &me) > 0)
	{
		ft_putstr(me);
		ft_putchar('\n');
		i = +1;
	}
	ft_putnbr(i);
	close(a);
	return (0);
}

