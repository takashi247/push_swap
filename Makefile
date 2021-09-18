NAME		:= push_swap

CC			:= gcc

CFLAGS		:= -Wall -Wextra -Werror

SRCS		:= push_swap.c

SRCSDIR		:= ./srcs/

SRCS		:= $(addprefix $(SRCSDIR), $(SRCS))

OBJS		:= $(SRCS:.c=.o)

LIBDIR		:= ./libft
LIBPATH		:= $(LIBDIR)/libft.a

INCLUDE		:= -I./include -I./libft/

LIBRARY		:= -L$(LIBDIR) -lft

RM			:= rm -f

# DEBUG 		:=
DEBUG		:= -g

all:		$(NAME)

$(NAME):	$(OBJS) $(LIBPATH)
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDE) $^ $(LIBRARY) -o $@

.c.o:
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDE) -c $< -o $@

$(LIBPATH):
	$(MAKE) plus -C $(LIBDIR)

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C $(LIBDIR)

fclean:		clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBDIR)

re:			fclean all

bonus:		all

.PHONY:		all clean fclean re bonus