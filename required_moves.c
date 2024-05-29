/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   required_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkauhane <kkauhane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:44:48 by kkauhane          #+#    #+#             */
/*   Updated: 2024/02/05 18:08:47 by kkauhane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_to_front(t_stack **the_stack, int cost, int nbr)
{
	if (cost < 0)
	{
		while (cost < 0)
		{
			if (nbr == 1)
				reverse_rotate_a(the_stack);
			if (nbr == 2)
				reverse_rotate_b(the_stack);
			cost++;
		}
	}
	else
	{
		while (cost > 0)
		{
			if (nbr == 1)
				rotate_a(the_stack);
			if (nbr == 2)
				rotate_b(the_stack);
			cost--;
		}
	}
}

static void	rotate_stacks(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
	{
		while (cost_a < 0 && cost_b < 0)
		{
			cost_a++;
			cost_b++;
			reverse_rotate_a_b(a, b);
		}
	}
	else if (cost_a > 0 && cost_b > 0)
	{
		while (cost_a > 0 && cost_b > 0)
		{
			cost_a--;
			cost_b--;
			rotate_a_b(a, b);
		}
	}
	move_to_front(b, cost_b, 2);
	move_to_front(a, cost_a, 1);
}

static void	get_cheapest(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*b_pointer;
	int		cheapest_cost;
	int		a_cost;
	int		b_cost;

	b_pointer = *b_stack;
	cheapest_cost = INT_MAX;
	while (b_pointer)
	{
		if (b_pointer->cost < cheapest_cost)
		{
			cheapest_cost = b_pointer->cost;
			a_cost = b_pointer->cost_a;
			b_cost = b_pointer->cost_b;
		}
		b_pointer = b_pointer->next;
	}
	rotate_stacks(a_stack, b_stack, a_cost, b_cost);
}

void	get_cost(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*b_pointer;
	t_stack	*a_pointer;

	b_pointer = *b_stack;
	a_pointer = *a_stack;
	while (b_pointer)
	{
		b_pointer->cost_b = b_pointer->place;
		if (b_pointer->place > lstsize(*b_stack) / 2)
			b_pointer->cost_b = (lstsize(*b_stack) - b_pointer->place) * -1;
		b_pointer->cost_a = b_pointer->target;
		if (b_pointer->target > lstsize(*a_stack) / 2)
			b_pointer->cost_a = (lstsize(*a_stack) - b_pointer->target) * -1;
		b_pointer->cost = abs(b_pointer->cost_b) + abs(b_pointer->cost_a);
		b_pointer = b_pointer->next;
	}
	get_cheapest(a_stack, b_stack);
}
