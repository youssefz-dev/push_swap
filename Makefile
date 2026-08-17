# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzoullik <yzoullik@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/19 14:56:15 by yzoullik          #+#    #+#              #
#    Updated: 2025/01/23 10:00:18 by yzoullik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

BONUS_NAME = checker

HEADER = push_swap.h

HEADER_BONUS = push_swap_bonus.h

SRCS =	check.c\
		ft_split.c\
		utils1.c\
		utils.c\
		pars.c\
		lists.c\
		lis.c\
		best_move.c\
		sort.c\
		moves.c\
		swap.c\
		push.c\
		rotate.c\
		rrotate.c\
		push_swap.c\
	   
SRCS_BONUS =	checker_bonus.c\
				get_next_line_bonus.c\
				get_next_line_utils_bonus.c\
				pars_bonus.c\
				check_bonus.c\
				ft_split_bonus.c\
				lists_bonus.c\
				check_moves_bonus.c\
				check_sort_bonus.c\
				moves_bonus.c\
	   			swap_bonus.c\
	   			push_bonus.c\
	   			rotate_bonus.c\
	   			rrotate_bonus.c\

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(OBJS_BONUS)
	cc $(CFLAGS) $(OBJS_BONUS) -o $(BONUS_NAME)

%.o: %.c $(HEADER)
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: clean