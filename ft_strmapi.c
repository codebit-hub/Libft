/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dporhomo <dporhomo@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:58:16 by dporhomo          #+#    #+#             */
/*   Updated: 2025/11/24 11:19:11 by dporhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_str;
	unsigned int	i;
	size_t			len_s;

	if (!s || !f)
		return (NULL);
	len_s = ft_strlen(s);
	new_str = (char *)malloc(sizeof(char) * (len_s + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < len_s)
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
