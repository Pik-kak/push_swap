/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkauhane <kkauhane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:00:12 by kkauhane          #+#    #+#             */
/*   Updated: 2024/02/14 14:13:49 by kkauhane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_signs(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = i;
	if (s1[i] == '+')
	{
		if (s2[j] != '+')
			i++;
	}
	else
	{
		if (s2[j] == '+')
			j++;
	}
	while (s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}

void	zero_duplicates(char *args)
{
	int	i;
	int	start;

	i = 0;
	start = 0;
	if (args[i] == '-' || args[i] == '+')
		start++;
	i = start;
	if (args[i] == '0' && args[i + 1] == '0')
	{
		while (args[i] == '0' && args[i + 1] == '0' && args[i + 2] != '\0')
			i++;
	}
	if (args[i] == '0' && args[i + 1] != '\0')
	{
		while (args[i + 1] != '\0')
		{
			args[start] = args[i + 1];
			i++;
			start++;
		}
		args[start] = '\0';
	}
}

int	check_duplicates(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i] != '\0')
	{
		zero_duplicates(args[i]);
		i++;
	}
	i = 0;
	while (args[i])
	{
		j = 1;
		while (args[j])
		{
			if (j != i && check_signs(args[i], args[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_numbers(int argc, char **args, int i)
{
	int	zeros;

	zeros = 0;
	while (args[i] != '\0')
	{
		if (is_number(args[i]) == 0)
		{
			if (argc == 2)
				free_args(args);
			return (0);
		}
		zeros += is_zero(args[i]);
		i++;
	}
	if (zeros > 1 || check_duplicates(args) == 0)
	{
		if (argc == 2)
			free_args(args);
		return (0);
	}
	return (1);
}

int	check_input(int argc, char *argv[])
{
	int		i;
	char	**args;	

	i = 0;
	if (argc == 2)
	{
		if (ft_strlen(argv[1]) == 0)
			return (0);
		args = ft_split(argv[1], ' ');
	}
	else
	{
		args = argv;
		i = 1;
	}
	if (check_numbers(argc, args, i) == 0)
		return (0);
	if (argc == 2)
		free_args(args);
	return (1);
}
