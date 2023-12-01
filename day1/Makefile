NAME	= day1
RM		= rm -rf
CC		= cc
CFLAGS	= -Wall -Werror -Wextra
SRCS	= 	main.c ft_split.c

all:	$(NAME)

$(NAME): 
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re test
