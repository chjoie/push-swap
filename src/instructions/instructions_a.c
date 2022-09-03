/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjoie <chjoie@student.42angouleme.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:53:57 by chjoie            #+#    #+#             */
/*   Updated: 2022/08/18 13:22:57 by chjoie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a(t_pile **root)
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
	my_putstr("sa\n");
}

void	push_a(t_pile **root_a, t_pile **root_b)
{
	t_pile	*current;

	current = *root_b;
	if (current == NULL)
		return ;
	*root_b = current->next;
	current->next = *root_a;
	*root_a = current;
	my_putstr("pa\n");
}

void	rotate_a(t_pile **root)
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
	my_putstr("ra\n");
}

void	reverse_rotate_a(t_pile **root)
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
	my_putstr("rra\n");
}
