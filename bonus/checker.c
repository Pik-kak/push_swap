/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkauhane <kkauhane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:59:54 by kkauhane          #+#    #+#             */
/*   Updated: 2024/02/14 14:02:41 by kkauhane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	print_message(char *message)
{
	ft_putendl_fd(message, 1);
}

void	execute_command(t_stack **a, t_stack **b, char *command)
{
	if (ft_strncmp(command, "sa\n", 3) == 0)
		swap_a(*a);
	else if (ft_strncmp(command, "sb\n", 3) == 0)
		swap_b(*b);
	else if (ft_strncmp(command, "ss\n", 3) == 0)
		swap_a_b(*a, *b);
	else if (ft_strncmp(command, "pa\n", 3) == 0)
		push_a(b, a);
	else if (ft_strncmp(command, "pb\n", 3) == 0)
		push_b(a, b);
	else if (ft_strncmp(command, "ra\n", 3) == 0)
		rotate_a(a);
	else if (ft_strncmp(command, "rb\n", 3) == 0)
		rotate_b(b);
	else if (ft_strncmp(command, "rr\n", 3) == 0)
		rotate_a_b(a, b);
	else if (ft_strncmp(command, "rra\n", 4) == 0)
		reverse_rotate_a(a);
	else if (ft_strncmp(command, "rrb\n", 4) == 0)
		reverse_rotate_b(b);
	else if (ft_strncmp(command, "rrr\n", 4) == 0)
		reverse_rotate_a_b(a, b);
	else
		error(a, b);
}

void	checker(t_stack **a_stack, t_stack **b_stack)
{
	char	*command;

	while (1)
	{
		command = get_next_line(STDIN_FILENO);
		if (command == NULL)
			break ;
		execute_command(a_stack, b_stack, command);
	}
	if (in_order(*a_stack))
		print_message("OK");
	else
		print_message("KO");
}

t_stack	*initialise(int argc, char *argv[])
{
	t_stack	*a_stack;
	char	**args;
	int		i;

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
	if (in_order(a_stack) == 1)
	{
		print_message("OK");
		return (0);
	}
	checker(&a_stack, &b_stack);
	free_stack(&a_stack);
	free_stack(&b_stack);
}
