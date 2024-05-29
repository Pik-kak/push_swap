/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_operations3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkauhane <kkauhane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:02:35 by kkauhane          #+#    #+#             */
/*   Updated: 2024/02/14 15:42:18 by kkauhane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	reverse_rotate_a(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*tail;
	t_stack	*snd_last;

	if (*stack == NULL)
		return ;
	tail = lstlast(*stack);
	snd_last = *stack;
	while (snd_last && snd_last->next && snd_last->next->next != NULL)
		snd_last = snd_last->next;
	temp = *stack;
	*stack = tail;
	(*stack)->next = temp;
	snd_last->next = NULL;
}

void	reverse_rotate_b(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*tail;
	t_stack	*snd_last;

	if (*stack == NULL)
		return ;
	tail = lstlast(*stack);
	snd_last = *stack;
	while (snd_last && snd_last->next && snd_last->next->next != NULL)
		snd_last = snd_last->next;
	temp = *stack;
	*stack = tail;
	(*stack)->next = temp;
	snd_last->next = NULL;
}

void	reverse_rotate_a_b(t_stack **a_stack, t_stack **b_stack)
{
	reverse_rotate_a(a_stack);
	reverse_rotate_b(b_stack);
}
