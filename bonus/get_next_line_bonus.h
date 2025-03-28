/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mans <ael-mans@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 15:43:08 by ael-mans          #+#    #+#             */
/*   Updated: 2025/03/25 23:46:52 by ael-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "push_swap_bonus.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

char	*get_next_line(int fd);
int		ft_contain(char *str, int c);
int		ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memcpy(void	*dest, const void *src, size_t n);

#endif
