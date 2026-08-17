/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzoullik <yzoullik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:56:13 by yzoullik          #+#    #+#             */
/*   Updated: 2025/01/20 11:42:53 by yzoullik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	int				content;
	int				len;
	struct s_list	*ptr;
	struct s_list	*next;
	struct s_list	*prev;
}				t_list;

int		ft_isdigit(int c);
long	ft_atoi(char *str);
size_t	ft_strcount(char const *s);
char	**ft_split(char const *s);
int		ft_isdup(char **av);
int		ft_digitcheck(char *s);
char	*ft_strdup(const char *s1);
void	ft_free(char **ptr);
int		ft_issorted(char **ptr);
char	**pars(int ac, char **av);

t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list **lst);
t_list	*ft_lstmin(t_list **lst);
t_list	*ft_lstmax(t_list **lst);
void	ft_freelst(t_list **lst);
void	setminfirst(t_list	**a);

void	ft_relen(t_list	**a);
void	ft_bestlis(t_list	**a);
void	ft_pushtob(t_list **a, t_list **b);

void	ft_index(t_list	**lst);
void	ft_bestmove(t_list	**a, t_list	**b);
t_list	*ft_settoa(t_list **b);

void	ft_sort(t_list **a, t_list **b);
void	sort_three(t_list **a);
void	sort_five(t_list **a, t_list **b);

void	ft_swap(t_list **lst);
void	ft_push(t_list	**lst1, t_list	**lst2);
void	ft_rotate(t_list **lst);
void	ft_rrotate(t_list **lst);
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **b, t_list **a);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

#endif