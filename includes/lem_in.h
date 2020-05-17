/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 22:27:18 by kcosta            #+#    #+#             */
/*   Updated: 2017/01/16 15:11:03 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#ifndef BUFF_SIZE
# define BUFF_SIZE 32
# endif

# include "libft.h"

typedef unsigned char	t_byte;

typedef struct		s_glob
{
	t_byte			end;
	t_byte			start;
	t_byte			stop;
	unsigned int	count;
	unsigned int	index;
	int				dist;
	int				ants;
}					t_glob;

t_glob				*get_glob(void);
t_list				**get_room(void);
t_list				**get_result(void);
int					***get_path(void);
int					ft_getline(const int fd, char **line);

t_byte				ft_check_room(t_list *list);
t_byte				ft_remove_path(int parent[]);
t_list				*ft_find_room(t_list *room, char *name, t_byte alt);
t_list				*ft_find_name(t_list *room, size_t index);

t_byte				ft_parse(void);
int					ft_solve(int ants, unsigned int c, unsigned int v, int u);
int					ft_strisdigit(const char *str);

#endif
