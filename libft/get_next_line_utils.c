/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjoie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:18:51 by chjoie            #+#    #+#             */
/*   Updated: 2022/04/25 16:29:17 by chjoie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	char	*newstr;
	size_t	i;

	i = 0;
	if (start > ft_strlen(s))
	{
		newstr = malloc(1 * sizeof(char));
		newstr[0] = '\0';
		return (newstr);
	}
	if (len > ft_strlen(s + start))
		newstr = malloc(ft_strlen(s + start) + 1 * sizeof(char));
	else
		newstr = malloc(len + 1 * sizeof(char));
	if (newstr == NULL)
		return (NULL);
	while (start < ft_strlen(s) && s[start] != '\0' && i < len)
	{
		newstr[i] = s[start];
		start++;
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	free((char *)s1);
	return (str);
}
