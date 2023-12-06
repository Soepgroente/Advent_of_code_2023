NAME	= day6
RM		= rm -rf
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
#CFLAGS += -g3 -fsanitize=address

SRCS	=	adv_utils.c \
			main.c \
			ft_split.c \
			gold.c \
			silver.c \

OBJS	= $(SRCS:%.c=$(OBJDIR)/%.o)
OBJDIR	= advent_objects

all: $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o : %.c
	$(CC) -c $(CFLAGS) -o $@ $^

$(NAME): $(OBJDIR) $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re test
