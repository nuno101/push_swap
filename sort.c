/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: nlouro <nlouro@student.42heilbronn.de>	 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/02/23 12:13:52 by nlouro			#+#	#+#			 */
/*   Updated: 2022/03/03 11:18:35 by nlouro           ###   ########.fr       */
/*																			*/
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
	int		i;
	int		min;
	int		pos;

	i = 0;
	min = s->ar[0];
	pos = 0;
	//printf("i %d, pos %d, min: %d\n", i, pos, min);
	while (i < s->top)
	{
		if (s->ar[i] < min)
		{
			min = s->ar[i];
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
	val = s->ar[0];
	pos = 0;
	//printf("i %d, pos %d, min: %d\n", i, pos, min);
	while (i < s->top)
	{
		if (s->ar[i] > val)
		{
			val = s->ar[i];
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
	t_Stack	tmp;
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
	{
		normalise(s);
		radix_sort(s);
	}
}
