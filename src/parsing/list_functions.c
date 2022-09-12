/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjoie <chjoie@student.42angouleme.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 18:35:52 by chjoie            #+#    #+#             */
/*   Updated: 2022/08/18 13:25:39 by chjoie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

void	insert_end(t_pile **root, int number)
{
	t_pile	*new_element;
	t_pile	*current;

	new_element = malloc(sizeof(t_pile));
	if (new_element == NULL)
		exit(1);
	new_element->next = NULL;
	new_element->number = number;
	new_element->group = 0;
	if (*root == NULL)
	{
		*root = new_element;
		return ;
	}
	current = *root;
	while (current->next != NULL)
		current = current->next;
	current->next = new_element;
}

void	free_list(t_pile **root)
{
	t_pile	*current;
	t_pile	*to_free;

	current = *root;
	if (*root == NULL)
	{
		free(*root);
		return ;
	}
	while (current->next != NULL)
	{
		to_free = current;
		current = current->next;
		free(to_free);
	}
	free(current);
}

int	check_duplicate(t_pile **root)
{
	t_pile	*copy;
	t_pile	*copy2;

	copy = *root;
	copy2 = copy->next;
	while (copy->next)
	{
		while (copy2->next)
		{
			if (copy->number == copy2->number)
				return (0);
			copy2 = copy2->next;
		}
		if (copy->number == copy2->number)
			return (0);
		copy = copy->next;
	}
	return (1);
}

int	check_if_sorted(t_pile *root)
{
	t_pile	*tmp;
	t_pile	*current;

	current = root;
	if (root->next == NULL)
		return (1);
	tmp = root->next;
	while (tmp->next != NULL)
	{
		if (current->number > tmp->number)
			return (1);
		current = current->next;
		tmp = tmp->next;
	}
	if (current->number > tmp->number)
		return (1);
	return (0);
}

void	free_char_lst(char **args)
{
	int	x;

	x = 0;
	while (args[x])
	{
		free(args[x]);
		x++;
	}
	free(args);
}
