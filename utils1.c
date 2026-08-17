/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzoullik <yzoullik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:57:26 by yzoullik          #+#    #+#             */
/*   Updated: 2025/01/14 16:23:57 by yzoullik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list **lst)
{
	t_list	*head;
	int		i;

	if (!lst || !*lst)
		return (0);
	head = *lst;
	i = 1;
	*lst = (*lst)->next;
	while (*lst != head)
	{
		i++;
		*lst = (*lst)->next;
	}
	return (i);
}

void	ft_freelst(t_list **lst)
{
	t_list	*head;
	t_list	*node;

	head = *lst;
	node = (*lst)->next;
	free(*lst);
	*lst = node;
	while (*lst != head)
	{
		node = (*lst)->next;
		free(*lst);
		*lst = node;
	}
}

void	setminfirst(t_list	**a)
{
	int	len;

	ft_index(a);
	len = ft_lstmin(a)->len;
	if (len >= 0)
		while (len-- > 0)
			ra(a);
	else
		while (len++ < 0)
			rra(a);
}

void	ft_relen(t_list	**a)
{
	t_list	*head;

	head = *a;
	(*a)->len = 1;
	*a = (*a)->next;
	while (*a != head)
	{
		(*a)->len = 1;
		*a = (*a)->next;
	}
}
