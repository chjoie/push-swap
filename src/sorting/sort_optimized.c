/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_optimized.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjoie <chjoie@student.42angouleme.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 09:29:47 by chjoie            #+#    #+#             */
/*   Updated: 2022/08/25 10:29:07 by chjoie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

int	closest_to_top(t_pile **root, int group)
{
	t_pile	*list;
	int		instructions;
	int		value;

	instructions = stack_count(root);
	list = *root;
	value = list->number;
	value = get_value(root, instructions, value, group);
	return (value);
}

void	sort_optimized(t_pile **root_a, t_pile **root_b)
{
	int	group;
	int	value;

	group = 1;
	while (stack_count(root_a) > 0)
	{
		while (check_group(root_a, group) != 0)
		{
			value = closest_to_top(root_a, group);
			put_value_top(root_a, value);
			push_b(root_a, root_b);
		}
		group++;
	}
	while (stack_count(root_b) > 0)
	{
		value = get_biggest(root_b);
		put_value_top_b(root_b, value);
		push_a(root_a, root_b);
	}
}
