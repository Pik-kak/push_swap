/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_operations1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkauhane <kkauhane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:01:40 by kkauhane          #+#    #+#             */
/*   Updated: 2024/02/14 15:40:19 by kkauhane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap_a(t_stack *head)
{
	int	temp;

	if (!head || head->next == NULL)
		return ;
	temp = head->content;
	head->content = head->next->content;
	head->next->content = temp;
	temp = head->index;
	head->index = head->next->index;
	head->next->index = temp;
}

void	swap_b(t_stack *head)
{
	int	temp;

	if (!head || head->next == NULL)
		return ;
	temp = head->content;
	head->content = head->next->content;
	head->next->content = temp;
	temp = head->index;
	head->index = head->next->index;
	head->next->index = temp;
}

void	swap_a_b(t_stack *a, t_stack *b)
{
	swap_a(a);
	swap_b(b);
}

void	push_a(t_stack **src, t_stack **dst)
{
	t_stack	*temp;

	temp = (*src)->next;
	if (*src == NULL)
		return ;
	(*src)->next = *dst;
	*dst = *src;
	*src = temp;
}

void	push_b(t_stack **src, t_stack **dst)
{
	t_stack	*temp;

	temp = (*src)->next;
	if (*src == NULL)
		return ;
	(*src)->next = *dst;
	*dst = *src;
	*src = temp;
}
