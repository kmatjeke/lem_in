
#include "lem_in.h"

static int		ft_error(char *str, int fd) //function which prints errors encountered in the program.
{
	ft_putstr_fd(str, 2);
	return (fd);
}

static unsigned char	show_result(int ants, int temp[], int room[], int ant_index)
{
	int			index;

	while (room[ant_index] != -1)	//while every ant has moved at least once.
	{
		if (!temp[room[ant_index]])	
			ant_index = room[ant_index];
		else
		{
			index = temp[room[ant_index]] - 1;	//determines the amount of ants, that have yet to move.
			temp[ant_index] = ((unsigned int)ant_index == start_frame()->count - 1) ? temp[ant_index] + 1 //checks if it's the last ant to move, if it is false it increases the ant index, if
															: temp[room[ant_index]]; 		// it is true it doesn't increase the ant index.
			temp[room[ant_index]] = (room[ant_index] == 0) ? temp[room[ant_index]] - 1 : 0;		
			ft_putstr("L");	//prints 'L' on stdout.
			ft_putnbr(ants - index);	//prints the ant name/index, by minusing index from the total number of ants.
			ft_putchar('-');	//prints '-' on stdout.
			ft_putstr(ft_find_name(*get_room(), ant_index)->content);	//gets and prints the name of the room by passing the nade content to the function ft_find_name.
			
			return (show_result(ants, temp, room, room[ant_index])); //returns this function recursively until there are no more ants to move this turn.
		}
	}
	return (0);
}

static unsigned char	calculate_and_print(int ants, int temp[])
{
	t_list		*move; //creating a t_list variable called move

	if (temp[start_frame()->count - 1] == ants)	//check if the are no more ants moving/busy.
		return (1);		//exit the function if all ants are done.
	move = *get_result();	//creating a list of results, which contains which ants move every turn.
	while (move)
	{
		show_result(ants, temp, move->content, start_frame()->count - 1);	//while this function passes the if statement above. run the show_result function.
		move = move->next; //go to the next move node.
	}
	ft_putchar('\n'); //display a newline after printing every turn.
	return (calculate_and_print(ants, temp));	//return this function recursively after every turn, until it reaches the exit if statement above.
}

int				main(void)
{
	int				*temp;
	unsigned char	check;

	check = ft_parse(); //function which gets data from the map files.
	if (check == 1)
		return (ft_error("\nERROR\n", 2));
	temp = (int*)ft_memalloc(sizeof(int) * start_frame()->count); //allocating the variable *temp memory.
	temp[0] = start_frame()->ants;	//assigning the first index of integer array *temp, the value of the number of ants.
	if (start_frame()->ants <= 0 || ft_check_room(*get_room())) //if the number of ants are lower than 0, or if the is no start or end room.
		return (ft_error("\nERROR\n", 2)); //return error.
	if (ft_solve(start_frame()->ants, -1, -1, 0))	//runs the function ft_solve(which actually solves the map and removes unused paths)and if the function determines that the map is unsolvable.
		return (ft_error("\nERROR\n", 2)); //return error.
	ft_putchar('\n');	//print newline, to separate the return results from the map data.
	(void)calculate_and_print(start_frame()->ants, temp);	//runs calculate_and_print results which actually prints the solution of the map.
	free(temp);	//frees the memory after printing.
	temp = NULL;	//resseting the variable temp to null.
	return (0);	//end of function.
}
