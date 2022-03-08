/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:00:31 by nlouro            #+#    #+#             */
/*   Updated: 2022/03/08 16:32:44 by nlouro           ###   ########.fr       */
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

int		validate_args(int argc, char **argv, int i)
{
	int	error;
	int	val;

	error = 0;
	if (ft_is_int(argv[argc - i]))
	{
		val = ft_atoi(argv[argc - i]);
		if (ft_is_duplicate(argv, argc - i, val))
			error = 1;
	}
	else
		error = 1;
	return (error);
}

/*
 * return 0 if stack is_ordered
 */
int		is_ordered(t_Stack *s)
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

void	raise_error_and_exit(void)
{
	write(2, "Error\n", 6);
	exit (0);
}

/*
 * validate user input
 * initialise stack with user input
 * better output: printf("ERROR! Call as: push_swap <integers list>\n");
 */
int	main(int argc, char **argv)
{
	t_Stack	st;
	int		i;

	if (argc < 3)
		raise_error_and_exit();
	init_stack(&st, argc - 1);
	i = 1;
	while (i < argc)
	{
		if (validate_args(argc, argv, i) == 1)
			raise_error_and_exit();
		push(&st, ft_atoi(argv[argc - i]), "no write");
		i++;
	}
	if (is_ordered(&st) != 0)
		sort_stack(&st);
	free(st.ar);
	return (0);
}
