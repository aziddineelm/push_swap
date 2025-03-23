/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mans <ael-mans@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 11:48:35 by ael-mans          #+#    #+#             */
/*   Updated: 2025/03/23 11:51:00 by ael-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	count_words(const char *s, char c)
{
	size_t	i;
	size_t	wc;

	i = 0;
	wc = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		wc++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (wc);
}

static size_t	count_len(const char *s, char c, size_t index)
{
	size_t	i;

	i = 0;
	while (s[index + i] && s[index + i] != c)
		i++;
	return (i);
}

static char	*word_allocate(const char *s, const char c, size_t index)
{
	char	*str;
	size_t	i;
	size_t	len;

	i = 0;
	len = count_len(s, c, index);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s[index + i] && i < len)
	{
		str[i] = s[index + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static void	free_split_memory(char **arr, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static char	**spliter(char **arr, const char *s, char c)
{
	size_t	i;
	size_t	w;

	i = 0;
	w = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			arr[w] = word_allocate(s, c, i);
			if (!arr[w])
			{
				free_split_memory(arr, w);
				return (NULL);
			}
			w++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	arr[w] = NULL;
	return (arr);
}

char	**ft_split(const char *s, int c)
{
	char	**arr;
	size_t	wc;

	if (!s)
		return (NULL);
	wc = count_words((char *)s, c);
	arr = malloc(sizeof(char *) * (wc + 1));
	if (!arr)
		return (NULL);
	arr = spliter(arr, s, c);
	return (arr);
}
