/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:13:52 by nlouro            #+#    #+#             */
/*   Updated: 2022/02/24 09:02:29 by nlouro           ###   ########.fr       */
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

	init_stack(&tmp, s->top);
	if (s->array[3] > s->array[2])
		swap(s, "sa\n");

}

void	sort_stack(t_Stack *s)
{
	if (is_ordered(s) == 0)
		printf("OK: stack is ordered. Nothing todo!\n");
	else if (s->top == 2)
		swap(s, "sa\n");
	else if (s->top == 3)
		sort_3(s);
	else
		printf("TODO\n");
}
