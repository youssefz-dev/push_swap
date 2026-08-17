/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzoullik <yzoullik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:55:08 by yzoullik          #+#    #+#             */
/*   Updated: 2025/01/17 16:13:03 by yzoullik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort1(t_list **a, t_list **b, int lena, int lenb)
{
	if (lena <= 0 && lenb <= 0)
	{
		while (lena < 0 && lenb < 0)
		{
			rrr(a, b);
			lena++;
			lenb++;
		}
		while (lena++ < 0)
			rra(a);
		while (lenb++ < 0)
			rrb(b);
	}
	else if (lena <= 0 && lenb >= 0)
	{
		while (lena++ < 0)
			rra(a);
		while (lenb-- > 0)
			rb(b);
	}
}

void	sort2(t_list **a, t_list **b, int lena, int lenb)
{
	if (lena >= 0 && lenb <= 0)
	{
		while (lena-- > 0)
			ra(a);
		while (lenb++ < 0)
			rrb(b);
	}
	else if (lena >= 0 && lenb >= 0)
	{
		while (lena > 0 && lenb > 0)
		{
			rr(a, b);
			lena--;
			lenb--;
		}
		while (lena-- > 0)
			ra(a);
		while (lenb-- > 0)
			rb(b);
	}
}

void	ft_sort(t_list **a, t_list **b)
{
	t_list	*best;
	int		lena;
	int		lenb;

	while (*b)
	{
		ft_bestmove(a, b);
		best = ft_settoa(b);
		lenb = best->len;
		lena = best->ptr->len;
		if ((lena <= 0 && lenb <= 0) || (lena <= 0 && lenb >= 0))
			sort1(a, b, lena, lenb);
		else if ((lena >= 0 && lenb <= 0) || (lena >= 0 && lenb >= 0))
			sort2(a, b, lena, lenb);
		pa(a, b);
	}
	setminfirst(a);
}

void	sort_three(t_list **a)
{
	if ((*a)->prev->content < (*a)->content)
		rra(a);
	if ((*a)->next->content > (*a)->prev->content)
		rra(a);
	if ((*a)->content > (*a)->next->content)
		sa(a);
}

void	sort_five(t_list **a, t_list **b)
{
	setminfirst(a);
	pb(b, a);
	setminfirst(a);
	pb(b, a);
	sort_three(a);
	pa(a, b);
	pa(a, b);
}
