

#include "lem_in.h"

t_list	*ft_find_name(t_list *room, size_t i)
{
	while (room != NULL)
	{
		if (room->content_size == i)
			return (room);
		room = room->next;
	}
	return (NULL);
}

t_list	*ft_find_room(t_list *room, char *name, t_byte nxt_room)
{
	char		*locate_room;

	locate_room = (nxt_room) ? ft_strsub(name, 0, nxt_room) : ft_strdup(name);
	while (room != NULL)
	{
		if (!ft_strcmp(room->content, locate_room))
		{
			ft_strdel(&locate_room);
			return (room);
		}
		room = room->next;
	}
	ft_strdel(&locate_room);
	return (NULL);
}

t_byte	ft_check_room(t_list *list)
{
	t_list	*cup;

	while (list != NULL)
	{
		cup = list->next;
		while (cup != NULL)
		{
			if (cup->content_size == list->content_size
				|| !ft_strcmp(cup->content, list->content))
				return (1);
			cup = cup->next;
		}
		list = list->next;
	}
	return (0);
}

t_byte	ft_remove_path(int block[])
{
	int		remove;

	remove = get_glob()->count - 1;
	while (block[remove] != -1)
	{
		(*get_path())[remove][block[remove]] = 0;
		(*get_path())[block[remove]][remove] = 0;
		remove = block[remove];
	}
	return (1);
}