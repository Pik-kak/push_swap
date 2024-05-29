/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkauhane <kkauhane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:33:25 by kkauhane          #+#    #+#             */
/*   Updated: 2024/02/14 14:09:56 by kkauhane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	in_order(t_stack *a_stack)
{
	t_stack	*pointer;

	pointer = a_stack;
	while (pointer && pointer -> next)
	{
		if (pointer -> content > pointer-> next -> content)
			return (0);
		pointer = pointer -> next;
	}
	return (1);
}

static void	index_stack(t_stack *a_stack, int stack_size)
{
	t_stack	*pointer;
	t_stack	*highest;
	int		i;

	while (stack_size > 0)
	{
		pointer = a_stack;
		highest = NULL;
		i = INT_MIN;
		while (pointer)
		{
			if (pointer -> index == 0 && pointer -> content > i)
			{
				i = pointer -> content;
				highest = pointer;
				pointer = a_stack;
			}
			else
				pointer = pointer -> next;
		}
		if (highest != NULL)
			highest -> index = stack_size;
		stack_size--;
	}
}

static t_stack	*initialise(int argc, char *argv[])
{
	t_stack		*a_stack;
	char		**args;
	int			i;

	a_stack = NULL;
	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		args = argv;
		i = 1;
	}
	while (args[i])
	{
		if (a_stack == NULL)
			a_stack = lstnew(ft_atoi(args[i]));
		else
			lstadd_back(&a_stack, lstnew(ft_atoi(args[i])));
		i++;
	}
	if (argc == 2)
		free_args(args);
	return (a_stack);
}

static void	push_swap(t_stack **a_stack, t_stack **b_stack)
{
	int	stack_size;

	stack_size = lstsize(*a_stack);
	if (in_order(*a_stack) == 1)
		return ;
	index_stack(*a_stack, stack_size);
	if (stack_size == 2)
		swap_a(*a_stack);
	else if (stack_size == 3)
		sort_three(a_stack);
	else
		sort(a_stack, b_stack);
}

int	main(int argc, char *argv[])
{
	t_stack	*a_stack;
	t_stack	*b_stack;

	if (argc < 2)
		return (0);
	b_stack = NULL;
	a_stack = NULL;
	if (check_input(argc, argv) == 0)
		error(&a_stack, &b_stack);
	a_stack = initialise(argc, argv);
	push_swap(&a_stack, &b_stack);
	free_stack(&a_stack);
	free_stack(&b_stack);
}
