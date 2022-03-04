/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 11:20:53 by nlouro            #+#    #+#             */
/*   Updated: 2022/03/04 16:53:05 by nlouro           ###   ########.fr       */
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
		i++;
	}
	array[max_pos] = i;
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
 * sort a stack of integers 
 * used for sorting 6+ elements
 */
void	radix_sort(t_Stack *s, t_Stack *tmp, int slen)
{
	int	i;
	int	j;
	int	k;
	int	pb;

	i = 0;
	j = slen - 1;
	k = 0;
	pb = 0;

	while (i < base2_bits(slen))
	{
		//printf("sorting bit %d\n", i);
		while (k < slen)
		{
			//printf("j: %d value: %d >> i %d\n", j, s->ar[j], s->ar[j] >> i);
			if ((s->ar[j] >> i & 1) == 1)
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
				//push(tmp, pop(s), "pb\n");
				pb++;
				j--;
			}
			k++;
		}
		//while (tmp->top > pb)
		while (tmp->top > 0)
			push(s, pop(tmp), "pa\n");
		pb = 0;
		j = slen - 1;
		k = 0;
		i++;
	}
}
