/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzoullik <yzoullik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 09:39:08 by yzoullik          #+#    #+#             */
/*   Updated: 2025/01/27 14:11:47 by yzoullik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_swap(t_list **lst)
{
	t_list	*node2;

	if (!*lst || *lst == (*lst)->next)
		return ;
	if ((*lst)->next == (*lst)->prev)
	{
		*lst = (*lst)->next;
		return ;
	}
	node2 = (*lst)->next;
	node2->prev = (*lst)->prev;
	(*lst)->next = node2->next;
	node2->next = (*lst);
	(*lst)->prev = node2;
	node2->prev->next = node2;
	(*lst)->next->prev = (*lst);
	*lst = node2;
}

void	ft_push(t_list	**lst1, t_list	**lst2)
{
	t_list	*head;
	t_list	*last;
	t_list	*node2;

	if (!*lst1)
		return ;
	if (*lst1 == (*lst1)->next)
	{
		ft_lstadd_front(lst2, *lst1);
		*lst1 = 0;
		lst1 = 0;
		return ;
	}
	head = *lst1;
	last = (*lst1)->prev;
	node2 = (*lst1)->next;
	last->next = node2;
	node2->prev = last;
	*lst1 = node2;
	ft_lstadd_front(lst2, head);
}

void	ft_rotate(t_list **lst)
{
	if (!*lst)
		return ;
	*lst = (*lst)->next;
}

void	ft_rrotate(t_list **lst)
{
	if (!*lst)
		return ;
	*lst = (*lst)->prev;
}
