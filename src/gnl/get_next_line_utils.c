/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkabzins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 03:12:51 by rkabzins          #+#    #+#             */
/*   Updated: 2022/04/04 03:12:54 by rkabzins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *str, int c)
{
	char	*s;
	int		i;

	i = 0;
	s = (char *)str;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == ((char)c))
			return ((char *)&s[ft_strlen(s)]);
		s++;
	}
	if ((char)c == 0)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*dest;
	unsigned int	s1_index;
	unsigned int	s2_index;

	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	s1_index = -1;
	s2_index = 0;
	dest = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dest)
		return (NULL);
	while (s1[++s1_index])
		dest[s1_index] = s1[s1_index];
	while (s2[s2_index])
		dest[s1_index++] = s2[s2_index++];
	dest[s1_index] = 0;
	free(s1);
	return (dest);
}
