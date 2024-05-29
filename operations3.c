/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkauhane <kkauhane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:22:57 by kkauhane          #+#    #+#             */
/*   Updated: 2024/02/14 15:42:35 by kkauhane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*tail;
	t_stack	*snd_last;

	tail = lstlast(*stack);
	snd_last = *stack;
	while (snd_last && snd_last->next && snd_last->next->next != NULL)
		snd_last = snd_last->next;
	temp = *stack;
	*stack = tail;
	(*stack)->next = temp;
	snd_last->next = NULL;
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*tail;
	t_stack	*snd_last;

	tail = lstlast(*stack);
	snd_last = *stack;
	while (snd_last && snd_last->next && snd_last->next->next != NULL)
		snd_last = snd_last->next;
	temp = *stack;
	*stack = tail;
	(*stack)->next = temp;
	snd_last->next = NULL;
	ft_printf("rrb\n");
}

void	reverse_rotate_a_b(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*temp;
	t_stack	*tail;
	t_stack	*snd_last;

	tail = lstlast(*a_stack);
	snd_last = *a_stack;
	while (snd_last && snd_last->next && snd_last->next->next != NULL)
		snd_last = snd_last->next;
	temp = *a_stack;
	*a_stack = tail;
	(*a_stack)->next = temp;
	snd_last->next = NULL;
	tail = lstlast(*b_stack);
	snd_last = *b_stack;
	while (snd_last && snd_last->next && snd_last->next->next != NULL)
		snd_last = snd_last->next;
	temp = *b_stack;
	*b_stack = tail;
	(*b_stack)->next = temp;
	snd_last->next = NULL;
	ft_printf("rrr\n");
}
