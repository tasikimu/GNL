#include "get_next_line.h"
#include "./libft/libft.h"

char	*storing(char *str)
{
	static char	*read;

	if (!str)
	{
		if (!read)
			return ((read = ft_strnew(0)));
		return (read);
	}
	if (str)
		return ((read = str));
	return (NULL);
}

int		write_into_line(char *ln, char **line, int eof)
{
	int i;

	if (!ft_strchr(ln, '\n') && !eof)
		return (0);
	i = 0;
	while (ln[i] && ln[i] != '\n')
		i++;
	storing(ft_strdup(&ln[i + 1]));
	*line = ft_strsub(ln, 0, i);
	ft_strdel(&ln);
	return (1);
}

int		readline(const int fd, char **line)
{
	int		rd;
	char	*tmp;
	char	*ln;
	char	buff[BUFF_SIZE + 1];

	ln = storing(NULL);
	if (write_into_line(ln, line, 0))
		return (1);
	while ((rd = read(fd, buff, BUFF_SIZE)))
	{
		if (rd < 0)
			return (-1);
		buff[rd] = 0;
		tmp = ft_strjoin(ln, buff);
		ft_strdel(&ln);
		ln = tmp;
		if (write_into_line(ln, line, 0))
			return (1);
	}
	if (write_into_line(ln, line, 1) && ft_strlen(ln))
		return (1);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	if (!line)
		return (-1);
	return (readline(fd, line));
}
