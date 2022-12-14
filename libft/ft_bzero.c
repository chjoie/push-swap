/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjoie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:06:43 by chjoie            #+#    #+#             */
/*   Updated: 2022/04/02 16:55:12 by chjoie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*copy;

	copy = s;
	while (n != 0)
	{
		*copy = '\0';
		copy++;
		n--;
	}
}
