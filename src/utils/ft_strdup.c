/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkabzins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 01:34:52 by rkabzins          #+#    #+#             */
/*   Updated: 2022/02/18 01:35:17 by rkabzins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*srcstr;
	char		*deststr;

	srcstr = src;
	deststr = dest;
	while (n--)
		*deststr++ = *srcstr++;
	return (dest);
}

char	*ft_strdup(const char *source)
{
	char	*dest;
	size_t	src_len;

	src_len = ft_strlen(source) + 1;
	dest = malloc(sizeof(char) * (src_len));
	if (!dest)
		return (NULL);
	ft_memcpy(dest, source, (src_len));
	return (dest);
}
