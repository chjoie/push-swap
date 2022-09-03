/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_double_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjoie <chjoie@student.42angouleme.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 10:35:44 by chjoie            #+#    #+#             */
/*   Updated: 2022/08/18 13:25:14 by chjoie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_a_noprint(t_pile **root)
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
}

void	rotate_b_noprint(t_pile **root)
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
}

void	ra_and_rb(t_pile **pile_a, t_pile **pile_b)
{
	rotate_a_noprint(pile_a);
	rotate_b_noprint(pile_b);
	my_putstr("rr\n");
}

void	rra_and_rrb(t_pile **pile_a, t_pile **pile_b)
{
	reverse_rotate_a_noprint(pile_a);
	reverse_rotate_b_noprint(pile_b);
	my_putstr("rrr\n");
}
