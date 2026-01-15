/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dporhomo <dporhomo@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:16:29 by dporhomo          #+#    #+#             */
/*   Updated: 2025/11/24 11:24:06 by dporhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	c_find;
	int		i;
	char	*last_found_ptr;

	c_find = (char)c;
	last_found_ptr = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == c_find)
			last_found_ptr = (char *)&s[i];
		i++;
	}
	if (c_find == '\0')
		return ((char *)&s[i]);
	return (last_found_ptr);
}
