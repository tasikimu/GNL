#include "get_next_line.h"
#include "./libft/libft.h"

int	get_next_line(const int a, char **me)
{
	static char	*ptr[2147483647];
	char		buffersize[BUFF_SIZE + 1];
	char		*temp;
	ssize_t		i;
	int			line_end;

	if (a < 0 || (!ptr[a] && !(ptr[a] = ft_strnew(1))) || !me)
		return (-1);
	while (!ft_strchr(ptr[a], '\n') && (i = read(a, buffersize, BUFF_SIZE)) > 0)
	{
		buffersize[i] = '\0';
		temp = ptr[a];
		ptr[a] = ft_strjoin(ptr[a], buffersize);
		ft_strdel(&temp);
	}
	if (i == -1 || !*(temp = ptr[a]))
		return (i == -1 ? -1 : 0);
	if ((line_end = (ft_strchr(ptr[a], '\n') > 0)))
		*me = ft_strsub(ptr[a], 0, ft_strchr(ptr[a], '\n') - ptr[a]);
	else
		*me = ft_strdup(ptr[a]);
	ptr[a] = ft_strsub(ptr[a], (unsigned int)(ft_strlen(*me) + line_end),
			(size_t)(ft_strlen(ptr[a]) - (ft_strlen(*me) + line_end)));
	ft_strdel(&temp);
	return (!(!ptr[a] && !ft_strlen(*me)));
}
