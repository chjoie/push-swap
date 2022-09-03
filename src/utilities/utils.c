/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjoie <chjoie@student.42angouleme.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 11:48:54 by chjoie            #+#    #+#             */
/*   Updated: 2022/08/25 11:48:56 by chjoie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stack_count(t_pile **root)
{
	t_pile	*list;
	int		x;

	list = *root;
	x = 0;
	if (list == NULL)
		return (0);
	while (list->next)
	{
		list = list->next;
		x++;
	}
	x++;
	return (x);
}

int	get_lowest(t_pile **root)
{
	t_pile	*list;

	list = *root;
	while (list->next)
	{
		if (is_lowest(list->number, root))
			return (list->number);
		list = list->next;
	}
	return (list->number);
}

int	get_biggest(t_pile **root)
{
	t_pile *list;

	list = *root;
	while (list->next)
	{
		if (is_biggest(list->number, root) == 1)
			return (list->number);
		list = list->next;
	}
	return (list->number);
}

int	lowest_index(t_pile **root)
{
	t_pile	*list;
	int		x;

	x = 1;
	list = *root;
	while (list->next && (is_lowest(list->number, root) != 1))
	{
		list = list->next;
		x++;
	}
	return (x);
}

int	biggest_index(t_pile **root)
{
	t_pile	*list;
	int		x;

	x = 1;
	list = *root;
	while (list->next && (is_biggest(list->number, root) != 1))
	{
		list = list->next;
		x++;
	}
	return (x);
}
