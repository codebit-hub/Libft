/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dporhomo <dporhomo@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:45:06 by dporhomo          #+#    #+#             */
/*   Updated: 2025/11/13 18:40:42 by dporhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	unsigned char		c_find;
	size_t				i;

	str = (const unsigned char *)s;
	c_find = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == c_find)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
