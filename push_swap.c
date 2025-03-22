/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mans <ael-mans@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:58:55 by ael-mans          #+#    #+#             */
/*   Updated: 2025/03/21 17:27:54 by ael-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

char	**filter_args(char **av)
{
	char	*str;
	char	*tmp;
	int		i;
	char	**args;

	i = 1;
	str = ft_strdup(av[i]);
	i++;
	while(av[i])
	{
		tmp = ft_strjoin(str, av[i]);
		free(str);
		str = tmp;
		i++;
	}
	args = ft_split(str, ' ');
	free(str);
	return (args);
}

int	main(int ac, char **av)
{
	t_data	data;
	char	**args;

	if (ac < 3)
		return 0;
	data.stack_a = NULL;
	args = filter_args(av);
	for (int i = 0; args[i]; i++)
		printf("%s\n", args[i]);
	return (0);
}
