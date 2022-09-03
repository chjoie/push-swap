/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjoie <chjoie@student.42angouleme.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 10:21:45 by chjoie            #+#    #+#             */
/*   Updated: 2022/08/22 11:32:13 by chjoie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_arg_number(t_pile **root)
{
	int	x;
	t_pile	*list;
	
	x = 1;
	list = *root;
	while (list->next)
	{
		list = list->next;
		x++;
	}
	return (x);
}

void	more_than_2(t_pile **root_a, t_pile **root_b, t_pile *list_a)
{
	while (is_lowest(list_a->number, root_a) != 1)
	{
		reverse_rotate_a(root_a);
		list_a = *root_a;
	}
	push_b(root_a, root_b);
	list_a = *root_a;
	while (is_lowest(list_a->number, root_a) != 1)
	{
		reverse_rotate_a(root_a);
		list_a = *root_a;
	}
	list_a = *root_a;
	push_b(root_a, root_b);
}

void	less_than_2(t_pile **root_a, t_pile **root_b, t_pile *list_a)
{
	while (is_lowest(list_a->number, root_a) != 1)
	{
		rotate_a(root_a);
		list_a = *root_a;
	}
	push_b(root_a, root_b);
	list_a = *root_a;
	while (is_lowest(list_a->number, root_a) != 1)
	{
		rotate_a(root_a);
		list_a = *root_a;
	}
	push_b(root_a, root_b);
	list_a = *root_a;
}

void	sort_5(t_pile **root_a, t_pile **root_b)
{
	t_pile	*list_a;

	list_a = *root_a;
	if (lowest_index(root_a) > 2)
		more_than_2(root_a, root_b, list_a);
	else
		less_than_2(root_a, root_b, list_a);
	while (check_if_sorted(*root_a))
		sort_3_args(root_a);
	push_a(root_a, root_b);
	push_a(root_a, root_b);
}
