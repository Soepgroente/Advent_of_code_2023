NAME	= day1
RM		= rm -rf
CC		= cc
CFLAGS	= -Wall -Werror -Wextra
#CFLAGS	+= -g -fsanitize=address
SRCS	= 	main.c ft_split.c
OBJS	= $(SRCS:*.c=*.o)

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re test
