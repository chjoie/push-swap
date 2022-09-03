/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjoie <chjoie@student.42angouleme.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:01:40 by chjoie            #+#    #+#             */
/*   Updated: 2022/08/17 17:55:05 by chjoie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

int	check_after_sign(char **args)
{
	int	x;
	int	i;

	x = 0;
	i = 1;
	while (args[i])
	{
		x = 0;
		while (args[i][x])
		{
			if (args[i][x] == '-' || args[i][x] == '+')
			{
				if (args[i][x - 1] != ' ' && x >= 1)
					return (0);
				x++;
				if (args[i][x] < '0' || args[i][x] > '9')
					return (0);
			}
			else
				x++;
		}
		i++;
	}
	return (1);
}

int	check_only_space(char **args)
{
	int	i;
	int	x;
	int	check;

	i = 1;
	while (args[i])
	{
		x = 0;
		check = 0;
		while (args[i][x])
		{
			if (args[i][x] >= '0' && args[i][x] <= '9')
				check++;
			x++;
		}
		if (check == 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_argv(int argc, char **argv)
{
	int	x;

	x = 1;
	while (x < argc)
	{
		if (argv[x][0] == '\0')
			return (0);
		x++;
	}
	if (check_after_sign(argv) == 0)
		return (0);
	if (check_argv_content(argv) == 0)
		return (0);
	return (1);
}

int	check_argv_content(char **argv)
{
	int	i;
	int	x;

	x = 0;
	i = 1;
	while (argv[i])
	{
		x = 0;
		if (ft_strlen(argv[i]) == 1 && argv[i][x] == '-')
			return (0);
		while (argv[i][x])
		{
			if ((argv[i][x] >= '0' && argv[i][x] <= '9') || \
				argv[i][x] == ' ' || argv[i][x] == '-' || argv[i][x] == '+')
				x++;
			else
				return (0);
		}
		i++;
	}
	return (check_only_space(argv));
}
