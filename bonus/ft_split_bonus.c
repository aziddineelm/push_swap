/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mans <ael-mans@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 11:48:35 by ael-mans          #+#    #+#             */
/*   Updated: 2025/03/25 16:16:31 by ael-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static char	*copy_word(const char *start, const char *end)
{
	char	*word;
	int		len;
	int		i;

	i = 0;
	len = end - start;
	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = *start;
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

static void	all_free(char **array, size_t count)
{
	while (count > 0)
	{
		count--;
		free(array[count]);
	}
	free(array);
}

static size_t	count_words(const char *s, char c)
{
	int	words;
	int	in_word;

	words = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			words++;
			in_word = 1;
		}
		else if (*s == c)
		{
			in_word = 0;
		}
		s++;
	}
	return (words);
}

static int	add_word(char **new_string, const char **s, size_t *i, char c)
{
	const char	*start = *s;

	while (**s && **s != c)
		(*s)++;
	new_string[*i] = copy_word(start, *s);
	if (!new_string[*i])
	{
		all_free(new_string, *i);
		return (0);
	}
	(*i)++;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**new_string;
	size_t	total_words;
	size_t	i;

	if (!s)
		return (NULL);
	total_words = count_words(s, c);
	i = 0;
	new_string = (char **)malloc((total_words + 1) * sizeof(char *));
	if (!new_string)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			if (!add_word(new_string, &s, &i, c))
				return (NULL);
		}
		else
			s++;
	}
	new_string[i] = NULL;
	return (new_string);
}
