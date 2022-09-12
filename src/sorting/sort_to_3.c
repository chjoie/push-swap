/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_to_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjoie <chjoie@student.42angouleme.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:11:49 by chjoie            #+#    #+#             */
/*   Updated: 2022/08/22 11:33:39 by chjoie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_lowest(int x, t_pile **root)
{
	t_pile	*list;

	list = *root;
	while (list->next != NULL)
	{
		if (x <= list->number)
			list = list->next;
		else
			return (0);
	}
	if (x <= list->number)
		return (1);
	else
		return (0);
}

int	is_biggest(int x, t_pile **root)
{
	t_pile	*list;

	list = *root;
	while (list->next != NULL)
	{
		if (x >= list->number)
			list = list->next;
		else
			return (0);
	}
	if (x >= list->number)
		return (1);
	else
		return (0);
}

void	sort_3_args(t_pile **root)
{
	t_pile	*list;

	list = *root;
	if (is_lowest(list->number, root) == 1)
	{
		list = list->next;
		if ((is_biggest(list->number, root) == 1))
		{
			reverse_rotate_a(root);
			swap_a(root);
		}
		return ;
	}
	while (list->next)
		list = list->next;
	if ((is_biggest(list->number, root) == 1))
	{
		if (check_if_sorted(*root) == 0)
			return ;
		swap_a(root);
	}
	else
		rotate_a(root);
	return ;
}

void	sort_to_3(t_pile **root_a)
{
	while (check_if_sorted(*root_a))
		sort_3_args(root_a);
}

void	sort(char **args, t_pile **root_a, t_pile **root_b)
{
	int	x;
	int	in_group;

	x = get_arg_number(root_a);
	if (x == 1)
	{
		free_char_lst(args);
		free_list(root_a);
		exit(0);
	}
	if (x <= 100)
		in_group = x / 7;
	else
		in_group = x / 12;
	if (x <= 3)
		sort_to_3(root_a);
	else if (x < 6)
		sort_5(root_a, root_b);
	else
	{
		get_group(root_a, in_group);
		sort_optimized(root_a, root_b);
	}
}
