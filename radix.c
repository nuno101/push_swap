/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 11:20:53 by nlouro            #+#    #+#             */
/*   Updated: 2022/03/03 12:29:40 by nlouro           ###   ########.fr       */
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
	int max_pos;
	int pos;
	int i;

	array = malloc(s->top * sizeof(int));
	max_pos = get_max_pos(s);
	i = 0;
	while (i < s->top - 1)
	{
		pos = get_min_pos(s);
		array[i] = pos;
		s->ar[pos] = INT_MAX;
		//printf("i: %d, min pos: %d\n", i, pos);
		i++;
	}
	array[i] = max_pos;
	//printf("i: %d, min pos: %d\n", i, pos);
	free(s->ar);
	s->ar = array;
}

void	radix_sort(t_Stack *s)
{
	if (s == NULL)
		printf("radix_sort... TODO\n");
}
