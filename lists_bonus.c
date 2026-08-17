/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzoullik <yzoullik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 10:10:20 by yzoullik          #+#    #+#             */
/*   Updated: 2025/01/16 10:38:13 by yzoullik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_plist	*lstnew(char *content)
{
	t_plist	*lst;

	lst = malloc(sizeof(t_plist));
	if (!lst)
		return (0);
	lst->content = content;
	lst->next = 0;
	return (lst);
}

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

void	ft_freelst(t_list **lst)
{
	t_list	*head;
	t_list	*node;

	if (!lst || !*lst)
		return ;
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

void	ft_freeptrlst(t_plist **lst)
{
	t_plist	*node;

	if (!*lst || !lst)
		return ;
	while (*lst)
	{
		node = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = node;
	}
}
