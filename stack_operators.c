/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operators.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:00:31 by nlouro            #+#    #+#             */
/*   Updated: 2022/03/08 15:14:34 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * push is used to load the user inputs into the stack
 * in that case no pa/pb is written to stdout
 */
int	push(t_Stack *st, int val, char *label)
{
	st->ar[st->top] = val;
	st->top++;
	if (label[0] == 'p')
		write(1, label, 3);
	return (val);
}

int	pop(t_Stack *st)
{
	int	val;

	val = st->ar[st->top - 1];
	st->ar[st->top - 1] = 0;
	st->top--;
	return (val);
}

/*
 * swap the two elements at the top of the stack
 */
void	swap(t_Stack *s, char *label)
{
	int	v;
	int	t;

	v = pop(s);
	t = pop(s);
	_push(s, v);
	_push(s, t);
	write(1, label, 3);
}

void	rotate(t_Stack *s, char *label)
{
	int	tmp;
	int	i;

	i = s->top - 1;
	tmp = s->ar[i];
	while (i > 0)
	{
		s->ar[i] = s->ar[i - 1];
		i--;
	}
	s->ar[0] = tmp;
	write(1, label, 3);
}

void	rrotate(t_Stack *s, char *label)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = s->ar[i];
	while (i < s->top - 1)
	{
		s->ar[i] = s->ar[i + 1];
		i++;
	}
	s->ar[s->top - 1] = tmp;
	write(1, label, 4);
}
