/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dporhomo <dporhomo@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:07:14 by dporhomo          #+#    #+#             */
/*   Updated: 2025/11/12 16:56:17 by dporhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	byte_c;
	size_t			i;

	ptr = s;
	byte_c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		ptr[i] = byte_c;
		i++;
	}
	return (s);
}
