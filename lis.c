/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzoullik <yzoullik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:24:34 by yzoullik          #+#    #+#             */
/*   Updated: 2025/01/18 15:02:11 by yzoullik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstmaxlen(t_list **lst)
{
	t_list	*head;
	int		max;

	if (!lst || !*lst)
		return (0);
	head = *lst;
	max = (*lst)->len;
	*lst = (*lst)->next;
	while (*lst != head)
	{
		if (max < (*lst)->len)
			max = (*lst)->len;
		*lst = (*lst)->next;
	}
	return (max);
}

void	ft_lis(t_list **a)
{
	t_list	*i;
	t_list	*j;

	ft_relen(a);
	i = *a;
	j = (*a)->next;
	while (j != *a)
	{
		while (i != j)
		{
			if (i->content < j->content && j->len <= i->len)
				j->len = i->len + 1;
			i = i->next;
		}
		j = j->next;
		i = *a;
	}
}

void	ft_setlis(t_list **a)
{
	int		maxlen;
	t_list	*head;

	head = *a;
	maxlen = ft_lstmaxlen(a);
	*a = (*a)->prev;
	while (*a != head)
	{
		if ((*a)->len == maxlen)
		{
			(*a)->len = 0;
			maxlen--;
		}
		*a = (*a)->prev;
	}
}

void	ft_bestlis(t_list	**a)
{
	int		res;
	int		len;
	t_list	*head;
	t_list	*best;

	head = *a;
	ft_lis(a);
	res = ft_lstmaxlen(a);
	best = *a;
	*a = (*a)->next;
	while (*a != head)
	{
		ft_lis(a);
		len = ft_lstmaxlen(a);
		if (len > res)
		{
			res = len;
			best = *a;
		}
		*a = (*a)->next;
	}
	ft_lis(&best);
	ft_setlis(&best);
}

void	ft_pushtob(t_list **a, t_list **b)
{
	t_list	*last;
	int		med;

	med = (ft_lstmax(a)->content + ft_lstmin(a)->content) / 2;
	last = (*a)->prev;
	while (*a != last)
	{
		if ((*a)->len != 0)
		{
			if ((*a)->content > med)
			{
				pb(b, a);
				rb(b);
			}
			else
				pb(b, a);
		}
		else
			ra(a);
	}
	if (last ->len != 0)
		pb(b, a);
}
