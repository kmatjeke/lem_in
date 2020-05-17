
#ifndef LEM_IN_H
# define LEM_IN_H

#ifndef BUFF_SIZE
# define BUFF_SIZE 32
# endif

# include "libft.h"


typedef struct		s_frame
{
	unsigned char	end;
	unsigned char	start;
	unsigned char	stop;
	unsigned int	count;
	unsigned int	index;
	int				dist;
	int				ants;
}					t_frame;

t_frame				*start_frame(void);
t_list				**get_room(void);
t_list				**get_result(void);
int					***get_path(void);
int					ft_getline(const int fd, char **line);

unsigned char		ft_check_room(t_list *list);
unsigned char		ft_remove_path(int parent[]);
t_list				*ft_find_room(t_list *room, char *name, unsigned char alt);
t_list				*ft_find_name(t_list *room, size_t index);

unsigned char		ft_parse(void);
int					ft_solve(int ants, unsigned int c, unsigned int v, int u);
int					ft_isnums(const char *str);

#endif
