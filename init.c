/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronnde>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:39:17 by nlouro            #+#    #+#             */
/*   Updated: 2022/03/12 17:36:30 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	raise_error_and_exit()
{   
	write(2, "Error\n", 6);
	exit (0);
}

/*
 * initialise a basic stack structure based on an array 
 * top property keeps track of the stack next available position/ size 
 */
void	init_stack(t_Stack *st, int size)
{
	st->ar = malloc(size * sizeof(int));
	st->top = 0;
}

/*
 * alias to comply with norm
 */
int		isdgt(int c)
{
	return (ft_isdigit(c));
}
