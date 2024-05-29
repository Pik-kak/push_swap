/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkauhane <kkauhane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 12:10:52 by kkauhane          #+#    #+#             */
/*   Updated: 2024/02/13 12:17:13 by kkauhane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	t_stack	*last;

	last = lstlast(*a);
	if (in_order(*a) == 1)
		return ;
	if ((*a)->index < (*a)->next->index && (*a)->index < last->index \
		&& (*a)->next->index > last->index)
	{
		swap_a(*a);
		rotate_a(a);
	}
	else if ((*a)->index > (*a)->next->index && (*a)->index < last->index)
		swap_a((*a));
	else if ((*a)->index < (*a)->next->index && (*a)->index > last->index)
		reverse_rotate_a(a);
	else if ((*a)->index > (*a)->next->index && last->index > (*a)->next->index)
		rotate_a(&(*a));
	else if ((*a)->index > (*a)->next->index && (*a)->index > last->index)
	{
		swap_a(*a);
		reverse_rotate_a(a);
	}
}

static void	keep_three(t_stack **a_stack, t_stack **b_stack)
{
	int	a_stack_size;
	int	b_stack_size;
	int	i;

	a_stack_size = lstsize(*a_stack);
	b_stack_size = 0;
	i = 0;
	while (a_stack_size > i && lstsize(*a_stack) > 3)
	{
		if ((*a_stack)->index <= a_stack_size / 2)
		{
			push_b(a_stack, b_stack);
			b_stack_size++;
		}
		else
			rotate_a(a_stack);
		i++;
	}
	while (lstsize(*a_stack) > 3)
	{
		push_b(a_stack, b_stack);
		b_stack_size++;
	}
}

void	sort(t_stack **a_stack, t_stack **b_stack)
{
	keep_three(a_stack, b_stack);
	sort_three(a_stack);
	while (*b_stack)
	{
		get_target(a_stack, b_stack);
		get_cost(a_stack, b_stack);
		push_a(b_stack, a_stack);
	}
	put_places(*a_stack);
	final_rotate(a_stack);
}
