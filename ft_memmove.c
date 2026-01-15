/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dporhomo <dporhomo@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:36:53 by dporhomo          #+#    #+#             */
/*   Updated: 2025/11/13 13:11:07 by dporhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	for_copy(unsigned char *dst, const unsigned char *src, size_t n);
static void	back_copy(unsigned char *dst, const unsigned char *src, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*p_dst;
	const unsigned char	*p_src;

	if (!dest && !src)
		return (NULL);
	if (n == 0 || dest == src)
		return (dest);
	p_dst = (unsigned char *)dest;
	p_src = (const unsigned char *)src;
	if (p_dst < p_src)
		for_copy(p_dst, p_src, n);
	else if (p_dst > p_src)
		back_copy(p_dst, p_src, n);
	return (dest);
}

static void	for_copy(unsigned char *dst, const unsigned char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
}

static void	back_copy(unsigned char *dst, const unsigned char *src, size_t n)
{
	while (n > 0)
	{
		dst[n - 1] = src[n - 1];
		n--;
	}
}
