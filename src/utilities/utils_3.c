/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjoie <chjoie@student.42angouleme.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 12:04:28 by chjoie            #+#    #+#             */
/*   Updated: 2022/08/25 12:04:35 by chjoie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	put_value_top_b(t_pile **root, int value)
{
	t_pile	*list;
	int	direction;
	

	direction = 1;
	list = *root;
	if (get_position(root, value) >= (stack_count(root) / 2))
		direction = 0;
	while (list->number != value)
	{
		if (direction == 1)
			rotate_b(root);
		else
			reverse_rotate_b(root);
		list = *root;
	}
}

int	get_position(t_pile **root, int number)
{
	t_pile	*list;
	int		x;

	list = *root;
	x = 0;
	while (list->next)
	{
		if (list->number == number)
			return (x);
		list = list->next;
		x++;
	}
	x++;
	return (x);
}

int	get_instructions_nb(t_pile **root, int number)
{
	t_pile *list;

	list = *root;
	while (list->next)
	{
		if (list->number == number)
		{
			if (get_position(root, list->number) >= (stack_count(root) / 2))
				return ((stack_count(root) - get_position(root, list->number) + 1));
			else
				return (get_position(root, list->number));
		}
		list = list->next;
	}
	return ((stack_count(root) - get_position(root, list->number) + 1));
}

int	closest_to_top(t_pile **root, int group)
{
	t_pile	*list;
	int		instructions;
	int		value;

	instructions = stack_count(root);
	list = *root;
	value = list->number;
	while (list->next)
	{
		if (list->group == group)
		{
			if (instructions > get_instructions_nb(root, list->number))
			{
				instructions = get_instructions_nb(root, list->number);
				value = list->number;
			}
		}
		list = list->next;
	}
	if (list->group == group)
	{
		if (instructions > get_instructions_nb(root, list->number))
		{
			instructions = get_instructions_nb(root, list->number);
			value = list->number;
		}
	}
	return (value);
}

void	put_value_top(t_pile **root, int value)
{
	t_pile	*list;
	int	direction;

	direction = 1;
	list = *root;
	if (get_position(root, value) >= (stack_count(root) / 2))
		direction = 0;
	while (list->number != value)
	{
		if (direction == 1)
			rotate_a(root);
		else
			reverse_rotate_a(root);
		list = *root;
	}
}
