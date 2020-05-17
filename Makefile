
CC = gcc
FLAGS = -Wall -Wextra -Werror -g
LIBFT = libft/
LIB = -L $(LIBFT) -lft
NAME = lem-in
SRCS_PATH = srcs/
INCLUDES_PATH = includes/
INCLUDES = -I includes/ -I libft/

FILES = lem_in.c \
		create_lists.c \
		parserTerence.c \
		utilities.c \
		solverEmanana.c \
		is_nums.c \
		ft_getlineNkholane.c
SRCS = $(addprefix $(SRCS_PATH), $(FILES))
OBJS = $(SRCS:.c=.o)

all: lib $(NAME)

lib :
	git submodule init
	git submodule update --remote
	@make -C $(LIBFT)

%.o: %.c
	@/bin/echo -n Compiling $(notdir $@) ...
	@$(CC) $(FLAGS) $(INCLUDES) -c -o $@ $<
	@echo "Done!"

$(NAME): $(OBJS)
	@/bin/echo Creating $(NAME) ...
	@$(CC) $(FLAGS) -o $(NAME) $(INCLUDES) $(OBJS) $(LIB)
	@/bin/echo "$(NAME) Created!"

clean:
	@/bin/echo "Cleaning ..."
	@/bin/rm -f $(OBJS)
	@make -C $(LIBFT) clean
	@/bin/echo "All .o Removed!"

fclean: clean
	@make -C $(LIBFT) fclean 
	@/bin/rm -f $(NAME)
	@/bin/echo "$(NAME) Removed!"

re: fclean all
