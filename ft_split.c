/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dporhomo <dporhomo@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 19:03:17 by dporhomo          #+#    #+#             */
/*   Updated: 2025/11/24 10:57:25 by dporhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_split_words(char const *s, char c, char **arr, int num_words);
static int	ft_word_count(char const *s, char c);
static char	*ft_word_dup(char const *s, int start, int end);
static void	*ft_free_all(char **arr, int i);

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		num_words;

	if (!s)
		return (NULL);
	num_words = ft_word_count(s, c);
	arr = malloc(sizeof(char *) * (num_words + 1));
	if (!arr)
		return (NULL);
	arr = ft_split_words(s, c, arr, num_words);
	return (arr);
}

static int	ft_word_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	**ft_split_words(char const *s, char c, char **arr, int num_words)
{
	int	i;
	int	w;
	int	start;

	i = 0;
	w = 0;
	while (w < num_words)
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		arr[w] = ft_word_dup(s, start, i);
		if (!arr[w])
			return (ft_free_all(arr, w - 1));
		w++;
	}
	arr[w] = NULL;
	return (arr);
}

static char	*ft_word_dup(char const *s, int start, int end)
{
	char	*word;
	int		j;

	word = (char *)malloc(end - start + 1);
	if (!word)
		return (NULL);
	j = 0;
	while (start < end)
		word[j++] = s[start++];
	word[j] = '\0';
	return (word);
}

static void	*ft_free_all(char **arr, int i)
{
	while (i >= 0)
		free(arr[i--]);
	free(arr);
	return (NULL);
}
