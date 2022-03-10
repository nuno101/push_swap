/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 11:20:53 by nlouro            #+#    #+#             */
/*   Updated: 2022/03/10 17:19:56 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * return 0 if stack is_ordered
 */
int	is_ordered(t_Stack *s)
{
	int	i;
	int	val;

	i = s->top - 1;
	val = s->ar[i];
	while (i > 0)
	{
		i--;
		if (s->ar[i] > val)
			val = s->ar[i];
		else
		{
			i = -1;
			break ;
		}
	}
	return (i);
}

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
		i++;
	}
	array[max_pos] = i;
	free(s->ar);
	s->ar = array;
}

/*
 * return the nr of bits required to represent n
 */
int	base2_bits(int n)
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
 * radix sorter code
 * cache pb to avoid redundant pb+pa stack operations
 */
void	sort_stack_bits(t_Stack *s, t_Stack *tmp, int bit, int slen)
{
	int	index;
	int	i;
	int	pb;

	i = 0;
	pb = 0;
	index = slen - 1;
	while (i < slen)
	{
		if ((s->ar[index] >> bit & 1) == 1)
		{
			while (pb > 0)
			{
				push(tmp, pop(s), "pb\n");
				pb--;
			}
			rotate(s, "ra\n");
		}
		else
		{
			pb++;
			index--;
		}
	i++;
	}
}

/*
 * sort a stack of integers. Used for sorting 6+ elements
 * determine the bit length of the (normalised) values to sort
 */
void	radix_sort(t_Stack *s, t_Stack *tmp)
{
	int	bit;
	int	slen;

	normalise(s);
	bit = 0;
	slen = s->top;
	while (bit < base2_bits(slen))
	{
		sort_stack_bits(s, tmp, bit, slen);
		while (tmp->top > 0)
			push(s, pop(tmp), "pa\n");
		bit++;
	}
}
