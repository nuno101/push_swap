/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:00:31 by nlouro            #+#    #+#             */
/*   Updated: 2022/03/07 17:09:41 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
 * validate user input
 * initialise stack with user input
 */
int	main(int argc, char **argv)
{
	t_Stack	st;
	int		i;
	int		val;

	if (argc < 3)
	{
		//printf("ERROR! Call as: push_swap <integers list>\n");
		write(1, "Error\n", 6);
		return (1);
	}
	init_stack(&st, argc - 1);
	i = 1;
	while (i < argc)
	{
		if (ft_is_int(argv[argc - i]))
		{
			val = ft_atoi(argv[argc - i]);
			if (ft_is_duplicate(argv, argc - i, val))
			{
				write(1, "Error\n", 6);
				exit (0);
			}
		}
		else
		{
			write(1, "Error\n", 6);
			exit (0);
		}
		if (val != _push(&st, val))
			printf("Error: inserting value [%d]\n", (int) val);
		i++;
	}
	//show_stack(&st);
	sort_stack(&st);
	//show_stack(&st);
	free(st.ar);
	return (0);
}
