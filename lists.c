/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzoullik <yzoullik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 10:10:20 by yzoullik          #+#    #+#             */
/*   Updated: 2025/01/18 16:59:04 by yzoullik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (0);
	lst->content = content;
	lst->len = 1;
	lst->ptr = 0;
	lst->next = 0;
	lst->prev = 0;
	return (lst);
}

t_list	*ft_lstmin(t_list **lst)
{
	t_list	*head;
	t_list	*min;

	if (!lst || !*lst)
		return (0);
	head = *lst;
	min = *lst;
	*lst = (*lst)->next;
	while (*lst != head)
	{
		if (min->content > (*lst)->content)
			min = *lst;
		*lst = (*lst)->next;
	}
	return (min);
}

t_list	*ft_lstmax(t_list **lst)
{
	t_list	*head;
	t_list	*max;

	if (!lst || !*lst)
		return (0);
	head = *lst;
	max = *lst;
	*lst = (*lst)->next;
	while (*lst != head)
	{
		if (max->content < (*lst)->content)
			max = *lst;
		*lst = (*lst)->next;
	}
	return (max);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		new->next = new;
		new->prev = new;
		*lst = new;
	}
	else
	{
		last = (*lst)->prev;
		new->next = (*lst);
		new->prev = last;
		last->next = new;
		(*lst)->prev = new;
	}
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		new->next = new;
		new->prev = new;
		*lst = new;
	}
	else
	{
		last = (*lst)->prev;
		new->next = *lst;
		(*lst)->prev = new;
		last->next = new;
		new->prev = last;
		*lst = new;
	}
}
