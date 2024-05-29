# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkauhane <kkauhane@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 13:34:28 by kkauhane          #+#    #+#              #
#    Updated: 2024/02/14 15:32:18 by kkauhane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFTNAME = libft.a

LIBFTDIR = ./libft

SRCS = push_swap.c help_functions1.c help_functions2.c operations1.c operations2.c operations3.c sort.c stack_functions.c places_and_targets.c required_moves.c check_input.c
BONUS = ./bonus/checker.c ./bonus/checker_operations1.c ./bonus/checker_operations2.c ./bonus/checker_input.c ./bonus/checker_operations3.c ./bonus/checker_utils1.c ./bonus/checker_utils2.c ./bonus/checker_stack_operations.c

CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)
BOBJS = $(BONUS:.c=.o)

all: $(NAME)

makelibft:
	@make -C $(LIBFTDIR)
	@cp $(LIBFTDIR)/$(LIBFTNAME) .
	@mv $(LIBFTNAME) $(NAME)

$(NAME): makelibft bonus $(OBJS)
	@ar -r $(NAME) $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFTDIR) -lft

bonus : .bonuss

.bonuss: $(BOBJS) $(OBJS)
	$(CC) $(CFLAGS) $(BOBJS) $(LIBFTDIR)/$(LIBFTNAME) -o checker
	touch .bonuss

clean:
	@rm -f $(OBJS) $(BOBJS) .bonuss
	@cd $(LIBFTDIR) && make clean
	
fclean: clean
	@rm -f $(NAME)
	@cd $(LIBFTDIR) && make fclean
	$(RM) push_swap
	$(RM) checker
	
re: fclean all

.PHONY: all bonus clean fclean re