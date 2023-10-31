
CC= cc
CFLAGS= -Wall -Wextra -Werror

RM = rm -f

LIB= ar rc
NAME= get_next_line
HEADER= get_next_line.h

SRCS=	ft_get_next_line.c \
		get_next_line_utils.c \

OBJS=		$(SRCS:.c=.o)
%.o:%.c		$(HEADER) Makefile
			$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			$(LIB) $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: 	all clean fclean re