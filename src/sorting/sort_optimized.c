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
/*
void	fill_stack_a(t_pile **root_a, t_pile **root_b)
{
	int	big;
	t_pile	*first_elem;
	
	first_elem = *root_b;
	big = get_biggest(root_b);
	if (get_position(root_b, big) >= (stack_count(root_b) / 2))
	{
		while (first_elem->number < big)
		{
			rotate_b(root_b);
			if (first_elem->next != NULL)
				first_elem = *root_b;
			else
				return ;
		}
	}
	else
	{
		while (first_elem->number != big)
		{
			reverse_rotate_b(root_b);
			if (first_elem->next != NULL)
				first_elem = *root_b;
			else
				return ;
		}
	}
	push_a(root_a, root_b);
}
*/
/*******         FILL STACK A          ************/

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
