/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkauhane <kkauhane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:38:01 by kkauhane          #+#    #+#             */
/*   Updated: 2024/02/13 12:18:00 by kkauhane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

int	is_number(char *argv)
{
	int	i;

	i = 0;
	if ((argv[i] == 43 || argv[i] == 45) && argv[i + 1] != '\0')
		i++;
	while (argv[i] != '\0' && ft_isdigit(argv[i]) == 1)
		i++;
	if (argv[i] != '\0' && ft_isdigit(argv[i]) == 0)
		return (0);
	return (1);
}

int	is_zero(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == 43 || argv[i] == 45)
		i++;
	while (argv[i] && argv[i] == '0')
		i++;
	if (argv[i] != '\0')
		return (0);
	return (1);
}

t_stack	*find_smallest(t_stack **a_stack)
{
	t_stack	*smallest;
	t_stack	*a_pointer;
	int		stack_size;

	a_pointer = *a_stack;
	smallest = a_pointer;
	stack_size = lstsize(*a_stack);
	while (a_pointer)
	{
		if (a_pointer->index < smallest->index)
			smallest = a_pointer;
		a_pointer = a_pointer->next;
	}
	return (smallest);
}
