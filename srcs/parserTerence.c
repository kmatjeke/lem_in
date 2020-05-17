#include "lem_in.h"

static unsigned char	ft_check_command(char *str) {
    if (!ft_strcmp("##start", str))
        start_frame()->start=1;
    else {
        if (!ft_strcmp("##end", str))
            start_frame()->end =1;
        else
            return 0;
    }
    return !(!start_frame()->start || !start_frame()->end);
}

static unsigned char	ft_check_format(char *str) {
    int i;

    i = 1;
    if (!ft_strstr(str, " "))
		return (i);

    if (start_frame()->stop)
        return (i);

    while (*str != ' ')
		str++;
	str++;
	i++;
	if (!ft_isdigit(*str))
		return (i);
	while (ft_isdigit(*str))
		str++;
	str++;
	i++;
	if (!ft_isdigit(*str))
		return (i);
    if (!*str)
        return (i);

    while (ft_isdigit(*str))
		str++;
    str++;
	return (0);
}

static unsigned char	ft_add_room(char *str) {
	char *room;

	if (ft_check_format(str))
		return (1);
	room = ft_strsub(str, 0, ft_strstr(str, " ") - str);
	ft_lstadd(get_room(), ft_lstnew(room, ft_strlen(room) + 1));
	if (start_frame()->start)
        (*get_room())->content_size = 0;
	else
        (*get_room())->content_size = start_frame()->index;
	if (start_frame()->end)
        (*get_room())->content_size = (size_t)-1;
	else
        (*get_room())->content_size = (*get_room())->content_size;
    start_frame()->index = start_frame()->index + !(start_frame()->start || start_frame()->end);
	start_frame()->count = start_frame()->count + 1;
    if ((start_frame()->start))
        start_frame()->start = 0;
    if ((start_frame()->end))
        start_frame()->end = 0;

    free(room);
	return (0);
}

static unsigned char	ft_add_path(char *str) {
	t_list *list[2];

	start_frame()->stop = 1;
	list[0] = ft_find_room(*get_room(), str, ft_strstr(str, "-") - str);
	list[1] = ft_find_room(*get_room(), ft_strstr(str, "-") + 1, 0);
	if (!(list[0] && list[1]))
		return (1);
	if (list[0]->content_size == (size_t)-1)
		list[0]->content_size = start_frame()->index;
	else if (list[1]->content_size == (size_t)-1)
		list[1]->content_size = start_frame()->index;
    (*get_path())[list[0]->content_size][list[1]->content_size] = 1;
	(*get_path())[list[1]->content_size][list[0]->content_size] = (*get_path())[list[0]->content_size][list[1]->content_size];
	return (0);
}

unsigned char			ft_parse() {
	char	*str;
	unsigned char check;

	if (ft_getline(0, &str) < 1)
		return (1);
	ft_putstr(str);
	ft_putchar('\n');
	if (ft_isnums(str))
	    check = 0;
	else
	    check = 1;
	start_frame()->ants = ft_atoi(str);
	free(str);
	while (ft_getline(0, &str) >= 1) {
        ft_putstr(str);
        ft_putchar('\n');
		if (!(check || *str != '#'))
			check = ft_check_command(str);
		else if (!(check || !ft_strstr(str, "-")))
			check = ft_add_path(str);
		else if (!(check || *str == 'L'))
			check = ft_add_room(str);
		else
			check = 1;
		free(str);
	}
	free(str);
	return (check);
}
