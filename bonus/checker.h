/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkauhane <kkauhane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:04:37 by kkauhane          #+#    #+#             */
/*   Updated: 2024/02/14 14:02:55 by kkauhane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../push_swap.h"

//main
int		in_order(t_stack *a_stack);
t_stack	*initialise(int argc, char *argv[]);

//check input
int		check_input(int argc, char *argv[]);

//operations1
void	swap_a(t_stack *head);
void	swap_b(t_stack *head);
void	swap_a_b(t_stack *a, t_stack *b);
void	push_a(t_stack **src, t_stack **dst);
void	push_b(t_stack **src, t_stack **dst);

//operations2
void	rotate_a(t_stack **stack);
void	rotate_b(t_stack **stack);
void	rotate_a_b(t_stack **a_stack, t_stack **b_stack);

//operations3
void	reverse_rotate_a(t_stack **stack);
void	reverse_rotate_b(t_stack **stack);
void	reverse_rotate_a_b(t_stack **a_stack, t_stack **b_stack);

//help functions
int		abs(int nb);
t_stack	*find_smallest(t_stack **a_stack);
void	final_rotate(t_stack **a_stack);
void	error(t_stack **a_stack, t_stack **b_stack);
void	free_stack(t_stack **the_stack);
int		is_number(char *argv);
void	free_args(char **args);

#endif