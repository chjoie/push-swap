/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjoie <chjoie@student.42angouleme.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:14:27 by chjoie            #+#    #+#             */
/*   Updated: 2022/08/18 13:23:48 by chjoie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_b(t_pile **root)
{
	t_pile	*first;
	t_pile	*second;
	int		tmp;

	first = *root;
	if (first == NULL || first->next == NULL)
		return ;
	tmp = first->number;
	second = first->next;
	first->number = second->number;
	second->number = tmp;
	my_putstr("sb\n");
}

void	push_b(t_pile **root_a, t_pile **root_b)
{
	t_pile	*current;

	current = *root_a;
	if (current == NULL)
		return ;
	*root_a = current->next;
	current->next = *root_b;
	*root_b = current;
	my_putstr("pb\n");
}

void	rotate_b(t_pile **root)
{
	t_pile	*current;
	t_pile	*first;

	first = *root;
	if (first == NULL || first->next == NULL)
		return ;
	*root = first->next;
	current = *root;
	while (current->next)
		current = current->next;
	current->next = first;
	first->next = NULL;
	my_putstr("rb\n");
}

void	reverse_rotate_b(t_pile **root)
{
	t_pile	*current;
	t_pile	*to_move;

	to_move = *root;
	if (*root == NULL || to_move->next == NULL)
		return ;
	current = to_move->next;
	if (current->next != NULL && current->next->next != NULL)
	{
		while (current->next->next)
			current = current->next;
	}
	if (current->next != NULL)
	{
		to_move = current->next;
		to_move->next = *root;
		*root = to_move;
		current->next = NULL;
	}
	else
		swap_b_noprint(root);
	my_putstr("rrb\n");
}
