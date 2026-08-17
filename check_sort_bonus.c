/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzoullik <yzoullik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:29:27 by yzoullik          #+#    #+#             */
/*   Updated: 2025/01/24 11:41:17 by yzoullik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_sort(t_list	**a, t_list	**b, t_plist **moves)
{
	if (!ft_strcmp((*moves)->content, "sa\n"))
		sa(a);
	else if (!ft_strcmp((*moves)->content, "sb\n"))
		sb(b);
	else if (!ft_strcmp((*moves)->content, "ss\n"))
		ss(a, b);
	else if (!ft_strcmp((*moves)->content, "pa\n"))
		pa(a, b);
	else if (!ft_strcmp((*moves)->content, "pb\n"))
		pb(b, a);
	else if (!ft_strcmp((*moves)->content, "ra\n"))
		ra(a);
	else if (!ft_strcmp((*moves)->content, "rb\n"))
		rb(b);
	else if (!ft_strcmp((*moves)->content, "rr\n"))
		rr(a, b);
	else if (!ft_strcmp((*moves)->content, "rra\n"))
		rra(a);
	else if (!ft_strcmp((*moves)->content, "rrb\n"))
		rrb(b);
	else if (!ft_strcmp((*moves)->content, "rrr\n"))
		rrr(a, b);
}

void	helptosort(t_list **a, t_list **b, t_plist **moves)
{
	t_plist	*head;

	head = *moves;
	while (*moves)
	{
		ft_sort(a, b, moves);
		*moves = (*moves)->next;
	}
	*moves = head;
}

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

int	ft_sortcheck(t_list **a, t_list	**b)
{
	t_list	*head;
	t_list	*node;

	if (!a || !*a || ft_lstsize(b) != 0)
		return (0);
	head = *a;
	node = (*a)->next;
	while (node != head)
	{
		while (node != head)
		{
			if ((*a)->content > node->content)
				return (0);
			node = node->next;
		}
		node = (*a)->next;
		*a = (*a)->next;
	}
	return (1);
}
