NAME	= silver_day3
NAME2	= gold_day3
RM		= rm -rf
CC		= cc
CFLAGS	= -Wall -Werror -Wextra

SRCS	= ft_split.c
OBJS	= $(SRCS:%.c=%.o)

S_SRCS	= silver.c
S_OBJS	= $(S_SRCS:%.c=%.o)

G_SRCS	= gold.c
G_OBJS	= $(G_SRCS:%.c=%.o)

all:	silver gold

silver: $(NAME)

gold:	$(NAME2)

$(NAME): $(OBJS) $(S_OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(S_OBJS) -o $(NAME)

$(NAME2): $(OBJS) $(G_OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(G_OBJS) -o $(NAME2)

%.o : %.c
	$(CC) -c $(CFGLAGS) $@ $^

clean:
	$(RM) $(OBJS) $(S_OBJS) $(G_OBJS)

fclean: clean
	$(RM) $(NAME) $(NAME2)

re: fclean all

.PHONY: all clean fclean re test
