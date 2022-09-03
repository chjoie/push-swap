/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjoie <chjoie@student.42angouleme.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 11:56:21 by chjoie            #+#    #+#             */
/*   Updated: 2022/08/17 17:55:16 by chjoie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*my_substr(char *str, char *substr, int start, int end)
{
	int	x;

	x = 0;
	if (end == 0)
		return (NULL);
	while (str[start] && x <= end)
	{
		substr[x] = str[start];
		x++;
		start++;
	}
	substr[x] = '\0';
	return (substr);
}

char	**fill_tmp(char **tmp, char	*str)
{
	size_t	x;
	int		m_size;
	int		i;

	i = 0;
	x = 0;
	m_size = 0;
	while (x <= ft_strlen(str))
	{
		while (str[x] == ' ' && str[x])
			x++;
		m_size = word_size(str, x);
		if (m_size != 0)
		{	
			tmp[i] = malloc(sizeof(char *) * m_size + 1);
			if (tmp[i] == NULL)
				exit(1);
			tmp[i] = my_substr(str, tmp[i], x, m_size);
			x = x + m_size;
			i++;
		}
		x++;
	}
	tmp[i] = NULL;
	return (tmp);
}

char	**fill_elems(char **elements, char *str, int *i)
{
	char	**tmp;
	int		x;

	x = 0;
	tmp = malloc(sizeof(tmp) * (new_size(str, 0) + 1));
	if (tmp == NULL)
		return (NULL);
	tmp = fill_tmp(tmp, str);
	while (tmp[x] != NULL)
	{
		elements[*i] = ft_strdup(tmp[x]);
		x++;
		*i = *i + 1;
	}
	free_char_lst(tmp);
	return (elements);
}

char	**get_elements(char **argv)
{
	char	**elements;
	int		size;
	int		i;
	int		index;

	index = 1;
	i = 0;
	size = get_args_size(argv);
	elements = malloc(sizeof(elements) * (size + 1));
	if (elements == NULL)
		exit(1);
	while (argv[index])
	{
		if (is_space(argv[index]))
			elements = fill_elems(elements, argv[index], &i);
		else
		{
			elements[i] = ft_strdup(argv[index]);
			i++;
		}
		index++;
	}
	elements[i] = NULL;
	return (elements);
}

int	my_atoll(char *str, char **args, t_pile *root)
{
	long long int	value;
	int				x;
	int				sign;

	sign = 0;
	value = 0;
	x = 0;
	if (str[x] == '-' || str[x] == '+')
	{
		if (str[x] == '-')
		sign++;
		x++;
	}
	while ((str[x] >= '0' && str[x] <= '9') && str[x] != '\0')
	{
		value = value * 10 + str[x] - '0';
		x++;
	}
	if (sign == 1)
		value = value * -1;
	if (value > 2147483647 || value < -2147483648)
		free_and_exit(args, &root);
	return ((int)value);
}
