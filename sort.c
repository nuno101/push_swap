/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:13:52 by nlouro            #+#    #+#             */
/*   Updated: 2022/02/25 14:34:12 by nlouro           ###   ########.fr       */
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
 * (3 1 2), (3 2 1), (2 1 3), (1 3 2), (2 3 1)
 */
void	sort_3(t_Stack *s)
{
	// 3 1 2
	if (s->array[0] > s->array[1] && s->array[1] < s->array[2] && s->array[0] < s->array[2])
		rotate(s, "ra\n");
	// 3 2 1
    else if (s->array[0] < s->array[1] && s->array[1] < s->array[2])
    {   
		swap(s, "sa\n");
		rrotate(s, "rra\n");
    }
	// 2 1 3
    else if (s->array[0] > s->array[1] && s->array[0] > s->array[2] && s->array[1] < s->array[2])
		swap(s, "sa\n");
	// 1 3 2
    else if (s->array[0] < s->array[1] && s->array[1] > s->array[2] && s->array[0] > s->array[2])
	{
		swap(s, "sa\n");
		rotate(s, "ra\n");
	} 
	// 2 3 1
    else if (s->array[0] < s->array[1] && s->array[1] > s->array[2] && s->array[0] < s->array[2])
		rrotate(s, "rra\n");
}

/*
 * find min position
 */
int	get_min_pos(t_Stack *s)
{
	int		i;
	int		min;
	int		pos;

	i = 0;
	min = s->array[0];
	pos = 0;
	//printf("i %d, pos %d, min: %d\n", i, pos, min);
	while(i < s->top)
	{
		if (s->array[i] < min)
		{
			min = s->array[i];
			pos = i;
		}
		//printf("i %d, pos %d, min: %d\n", i, pos, min);
		i++;
	}
	//printf("Min pos: %d\n", pos);
	return (pos);
}

int	get_max_pos(t_Stack *s)
{
	int		i;
	int		val;
	int		pos;

	i = 0;
	val = s->array[0];
	pos = 0;
	//printf("i %d, pos %d, min: %d\n", i, pos, min);
	while(i < s->top)
	{
		if (s->array[i] > val)
		{
			val = s->array[i];
			pos = i;
		}
		//printf("i %d, pos %d, min: %d\n", i, pos, min);
		i++;
	}
	//printf("Max pos: %d\n", pos);
	return (pos);
}

/*
 * sort a stack of 4 elements
 * 
 */
void	sort_4(t_Stack *s)
{
	t_Stack tmp;
	int		pos;

	init_stack(&tmp, s->top);
	pos = get_min_pos(s);
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
