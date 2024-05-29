/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkauhane <kkauhane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:57:26 by kkauhane          #+#    #+#             */
/*   Updated: 2024/02/14 15:01:17 by kkauhane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_printf("sa\n");
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
	ft_printf("pa\n");
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
	ft_printf("pb\n");
}
