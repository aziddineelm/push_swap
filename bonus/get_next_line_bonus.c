/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mans <ael-mans@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 15:44:19 by ael-mans          #+#    #+#             */
/*   Updated: 2025/01/01 17:24:47 by ael-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "push_swap_bonus.h"

static char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;

	len1 = 0;
	if (s1)
		len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = malloc(len1 + len2 + 1);
	if (!str)
		return (NULL);
	if (s1)
		ft_memcpy(str, s1, len1);
	ft_memcpy(str + len1, s2, len2);
	str[len1 + len2] = '\0';
	return (str);
}

char	*ft_read(char *buffer, int fd)
{
	char	*tmp;
	char	*new_buffer;
	int		i;

	if (!buffer)
		buffer = ft_strdup("");
	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (free(buffer), NULL);
	i = 1;
	while (i && !ft_contain(buffer, '\n'))
	{
		i = read(fd, tmp, BUFFER_SIZE);
		if (i < 0)
			return (free(buffer), free(tmp), NULL);
		tmp[i] = '\0';
		new_buffer = ft_strjoin_gnl(buffer, tmp);
		free(buffer);
		if (!new_buffer)
			return (free(tmp), NULL);
		buffer = new_buffer;
	}
	free(tmp);
	return (buffer);
}

char	*ft_line(char *buffer)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = buffer[j];
		j++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_rest_buff(char *buffer)
{
	char	*rest_buffer;
	int		i;
	int		j;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	rest_buffer = malloc(ft_strlen(buffer) - i + 1);
	if (!rest_buffer)
		return (free(buffer), NULL);
	j = 0;
	while (buffer[i])
		rest_buffer[j++] = buffer[i++];
	rest_buffer[j] = '\0';
	free(buffer);
	return (rest_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd == -1)
		return (free(buffer), NULL);
	if (fd < 0 || BUFFER_SIZE < 0 || BUFFER_SIZE > 2147483647)
		return (NULL);
	buffer = ft_read(buffer, fd);
	if (!buffer)
		return (buffer);
	if (!buffer[0])
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	line = ft_line(buffer);
	buffer = ft_rest_buff(buffer);
	return (line);
}
