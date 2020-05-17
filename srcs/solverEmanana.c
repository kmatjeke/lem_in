
#include "lem_in.h"
#include <limits.h>

// ft_get_shortest_path.
static int		ft_shortest_path(int dist[], int visited[])
{
	int				min_dist;
	int				min_index;
	unsigned int	v_index;

	min_dist = INT_MAX;
	v_index = 0; // index to iterate through the visited array
	while (get_glob()->count > v_index)
	{
		// find closest vertex(node) and set its distance as the shortest distance
		if (!visited[v_index] && dist[v_index] <= min_dist)
		{
			min_dist = dist[v_index];
			min_index = v_index;
		}
		v_index++;
	}
	return (min_index); // return distance of the closet room from the start room.
}

// initialise the table. ft_init_solver
static t_byte	ft_initialise_solver(int (*dist)[], int (*visited)[], int (*source)[])
{
	unsigned int	i;

	i = 0;
	while (get_glob()->count > i)
	{
		//assume all unvsited nodes to an infinite distance.
		(*dist)[i] = INT_MAX;
		// flag all to unvisted nodes to false.
		(*visited)[i] = 0;
		(*source)[0] = -1;
		i++;
	}
	(*dist)[0] = 0;
	return (0);
}

// change ft_solve to ft_dijskras_path
int				ft_solve(int ants, unsigned int c, unsigned int v_index, int short_path)
{
	int				dist[get_glob()->count];
	int				visited[get_glob()->count];
	int				source[get_glob()->count];

	(void)ft_initialise_solver(&dist, &visited, &source);
	while (++c < get_glob()->count - 1)
	{
		v_index = -1;
		short_path = ft_shortest_path(dist, visited);
		visited[short_path] = 1; //mark the visited["shortest path index(node/vertex)"]
		while (++v_index < get_glob()->count)
			if (!visited[v_index] && (*get_path())[short_path][v_index] && dist[short_path] != INT_MAX
							&& dist[short_path] + (*get_path())[short_path][v_index] < dist[v_index])
			{
				source[v_index] = short_path; // make this the new source(start room) vertex from the start room(vertex)
				dist[v_index] = dist[short_path] + (*get_path())[short_path][v_index]; // set current index to the recent shortest path
			}
	}
	if (get_glob()->dist < dist[get_glob()->count - 1]
						|| dist[get_glob()->count - 1] == INT_MAX)
		return (get_glob()->dist == INT_MAX);
	get_glob()->dist = dist[get_glob()->count - 1];
	ft_lstadd(get_result(), ft_lstnew(source, sizeof(source))); // and the new closet node(vertex) to the path.
	(void)ft_remove_path((*get_result())->content); // free the path, for a new found one.
	return (ft_solve(ants, -1, -1, 0)); // reset and repeat
}
