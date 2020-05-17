
#include "lem_in.h"
#include <limits.h>

t_glob		*get_glob(void)
{
	static t_glob	frame = {0, 0, 0, 0, 1, INT_MAX, 0};

	return (&frame);
}
//passing starting values to the struct s_frame in lem_in.h

t_list		**get_room(void)
{
	static t_list	*rooms = NULL;

	return (&rooms);
}
//creating a room linked list, using the struct t_list from my libft

t_list		**get_result(void)
{
	static t_list	*result = NULL;

	return (&result);
}
//creating a result linked list, using the struct t_list from my libft

int			***get_path(void)
{
	static int		**path = NULL;  //creating a 2 dimensional integer array. and initialising it to NULL
	unsigned int	i;

	if (path == NULL)
	{
		path = (int**)ft_memalloc(sizeof(int*) * get_glob()->count); //allocating memory for the whole 2 dimensional array.
		i = 0;
		while (i < get_glob()->count)
			path[i++] = (int*)ft_memalloc(sizeof(int) * get_glob()->count); //allocating memory for each node/index in the 2d array.
	}
	return (&path);	//return the 2 dimensional integer array, with memory already allocated to it
}
//functions to allocate memory for the paths. and returning the allocated memory.
