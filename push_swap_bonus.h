/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzoullik <yzoullik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:02:53 by yzoullik          #+#    #+#             */
/*   Updated: 2025/01/24 11:09:11 by yzoullik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_plist
{
	char				*content;
	struct s_plist		*next;
	struct s_plist		*prev;
}				t_plist;

typedef struct s_list
{
	int				content;
	int				len;
	struct s_list	*ptr;
	struct s_list	*next;
	struct s_list	*prev;
}				t_list;

# define BUFFER_SIZE 42

int		ft_isdigit(int c);
long	ft_atoi(char *str);
size_t	ft_strcount(char const *s);
char	**ft_split(char const *s);
int		ft_isdup(char **av);
int		ft_digitcheck(char *s);
void	ft_free(char **ptr);
char	**pars(int ac, char **av);

char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
int		ft_strchr(char *s, int c);
char	*ft_strdup(char *s1);
size_t	ft_strlcat(char *dst, char *src, size_t dstsize);

void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_freelst(t_list **lst);
void	ft_freeptrlst(t_plist **lst);
t_list	*ft_lstnew(int content);
t_plist	*lstnew(char *content);

int		ft_getmoves(t_plist	**lst);

void	helptosort(t_list **a, t_list **b, t_plist **moves);
int		ft_sortcheck(t_list **a, t_list	**b);
void	lstadd_back(t_plist **lst, t_plist *new);
int		ft_strcmp(char *s1, char *s2);

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