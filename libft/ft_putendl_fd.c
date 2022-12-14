/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlendl_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjoie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:34:31 by chjoie            #+#    #+#             */
/*   Updated: 2022/04/12 15:38:16 by chjoie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	x;

	x = 0;
	if (s != NULL)
	{
		while (s[x] != '\0')
		{
			write(fd, &s[x], 1);
			x++;
		}
		write(fd, "\n", 1);
	}
}
