/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:00:31 by nlouro            #+#    #+#             */
/*   Updated: 2022/03/10 16:09:23 by nlouro           ###   ########.fr       */
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
 * display stack content from top to bottom
 */
void	show_stack(t_Stack *st)
{
	int	i;

	i = st->top;
	while (i-- > 0)
		printf("Stack [%i]: %i\n", i, st->ar[i]);
}

void	raise_error_and_exit(t_Stack *st)
{
	write(2, "Error\n", 6);
	free(st->ar);
	exit (0);
}

void	validate_and_load_input(t_Stack *st, char **array, int index, int min)
{
	int	error;
	int	val;

	error = 0;
	while (index >= min)
	{
		if (ft_is_int(array[index]))
		{
			val = ft_atoi(array[index]);
			if (ft_is_duplicate(array, index, val, min))
				raise_error_and_exit(st);
		}
		else
			raise_error_and_exit(st);
		push(st, ft_atoi(array[index]), "no write");
		index--;
	}
}

/*
 * validate user input
 * initialise stack with user input
 */
int	main(int argc, char **argv)
{
	t_Stack	st;
	char	**tmp;
	int		i;

	//init_stack(&st, argc - 1);
	tmp = NULL;
	i = 0;
	if (argc < 2)
		raise_error_and_exit(&st);
	if (argc == 2)
	{
		while (i < ft_strlen(argv[1]))
		{
			if (!(ft_isdigit(argv[1][i]) != 0 || argv[1][i] == '-' || argv[1][i] == ' '))
				raise_error_and_exit(&st);
			i++;
		}
		tmp = ft_split(argv[1], ' ');
		i = 0;
		while (tmp[i] != NULL)
			i++;
		init_stack(&st, i);
		validate_and_load_input(&st, tmp, i - 1, 0);
	}
	else
	{
		init_stack(&st, argc - 1);
		validate_and_load_input(&st, argv, argc - 1, 1);
	}
	if (is_ordered(&st) != 0)
		sort_stack(&st);
	if (tmp != NULL)
	{
		while (i >= 0)
		{
			free(tmp[i]);
			i--;
		}
		free(tmp);
	}
	free(st.ar);
	return (0);
}
