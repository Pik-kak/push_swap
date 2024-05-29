/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkauhane <kkauhane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:33:33 by kkauhane          #+#    #+#             */
/*   Updated: 2024/02/14 13:54:49 by kkauhane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include <limits.h>

typedef struct t_list
{
	int				content;
	int				index;
	int				place;
	int				target;
	int				cost_b;
	int				cost_a;
	int				cost;
	struct t_list	*next;
}					t_stack;

//main
int		in_order(t_stack *a_stack);

//check input
int		check_input(int argc, char *argv[]);

//sort
void	sort_three(t_stack **a);
void	sort(t_stack **a_stack, t_stack **b_stack);

//operations1
void	swap_a(t_stack *head);
void	push_a(t_stack **src, t_stack **dst);
void	push_b(t_stack **src, t_stack **dst);

//operations2
void	rotate_a(t_stack **stack);
void	rotate_b(t_stack **stack);
void	rotate_a_b(t_stack **a_stack, t_stack **b_stack);
void	final_rotate(t_stack **a_stack);

//operations3
void	reverse_rotate_a(t_stack **stack);
void	reverse_rotate_b(t_stack **stack);
void	reverse_rotate_a_b(t_stack **a_stack, t_stack **b_stack);

//stack funtions
void	lstadd_front(t_stack **lst, t_stack *new);
int		lstsize(t_stack *lst);
t_stack	*lstlast(t_stack *lst);
void	lstadd_back(t_stack **lst, t_stack *new);
t_stack	*lstnew(int content);

//help functions
int		abs(int nb);
t_stack	*find_smallest(t_stack **a_stack);
void	error(t_stack **a_stack, t_stack **b_stack);
int		is_number(char *argv);
void	free_stack(t_stack **the_stack);
void	free_args(char **args);
int		is_zero(char *argv);

//places and targets
void	put_places(t_stack *the_stack);
void	get_target(t_stack **a_stack, t_stack **b_stack);

//required moves
void	get_cost(t_stack **a_stack, t_stack **b_stack);

#endif
