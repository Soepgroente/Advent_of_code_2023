NAME	= day4
RM		= rm -rf
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
#CFLAGS += -g3 -fsanitize=address

SRCS	=	main.c \
			ft_split.c \
			gold.c \
			silver.c \

OBJS	= $(SRCS:%.c=%.o)

all: $(NAME)

%.o : %.c
	$(CC) -c $(CFLAGS) -o $@ $^

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re test
