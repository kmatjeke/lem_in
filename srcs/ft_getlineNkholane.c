#include "lem_in.h"

int			ft_getline(const int fd, char **line)
{
	char	buff[BUFF_SIZE];
	char	*new;
	char	*temp;
	int		result;

	new = ft_strnew(0);
	while ((result = read(fd, buff, 1)) > 0)
	{
		buff[1] = 0;
		if (!ft_strcmp(buff, "\n"))
			break ;
		temp = new;
		new = ft_strjoin(new, buff);
		free(temp);
	}
	*line = ft_strdup(new);
	free(new);
	return (result);
}



// int	ft_getline(const int fd, char **line)
// {
// 	char	*buff;
// 	char	*temp;
// 	int		res;

// 	if (!(buff = ft_strnew(sizeof(char) * 2 + 1)))
// 		return (-1);
// 	res = read(fd, buff, 2);
// 	if (res > 0)
// 	{
// 		buff[res] = '\0';
// 		temp = ft_strjoin(*line, buff);
// 		if (!temp)
// 			return (-1);
// 		free(*line);
// 		*line = temp;
// 	}
// 	free(buff);
// 	return (res);
// }
