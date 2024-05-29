/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_operations2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkauhane <kkauhane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:02:09 by kkauhane          #+#    #+#             */
/*   Updated: 2024/02/14 15:22:03 by kkauhane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rotate_a(t_stack **stack)
{
	t_stack	*last;
	t_stack	*first;

	if (*stack == NULL)
		return ;
	last = lstlast(*stack);
	first = *stack;
	last -> next = first;
	*stack = (*stack)->next;
	first -> next = NULL;
}

void	rotate_b(t_stack **stack)
{
	t_stack	*last;
	t_stack	*first;

	if (*stack == NULL)
		return ;
	last = lstlast(*stack);
	first = *stack;
	last -> next = first;
	*stack = (*stack)->next;
	first -> next = NULL;
}

void	rotate_a_b(t_stack **a_stack, t_stack **b_stack)
{
	rotate_a(a_stack);
	rotate_b(b_stack);
}

void	final_rotate(t_stack **a_stack)
{
	t_stack	*smallest;
	t_stack	*a_pointer;
	int		stack_size;
	int		i;

	a_pointer = *a_stack;
	smallest = find_smallest(a_stack);
	stack_size = lstsize(*a_stack);
	i = smallest->place;
	if (i > stack_size / 2)
	{
		while (i < stack_size)
		{
			reverse_rotate_a(a_stack);
			i++;
		}
	}
	else
	{
		while (i > 0)
		{
			rotate_a(a_stack);
			i--;
		}
	}
}
