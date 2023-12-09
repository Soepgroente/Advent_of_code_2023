NAME	= day9
RM		= rm -rf
CC		= cc
CFLAGS	= -Wall -Werror -Wextra
#CFLAGS += -g3 -fsanitize=address

SRCS	=	adv_utils.c \
			main.c \
			ft_split.c \
			silver.c \
			gold.c \

OBJS	= $(SRCS:%.c=$(OBJDIR)/%.o)
OBJDIR	= advent_objects

all: $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o : %.c
	$(CC) -c $(CFLAGS) -o $@ $^

$(NAME): $(OBJDIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re test
