#include "./libft/libft.h"
#include "fcntl.h"
#include "get_next_me.h"
#include <stdio.h>

int main(void)
{
	char *me;
	int a;

	a = 0;
	while(get_next_me(a, &me) > 0)
	{
		ft_putstr(me);
	}
	return (0);
}
