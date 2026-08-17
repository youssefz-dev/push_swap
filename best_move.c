/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzoullik <yzoullik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:32:44 by yzoullik          #+#    #+#             */
/*   Updated: 2025/01/20 11:14:02 by yzoullik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_index(t_list	**lst)
{
	t_list	*head;
	int		i;
	int		size;

	if (!lst || !*lst)
		return ;
	head = *lst;
	i = -1;
	size = ft_lstsize(lst) / 2;
	(*lst)->len = ++i;
	*lst = (*lst)->next;
	while (i < size && *lst != head)
	{
		(*lst)->len = ++i;
		*lst = (*lst)->next;
	}
	if (ft_lstsize(lst) % 2 == 0)
		i--;
	while (*lst != head)
	{
		(*lst)->len = -i--;
		*lst = (*lst)->next;
	}
}

void	ft_move(t_list	**a, t_list	*node)
{
	t_list	*head;

	head = *a;
	if (node->content > ft_lstmax(a)->content)
	{
		node->ptr = ft_lstmin(a);
		return ;
	}
	node->ptr = *a;
	*a = (*a)->next;
	while (*a != head)
	{
		if ((*a)->content > node->content && (*a)->content < node->ptr->content)
			node->ptr = *a;
		if (node->ptr->content < node->content)
			node->ptr = *a;
		*a = (*a)->next;
	}		
}

void	ft_bestmove(t_list	**a, t_list	**b)
{
	t_list	*head;

	if (!a || !*a || !b || !*b)
		return ;
	ft_index(b);
	ft_index(a);
	head = *b;
	ft_move(a, *b);
	*b = (*b)->next;
	while (*b != head)
	{
		ft_move(a, *b);
		*b = (*b)->next;
	}
}

int	ft_calc(t_list *b, t_list *bptr)
{
	int	lena;
	int	lenb;

	lena = bptr->len;
	lenb = b->len;
	if (lena <= 0 && lenb <= 0)
		return (lena * -1 + lenb * -1);
	else if (lena <= 0 && lenb >= 0)
		return (lena * -1 + lenb);
	else if (lena >= 0 && lenb <= 0)
		return (lena + lenb * -1);
	else
		return (lena + lenb);
}

t_list	*ft_settoa(t_list **b)
{
	t_list	*ptr;
	t_list	*head;
	int		res;

	ptr = *b;
	res = ft_calc(*b, (*b)->ptr);
	head = *b;
	*b = (*b)->next;
	while (head != *b)
	{
		if (res > ft_calc(*b, (*b)->ptr))
		{
			res = ft_calc(*b, (*b)->ptr);
			ptr = *b;
		}
		*b = (*b)->next;
	}
	return (ptr);
}
