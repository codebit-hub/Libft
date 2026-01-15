/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dporhomo <dporhomo@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:15:41 by dporhomo          #+#    #+#             */
/*   Updated: 2025/11/13 14:36:42 by dporhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	c_find;
	int		i;

	c_find = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == c_find)
			return ((char *)&s[i]);
		i++;
	}
	if (c_find == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
