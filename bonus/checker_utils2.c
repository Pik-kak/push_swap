/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkauhane <kkauhane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:47:44 by kkauhane          #+#    #+#             */
/*   Updated: 2024/02/14 13:53:32 by kkauhane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	error(t_stack **a_stack, t_stack **b_stack)
{
	write(2, "Error\n", 6);
	free_stack(a_stack);
	free_stack(b_stack);
	exit (1);
}

void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	free_stack(t_stack **the_stack)
{
	t_stack	*head;
	t_stack	*temp;

	head = *the_stack;
	while (head)
	{
		temp = head;
		head = head -> next;
		free(temp);
	}
	*the_stack = NULL;
}
