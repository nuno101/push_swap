/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:13:52 by nlouro            #+#    #+#             */
/*   Updated: 2022/02/24 11:23:59 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int tmp;
	int	i;

	i = s->top - 1;
	tmp = s->array[i];
	while (i > 0)
	{
		s->array[i] = s->array[i - 1];
		i--;
	}
	s->array[0] = tmp;
	write(1, label, 3);
}

void	rrotate(t_Stack *s, char *label)
{
	int tmp;
	int	i;

	i = 0;
	tmp = s->array[i];
	while (i < s->top - 1)
	{
		s->array[i] = s->array[i + 1];
		i++;
	}
	s->array[s->top - 1] = tmp;
	write(1, label, 4);
}

/*
 * sort a stack of 3 elements
 */
void	sort_3(t_Stack *s)
{
	t_Stack tmp;

	init_stack(&tmp, s->top);
	if (s->array[2] > s->array[1])
		swap(s, "sa\n");
	if (s->array[1] > s->array[0])
	{
		push(&tmp, pop(s), "pb\n");
		swap(s, "sa\n");
		push(s, pop(&tmp), "pa\n");
	}
	if (s->array[2] > s->array[1])
		swap(s, "sa\n");
	free(tmp.array);
}

/*
 * sort a stack of 4 elements
 * 
 */
void	sort_4(t_Stack *s)
{
	t_Stack tmp;
	int		i;
	int		min;
	int		pos;

	i = 0;
	// find min position
	min = s->array[0];
	pos = 0;
	init_stack(&tmp, s->top);
	printf("i %d, pos %d, min: %d\n", i, pos, min);
	while(i < s->top)
	{
		if (s->array[i] < min)
		{
			min = s->array[i];
			pos = i;
		}
		printf("i %d, pos %d, min: %d\n", i, pos, min);
		i++;
	}
	printf("Min pos: %d\n", pos);
	if (pos <= 1)
	{
		while (pos >= 0)
		{
			rrotate(s, "rra\n");
			pos--;
		}
	}
	else
	{
		while (pos < 3)
		{
			rotate(s, "ra\n");
			pos++;
		}
	}
	push(&tmp, pop(s), "pb\n");
	sort_3(s);
	push(s, pop(&tmp), "pa\n");
}

void	sort_stack(t_Stack *s)
{
	if (is_ordered(s) == 0)
		printf("OK: stack is ordered. Nothing todo!\n");
	else if (s->top == 2)
		swap(s, "sa\n");
	else if (s->top == 3)
		sort_3(s);
	else if (s->top == 4)
		sort_4(s);
	else
		printf("TODO\n");
}
