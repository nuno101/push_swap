/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:01:38 by nlouro            #+#    #+#             */
/*   Updated: 2022/03/07 17:12:03 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h> 
# include <stdlib.h> // used for exit
# include "libft.h"

/*
 * ar is stack array
 * top is the position of the next element/ length of the stack array
 */
typedef struct Stack
{
	int	*ar;
	int	top;
}	t_Stack;

int		_push(t_Stack *st, int val);
int		push(t_Stack *st, int val, char *label);
int		pop(t_Stack *st);
void	swap(t_Stack *s, char *label);
void	rotate(t_Stack *s, char *label);
void	rrotate(t_Stack *s, char *label);

void	show_stack(t_Stack *s);
int		is_ordered(t_Stack *s);
int		ft_is_int(const char *str);
int		ft_is_duplicate(char **argv, int i, int val);
int		get_min_pos(t_Stack *s);
int		get_max_pos(t_Stack *s);

void	normalise(t_Stack *s);
void	radix_sort(t_Stack *s, t_Stack *tmp, int slen);

void	init_stack(t_Stack *st, int size);
void	sort_stack(t_Stack *s);

#endif
