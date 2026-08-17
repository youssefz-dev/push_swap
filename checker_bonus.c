/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzoullik <yzoullik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:54:53 by yzoullik          #+#    #+#             */
/*   Updated: 2025/01/24 11:23:01 by yzoullik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

t_plist	*ft_lstlast(t_plist *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	lstadd_back(t_plist **lst, t_plist *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}

void	ft_free(char **ptr)
{
	size_t	i;

	i = 0;
	if (ptr && ptr[i])
		while (ptr[i])
			free(ptr[i++]);
	if (ptr)
	{
		free(ptr);
		ptr = 0;
	}
}

int	main(int ac, char **av)
{
	char		**ptr;
	int			i;
	t_list		*a;
	t_list		*b;
	t_plist		*moves;

	a = 0;
	b = 0;
	i = 0;
	moves = 0;
	ptr = pars(ac, av);
	if (!ptr)
		return (1);
	if (!ft_getmoves(&moves))
		return (ft_freeptrlst(&moves), write(2, "Error\n", 6), ft_free(ptr), 1);
	while (ptr[i])
		ft_lstadd_back(&a, ft_lstnew(ft_atoi(ptr[i++])));
	ft_free(ptr);
	helptosort(&a, &b, &moves);
	if (ft_sortcheck(&a, &b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (ft_freelst(&a), ft_freelst(&b), ft_freeptrlst(&moves), 0);
}
