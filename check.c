/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzoullik <yzoullik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 11:33:05 by yzoullik          #+#    #+#             */
/*   Updated: 2025/01/20 10:53:19 by yzoullik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_signal(char c, long *signal, size_t *i)
{
	if (c == '+' || c == '-')
	{
		if (c == '-')
			(*signal) = -1;
		(*i)++;
	}
}

long	ft_atoi(char *str)
{
	size_t		i;
	long long	res;
	long		signal;

	i = 0;
	res = 0;
	signal = 1;
	while ((str[i] && str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	ft_signal(str[i], &signal, &i);
	while (str[i] && ft_isdigit(str[i]))
	{
		if (i >= 18)
			break ;
		res = (res * 10) + (str[i++] - 48);
	}
	return (res * signal);
}

int	ft_digitcheck(char *s)
{
	int	i;

	i = 0;
	if (s[i] && (s[i] == '-' || s[i] == '+') && ft_isdigit(s[i + 1]))
		i++;
	while (s[i])
		if (!ft_isdigit(s[i++]))
			return (0);
	if (ft_atoi(s) > INT_MAX || ft_atoi(s) < INT_MIN)
		return (0);
	return (1);
}

int	ft_isdup(char **ptr)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (ptr[i])
	{
		while (ptr[j])
		{
			if (ft_atoi(ptr[i]) == ft_atoi(ptr[j]))
				return (1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

int	ft_issorted(char **ptr)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (ptr[i])
	{
		while (ptr[j])
		{
			if (ft_atoi(ptr[i]) > ft_atoi(ptr[j]))
				return (0);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}
