/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 00:32:15 by nlouro            #+#    #+#             */
/*   Updated: 2022/03/08 12:21:43 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * sort a stack of 3 elements
 * (3 1 2), (3 2 1), (2 1 3), (1 3 2), (2 3 1)
 */
void	sort_3(t_Stack *s)
{
	if (s->ar[0] > s->ar[1] && s->ar[1] < s->ar[2] && s->ar[0] < s->ar[2])
		rotate(s, "ra\n");
	else if (s->ar[0] < s->ar[1] && s->ar[1] < s->ar[2])
	{
		swap(s, "sa\n");
		rrotate(s, "rra\n");
	}
	else if (s->ar[0] > s->ar[1] && s->ar[0] > s->ar[2] && s->ar[1] < s->ar[2])
		swap(s, "sa\n");
	else if (s->ar[0] < s->ar[1] && s->ar[1] > s->ar[2] && s->ar[0] > s->ar[2])
	{
		swap(s, "sa\n");
		rotate(s, "ra\n");
	}
	else if (s->ar[0] < s->ar[1] && s->ar[1] > s->ar[2] && s->ar[0] < s->ar[2])
		rrotate(s, "rra\n");
}

/*
 * find min position
 */
int	get_min_pos(t_Stack *s)
{
	int	i;
	int	min;
	int	pos;

	i = 0;
	min = s->ar[0];
	pos = 0;
	while (i < s->top)
	{
		if (s->ar[i] < min)
		{
			min = s->ar[i];
			pos = i;
		}
		i++;
	}
	//printf("Min pos: %d val: %d\n", pos, min);
	return (pos);
}

/*
 * find the second  min position
 */
int	get_min2_pos(t_Stack *s, int pos1)
{
	int	i;
	int	min;
	int	min2;
	int	pos;

	i = 0;
	min = s->ar[pos1];
	min2 = s->ar[0];
	pos = 0;
	while (i < s->top)
	{
		if (s->ar[i] != min && s->ar[i] < min2)
		{
			min2 = s->ar[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

int	get_max_pos(t_Stack *s)
{
	int	i;
	int	val;
	int	pos;

	i = 0;
	val = s->ar[0];
	pos = 0;
	while (i < s->top)
	{
		if (s->ar[i] > val)
		{
			val = s->ar[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

/*
 * sort a stack of 4 elements
 */
void	sort_4(t_Stack *s, t_Stack *tmp)
{
	int	pos;

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
	push(tmp, pop(s), "pb\n");
	sort_3(s);
	push(s, pop(tmp), "pa\n");
}

/*
 * sort a stack of 5 elements
 */
void	sort_5(t_Stack *s, t_Stack *tmp)
{
	int	pos;
	int	pos2;
	int	min2;

	pos = get_min_pos(s);
	pos2 = get_min2_pos(s, pos);
	min2 = s->ar[get_min2_pos(s, pos)];
	if (pos == 4 || pos2 == 4)
		push(tmp, pop(s), "pb\n");
	if (pos == 0 || pos2 == 0)
	{
		rrotate(s, "rra\n");
		pos--;
		pos2--;
		push(tmp, pop(s), "pb\n");
	}
	if (s->top == 3)
		sort_3(s);
	else if (s->top == 4)
	{
		sort_4(s, tmp);
		push(tmp, pop(s), "pb\n");
	}
	else
	{
		while (s->top > 3)
		{
			if (pos < 3 && pos2 < 3)
				rrotate(s, "rra\n");
			else
				rotate(s, "ra\n");
			if (s->ar[s->top - 1] <= min2 )
				push(tmp, pop(s), "pb\n");
		}
	}
	sort_3(s);
	push(s, pop(tmp), "pa\n");
	push(s, pop(tmp), "pa\n");
	if (is_ordered(s) != 0)
		swap(s, "sa\n");
}

void	sort_stack(t_Stack *s)
{
	t_Stack	tmp;
	int		slen;

	init_stack(&tmp, s->top);
	if (is_ordered(s) == 0)
		printf("OK: stack is ordered. Nothing todo!\n");
	else if (s->top == 2)
		swap(s, "sa\n");
	else if (s->top == 3)
		sort_3(s);
	else if (s->top == 4)
		sort_4(s, &tmp);
	else if (s->top == 5)
		sort_5(s, &tmp);
	else
	{
		normalise(s);
		//printf("Normalised...\n");
		//show_stack(s);
		slen = s->top;
		radix_sort(s, &tmp, slen);
	}
	free(tmp.ar);
}
