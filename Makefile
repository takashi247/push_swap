NAME		:= push_swap

CC			:= gcc

CFLAGS		:= -Wall -Wextra -Werror

SRCS		:= push_swap.c \
				sort_stack.c \
				swap.c \
				rotate.c \
				rev_rotate.c \
				push.c \
				sort_two.c \
				sort_three.c \
				sort_five.c \
				sort_utils.c \
				sort_four.c \
				convert_to_index.c \
				sort_more.c \
				action_utils.c \
				sort_utils_2.c \
				clear_base.c \
				clear_sub.c \
				initialize_sub.c \
				search_next_min.c \
				rotate_n_keep.c \
				reset_stack_position.c \
				halve_stack.c \
				is_added_to_batch.c \
				main_utils.c

SRCSBONUS	:= checker.c \
				get_next_line.c \
				main_utils.c \
				swap.c \
				push.c \
				convert_to_index.c \
				action_utils.c \
				sort_utils_2.c \
				checker_utils.c \
				do_instruction.c

SRCSDIR		:= srcs/

OBJSDIR		:= objs/

OBJS		:= $(addprefix $(OBJSDIR), $(SRCS:.c=.o))

OBJSBONUS	:= $(addprefix $(OBJSDIR), $(SRCSBONUS:.c=.o))

LIBDIR		:= ./libft
LIBPATH		:= $(LIBDIR)/libft.a

INCLUDE		:= -I./include -I./libft/

LIBRARY		:= -L$(LIBDIR) -lft

RM			:= rm -rf

DEBUG		:= -fsanitize=address -g

CHECKER		:= checker

all:		$(NAME)

$(NAME):	$(OBJS) $(LIBPATH)
	$(CC) $(CFLAGS) $(INCLUDE) $^ $(LIBRARY) -o $@

$(CHECKER):	$(OBJSBONUS) $(LIBPATH)
	$(CC) $(CFLAGS) $(INCLUDE) $^ $(LIBRARY) -o $@

$(OBJSDIR)%.o: $(SRCSDIR)%.c
	@if [ ! -d $(OBJSDIR) ]; then mkdir $(OBJSDIR); fi
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(LIBPATH):
	$(MAKE) plus -C $(LIBDIR)

bonus:		$(CHECKER)

clean:
	$(RM) $(OBJSDIR)
	$(MAKE) clean -C $(LIBDIR)
	$(RM) -rf *.dSYM

fclean:		clean
	$(RM) $(NAME) $(CHECKER)
	$(MAKE) fclean -C $(LIBDIR)

re:			fclean all

debug:		CFLAGS += $(DEBUG)
debug:		re

debug_bonus:	CFLAGS += $(DEBUG)
debug_bonus:	re bonus

.PHONY:		all clean fclean re bonus debug debug_bonus