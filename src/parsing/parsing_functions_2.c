/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_functions_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjoie <chjoie@student.42angouleme.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 12:02:05 by chjoie            #+#    #+#             */
/*   Updated: 2022/08/17 17:55:21 by chjoie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_space(char *str)
{
	int	x;

	x = 0;
	while (str[x])
	{
		if (str[x] == ' ')
			return (1);
		x++;
	}
	return (0);
}

int	new_size(char *str, int size)
{
	int	x;
	int	cpt;

	x = 0;
	while (str[x] != '\0')
	{
		cpt = 0;
		while ((str[x] == ' ' || str[x] == '-' || str[x] == '+') \
			&& str[x] != '\0')
			x++;
		while ((str[x] >= '0' && str[x] <= '9') && str[x] != '\0')
		{
			x++;
			cpt++;
		}
		if (cpt > 0)
			size++;
	}
	return (size);
}

int	get_args_size(char **argv)
{
	int	x;
	int	size;

	size = 0;
	x = 1;
	while (argv[x])
	{
		if (is_space(argv[x]))
			size = new_size(argv[x], size);
		else
			size++;
		x++;
	}
	return (size);
}

int	word_size(char *str, int size)
{
	int	x;

	x = 0;
	if (str[size] == '-' || str[size] == '+')
		size++;
	while ((str[size] >= '0' && str[size] <= '9') && str[size])
	{
		size++;
		x++;
	}
	return (x);
}

void	free_and_exit(char **args, t_pile **root)
{
	free_list(root);
	free_char_lst(args);
	print_error();
}
