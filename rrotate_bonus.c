/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzoullik <yzoullik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:52:07 by yzoullik          #+#    #+#             */
/*   Updated: 2025/01/15 15:27:41 by yzoullik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rra(t_list **a)
{
	ft_rrotate(a);
}

void	rrb(t_list **b)
{
	ft_rrotate(b);
}

void	rrr(t_list **a, t_list **b)
{
	ft_rrotate(a);
	ft_rrotate(b);
}
