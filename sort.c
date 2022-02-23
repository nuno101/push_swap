/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:13:52 by nlouro            #+#    #+#             */
/*   Updated: 2022/02/23 16:39:56 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_Stack *s)
{
	int	v;
	int	t;

	v = pop(s);
	t = pop(s);
	push(s, v);
	push(s, t);
}

void	sort_3(t_Stack *s)
{
	t_Stack tmp;

	init_stack(&tmp, s->top);
	if (s->array[2] > s->array[1])
	{
		swap(s);
		write(1, "sa\n", 3);
	}
	if (s->array[1] > s->array[0])
	{
		push(&tmp, pop(s));
		write(1, "pb\n", 3);
		swap(s);
		write(1, "sa\n", 3);
		push(s, pop(&tmp));
		write(1, "pa\n", 3);
	}
	if (s->array[2] > s->array[1])
	{
		swap(s);
		write(1, "sa\n", 3);
	}
}

void	sort_stack(t_Stack *s)
{

	if (s->top == 2)
	{
		swap(s);
		write(1, "sa\n", 3);
	}
	else if (s->top == 3)
		sort_3(s);
	else
		printf("TODO\n");
}
