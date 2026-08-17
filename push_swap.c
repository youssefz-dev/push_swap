/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzoullik <yzoullik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:05:11 by yzoullik          #+#    #+#             */
/*   Updated: 2025/01/21 14:38:44 by yzoullik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char	**ptr;
	int		i;
	t_list	*a;
	t_list	*b;

	ptr = pars(ac, av);
	if (!ptr)
		return (1);
	a = 0;
	b = 0;
	i = 0;
	while (ptr[i])
		ft_lstadd_back(&a, ft_lstnew(ft_atoi(ptr[i++])));
	ft_free(ptr);
	if (ft_lstsize(&a) <= 3)
		sort_three(&a);
	else if (ft_lstsize(&a) == 5)
		sort_five(&a, &b);
	else
	{
		ft_bestlis(&a);
		ft_pushtob(&a, &b);
		ft_sort(&a, &b);
	}
	return (ft_freelst(&a), 0);
}
