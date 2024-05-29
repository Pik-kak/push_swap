/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkauhane <kkauhane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:58:09 by kkauhane          #+#    #+#             */
/*   Updated: 2024/02/14 15:16:06 by kkauhane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_printf("ra\n");
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
	ft_printf("rb\n");
}

void	rotate_a_b(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*last;
	t_stack	*first;

	if (*a_stack != NULL)
	{
		last = lstlast(*a_stack);
		first = *a_stack;
		last -> next = first;
		*a_stack = (*a_stack)->next;
		first -> next = NULL;
	}
	if (*b_stack != NULL)
	{
		last = lstlast(*b_stack);
		first = *b_stack;
		last -> next = first;
		*b_stack = (*b_stack)->next;
		first -> next = NULL;
	}
	ft_printf("rr\n");
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
