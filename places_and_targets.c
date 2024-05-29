/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   places_and_targets.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkauhane <kkauhane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:43:53 by kkauhane          #+#    #+#             */
/*   Updated: 2024/02/05 16:58:24 by kkauhane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_target_place(t_stack **a, int b_idx, int t_idx, int t_place)
{
	t_stack	*tmp_a;

	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index > b_idx && tmp_a->index < t_idx)
		{
			t_idx = tmp_a->index;
			t_place = tmp_a->place;
		}
		tmp_a = tmp_a->next;
	}
	if (t_idx != INT_MAX)
		return (t_place);
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index < t_idx)
		{
			t_idx = tmp_a->index;
			t_place = tmp_a->place;
		}
		tmp_a = tmp_a->next;
	}
	return (t_place);
}

void	put_places(t_stack *the_stack)
{
	int		i;
	t_stack	*pointer;

	i = 0;
	pointer = the_stack;
	while (pointer)
	{
		pointer -> place = i;
		pointer = pointer -> next;
		i++;
	}
}

void	get_target(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*b_pointer;
	int		target;

	b_pointer = *b_stack;
	target = 0;
	put_places(*a_stack);
	put_places(*b_stack);
	while (b_pointer)
	{
		target = get_target_place(a_stack, b_pointer->index, INT_MAX, target);
		b_pointer -> target = target;
		b_pointer = b_pointer -> next;
	}
}
