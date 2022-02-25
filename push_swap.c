/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:00:31 by nlouro            #+#    #+#             */
/*   Updated: 2022/02/25 16:37:20 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_Stack *st, int size)
{
	st->ar = malloc(size * sizeof(int));
	st->top = 0;
}

/*
 * TODO: create ft_strict_atoi
 */
int	main(int argc, char **argv)
{
	t_Stack	st;
	int		i;
	int		val;

	if (argc < 2)
	{
		printf("ERROR! Call as: push_swap <integers list>\n");
		return (1);
	}
	init_stack(&st, argc - 1);
	i = 0;
	while (i < argc - 1)
	{
		val = ft_atoi(argv[argc - 1 - i]);
		//if ((val == 0 && ft_strncmp(argv[i + 1], "0", 2) > 0) || (val == -1 && ft_strncmp(argv[i + 1], "-1", 2) > 0))
		if (0)
		{
			printf("Error: invalid parameter found\n");
			return (0);
		}
		if (val != _push(&st, val))
			printf("Error: inserting value [%d]\n", val);
		i++;
	}
	show_stack(&st);
	sort_stack(&st);
	show_stack(&st);
	free(st.ar);
	return (0);
}
