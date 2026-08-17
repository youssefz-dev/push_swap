/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_moves_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzoullik <yzoullik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:27:39 by yzoullik          #+#    #+#             */
/*   Updated: 2025/01/24 13:00:32 by yzoullik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t			i;
	unsigned char	*s1ptr;
	unsigned char	*s2ptr;

	s1ptr = (unsigned char *) s1;
	s2ptr = (unsigned char *) s2;
	i = 0;
	while (s1ptr[i] && s2ptr[i] && s1ptr[i] == s2ptr[i])
		i++;
	return (s1ptr[i] - s2ptr[i]);
}

int	ft_ismove(char *ptr)
{
	if (!ft_strcmp(ptr, "sa\n"))
		return (1);
	else if (!ft_strcmp(ptr, "sb\n"))
		return (1);
	else if (!ft_strcmp(ptr, "ss\n"))
		return (1);
	else if (!ft_strcmp(ptr, "pa\n"))
		return (1);
	else if (!ft_strcmp(ptr, "pb\n"))
		return (1);
	else if (!ft_strcmp(ptr, "ra\n"))
		return (1);
	else if (!ft_strcmp(ptr, "rb\n"))
		return (1);
	else if (!ft_strcmp(ptr, "rr\n"))
		return (1);
	else if (!ft_strcmp(ptr, "rra\n"))
		return (1);
	else if (!ft_strcmp(ptr, "rrb\n"))
		return (1);
	else if (!ft_strcmp(ptr, "rrr\n"))
		return (1);
	return (0);
}

int	ft_getmoves(t_plist	**lst)
{
	char		*ptr;

	ptr = get_next_line(0);
	while (ptr)
	{
		if (!ft_ismove(ptr))
			return (free(ptr), 0);
		lstadd_back(lst, lstnew(ft_strdup(ptr)));
		free(ptr);
		ptr = get_next_line(0);
	}
	return (1);
}
