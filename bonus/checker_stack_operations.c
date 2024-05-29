/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_stack_operations.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkauhane <kkauhane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:00:50 by kkauhane          #+#    #+#             */
/*   Updated: 2024/02/14 11:45:07 by kkauhane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	lstadd_front(t_stack **lst, t_stack *new)
{
	if (!lst)
	{
		*lst = lstnew(new->content);
	}
	else
	{
		new -> next = *lst;
		lst = &new;
	}
}

int	lstsize(t_stack *lst)
{
	t_stack	*current;
	int		size;

	current = lst;
	size = 0;
	while (current != NULL)
	{
		size++;
		current = current -> next;
	}
	return (size);
}

t_stack	*lstlast(t_stack *lst)
{
	while (lst != NULL)
	{
		if (lst -> next == NULL)
			return (lst);
		lst = lst -> next;
	}
	return (0);
}

void	lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (lst)
	{
		last = lstlast(*lst);
		last -> next = new;
		new -> next = NULL;
		return ;
	}
	*lst = new;
}

t_stack	*lstnew(int content)
{
	t_stack	*newstack;

	newstack = (t_stack *)malloc(sizeof(t_stack));
	if (newstack == 0)
	{
		write(2, "Error\n", 6);
		exit (1);
	}
	newstack -> content = content;
	newstack -> index = 0;
	newstack -> place = 0;
	newstack -> target = 0;
	newstack -> cost_b = 0;
	newstack -> cost_a = 0;
	newstack -> cost = 0;
	newstack -> next = NULL;
	return (newstack);
}
