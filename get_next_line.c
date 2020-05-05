#include "get_next_me.h"
#include "./libft/libft.h"

int	get_next_me(const int a, char **me)
{
	static char	*p[2147483647];
	char		buffersize[BUFF_SIZE + 1];
	char		*temp;
	ssize_t		i;
	int			line_end;

	if (a < 0 || (!p[a] && !(p[a] = ft_strnew(1))) || !me)
		return (-1);
	while (!ft_strchr(p[a], '\n') && (i = read(a, buffersize, BUFF_SIZE)) > 0)
	{
		buffersize[i] = '\0';
		temp = p[a];
		p[a] = ft_strjoin(p[a], buffersize);
		ft_strdel(&temp);
	}
	if (i == -1 || !*(temp = p[a]))
		return (i == -1 ? -1 : 0);
	if ((line_end = (ft_strchr(p[a], '\n') > 0)))
		*me = ft_strsub(p[a], 0, ft_strchr(p[a], '\n') - p[a]);
	else
		*me = ft_strdup(p[a]);
	p[a] = ft_strsub(p[a], (unsigned int)(ft_strlen(*me) + line_end),
			(size_t)(ft_strlen(p[a]) - (ft_strlen(*me) + line_end)));
	ft_strdel(&temp);
	return (!(!p[a] && !ft_strlen(*me)));
}
