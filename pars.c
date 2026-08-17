/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzoullik <yzoullik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:45:58 by yzoullik          #+#    #+#             */
/*   Updated: 2025/01/23 09:44:34 by yzoullik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count(char **av)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (av[i])
		j += ft_strcount(av[i++]);
	return (j);
}

char	**ft_get(char **av)
{
	char	**ptr;
	char	**list;
	int		i;
	int		j;

	j = ft_count(av);
	list = malloc(sizeof(char *) * (j + 1));
	if (!list)
		return (0);
	i = 0;
	while (*av)
	{
		j = 0;
		ptr = ft_split(*av++);
		if (!ptr)
			return (ft_free(list), NULL);
		if (!ptr[j])
			return (ft_free(list), ft_free(ptr), write(2, "Error\n", 6), NULL);
		while (ptr[j])
			list[i++] = ft_strdup(ptr[j++]);
		ft_free(ptr);
	}
	return (list[i] = 0, list);
}

char	**pars(int ac, char **av)
{
	char	**ptr;
	int		i;

	if (ac == 1)
		exit(0);
	ptr = ft_get(++av);
	if (!ptr)
		return (0);
	i = 0;
	while (ptr[i])
		if (!ft_digitcheck(ptr[i++]))
			return (ft_free(ptr), write(2, "Error\n", 6), NULL);
	if (ft_isdup(ptr))
		return (ft_free(ptr), write(2, "Error\n", 6), NULL);
	if (ft_issorted(ptr))
	{
		ft_free(ptr);
		exit(0);
	}
	return (ptr);
}
