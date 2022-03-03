/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 11:20:53 by nlouro            #+#    #+#             */
/*   Updated: 2022/03/03 16:37:15 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
# define INT_MAX 2147483647

/*
 * create a new array with the indexes of each value
 * find the min value positions and insert them in an array
 */
void	normalise(t_Stack *s)
{
	int	*array;
	int	max_pos;
	int	pos;
	int	i;

	array = malloc(s->top * sizeof(int));
	max_pos = get_max_pos(s);
	i = 0;
	while (i < s->top - 1)
	{
		pos = get_min_pos(s);
		array[pos] = i;
		s->ar[pos] = INT_MAX;
		//printf("i: %d, min pos: %d\n", i, pos);
		i++;
	}
	array[max_pos] = i;
	//printf("i: %d, max pos: %d\n", i, max_pos);
	free(s->ar);
	s->ar = array;
}

/*
 * return the nr of bits required to represent n
 */
int		base2_bits(int n)
{
	int	bits;

	bits = 0;
	while (n > 0)
	{
		n = n / 2;
		bits++;
	}
	return (bits);
}

/*
 * sort a stack of 6+ elements
 */
void	radix_sort(t_Stack *s)
{
	t_Stack	tmp;
	int		max_bits;
	int		i;
	int		j;
	int		slen;

	init_stack(&tmp, s->top);
	max_bits = base2_bits(s->top);
	printf("bits: %d\n", max_bits);
	i = 0;
	slen = s->top;
	j = slen - 1;
	while (i < max_bits)
	{
		printf("sorting bit %d\n", i);
		while (j > 0)
		{
			if ((s->ar[j] >> i & 1) == 1)
				rotate(s, "ra\n");
			else
				push(&tmp, pop(s), "pb\n");
			j--;
		}
		while (tmp.top > 0)
			push(s, pop(&tmp), "pa\n");
		j = slen - 1;
		i++;
	}
}
