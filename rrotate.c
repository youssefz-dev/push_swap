/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzoullik <yzoullik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:52:07 by yzoullik          #+#    #+#             */
/*   Updated: 2025/01/15 15:02:29 by yzoullik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **a)
{
	ft_rrotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_list **b)
{
	ft_rrotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b)
{
	ft_rrotate(a);
	ft_rrotate(b);
	write(1, "rrr\n", 4);
}
