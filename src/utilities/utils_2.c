/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjoie <chjoie@student.42angouleme.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 11:51:22 by chjoie            #+#    #+#             */
/*   Updated: 2022/08/25 11:51:24 by chjoie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

int	check_group(t_pile **root, int group)
{
	t_pile	*list;

	list = *root;
	if (list == NULL)
		return (0);
	while (list->next)
	{
		if (list->group == group)
			return (1);
		list = list->next;
	}
	if (list->group == group)
		return (1);
	return (0);
}

int	get_next_int(int x, t_pile **root)
{
	int		next;
	t_pile	*list;

	list = *root;
	next = get_biggest(root);
	while (list->next)
	{
		if ((next > list->number && list->number > x) && list->number != x)
			next = list->number;
		list = list->next;
	}
	if ((next > list->number && list->number > x) && list->number != x)
		next = list->number;
	return (next);
}

int	all_group(t_pile **root)
{
	t_pile	*list;

	list = *root;
	while (list->next)
	{
		if (list->group == 0)
			return (0);
		list = list->next;
	}
	if (list->group == 0)
		return (0);
	return (1);
}

void	set_group(int num, t_pile **root, int group)
{
	t_pile	*list;

	list = *root;
	while (list->next)
	{
		if (list->number == num)
		{
			list->group = group;
			return ;
		}
		list = list->next;
	}
	if (list->number == num)
		list->group = group;
	return ;
}

void	get_group(t_pile **root, int limit)
{
	int		group_nb;
	int		num;
	int		x;

	num = get_lowest(root);
	x = 2;
	group_nb = 1;
	set_group(num, root, group_nb);
	while (all_group(root) == 0)
	{
		num = get_next_int(num, root);
		set_group(num, root, group_nb);
		x++;
		if (x >= limit)
		{
			x = 0;
			group_nb++;
		}
	}
}
