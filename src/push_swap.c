/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjoie <chjoie@student.42angouleme.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 14:55:44 by chjoie            #+#    #+#             */
/*   Updated: 2022/08/18 09:42:50 by chjoie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	my_putstr(char *str)
{
	int	x;

	x = 0;
	while (str[x])
	{
		write(1, &str[x], 1);
		x++;
	}
}

void	check_arguments(int c, char **args)
{
	if (c <= 1)
		exit(0);
	else if (!check_argv(c, args))
	{
		print_error();
		exit(0);
	}
}

void	is_already_in(t_pile **root, int x, char **args)
{
	t_pile	*list;

	list = *root;
	while (list->next)
	{
		if (list->number == x)
			free_and_exit(args, root);
		list = list->next;
	}
	if (list->number == x)
		free_and_exit(args, root);
}

t_pile	*fill_list(t_pile *pile_a, char **args)
{
	int	x;

	x = 0;
	while (args[x])
	{
		if (pile_a != NULL)
			is_already_in(&pile_a, my_atoll(args[x], args, pile_a), args);
		insert_end(&pile_a, my_atoll(args[x], args, pile_a));
		x++;
	}
	if (!(check_if_sorted(pile_a)))
	{
		free_char_lst(args);
		free_list(&pile_a);
		exit(0);
	}
	return (pile_a);
}

int	main(int argc, char **argv)
{
	char	**args;
	t_pile	*pile_a;
	t_pile	*pile_b;

	pile_a = NULL;
	pile_b = NULL;
	check_arguments(argc, argv);
	args = get_elements(argv);
	pile_a = fill_list(pile_a, args);
	sort(args, &pile_a, &pile_b);
	free_char_lst(args);
	free_list(&pile_a);
	free_list(&pile_b);
	return (0);
}
