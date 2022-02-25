/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronnde>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:40:51 by nlouro            #+#    #+#             */
/*   Updated: 2022/02/25 18:45:40 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_Stack *st, int size)
{
	st->ar = malloc(size * sizeof(int));
	st->top = 0;
}

int	main(int argc, char **argv)
{
	t_Stack	st;
	int		i;
	int		val;
	int		word;

	if (argc < 2)
	{
		printf("ERROR! Call as: checker <integers list>\n");
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
	word = getchar();
	printf("Word: [%d]\n", word);
	//show_stack(&st);
	free(st.ar);
	return (0);
}
