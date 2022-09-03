/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_double.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjoie <chjoie@student.42angouleme.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 18:27:39 by chjoie            #+#    #+#             */
/*   Updated: 2022/08/18 13:24:41 by chjoie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa_and_sb(t_pile *pile_a, t_pile *pile_b)
{
	swap_a_noprint(&pile_a);
	swap_b_noprint(&pile_b);
	my_putstr("ss\n");
}

void	swap_b_noprint(t_pile **root)
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
}

void	swap_a_noprint(t_pile **root)
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
}

void	reverse_rotate_a_noprint(t_pile **root)
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
		swap_a_noprint(root);
}

void	reverse_rotate_b_noprint(t_pile **root)
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
}
