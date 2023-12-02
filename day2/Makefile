NAME	= day2_silver
NAME2	= day2_gold
RM		= rm -rf
CC		= cc
CFLAGS	= -Wall -Werror -Wextra

S_SRCS	= silver.c ft_split.c
S_OBJS	= $(S_SRCS:%.c=%.o)

G_SRCS	= gold.c ft_split.c
G_OBJS	= $(G_SRCS:%.c=%.o)

all:	$(NAME) $(NAME2)

silver: $(NAME)

gold:	$(NAME2)

$(NAME): $(S_OBJS)
	$(CC) $(CFLAGS) $(S_OBJS) -o $(NAME)

$(NAME2): $(G_OBJS)
	$(CC) $(CFLAGS) $(G_OBJS) -o $(NAME2)

clean:
	$(RM) $(S_OBJS) $(G_OBJS)

fclean: clean
	$(RM) $(NAME) $(NAME2)

re: fclean all

.PHONY: all clean fclean re test
