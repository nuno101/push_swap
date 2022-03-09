/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:00:31 by nlouro            #+#    #+#             */
/*   Updated: 2022/03/09 11:50:08 by nlouro           ###   ########.fr       */
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

int	validate_args(char **argv, int index)
{
	int	error;
	int	val;

	error = 0;
	if (ft_is_int(argv[index]))
	{
		val = ft_atoi(argv[index]);
		if (ft_is_duplicate(argv, index, val))
			error = 1;
	}
	else
		error = 1;
	return (error);
}

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
	char	**tmp;
	int		i;

	if (argc < 2)
		raise_error_and_exit();
	init_stack(&st, argc - 1);
	if (argc == 2)
	{
		tmp = ft_split(argv[1], ' ');
		i = 0;
		while (tmp[i] != NULL)
			i++;
		i--;
		while (i >= 0)
		{
			if (validate_args(tmp, i) == 1)
				raise_error_and_exit();
			push(&st, ft_atoi(tmp[i]), "no write");
			i--;
		}
		free(tmp);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			if (validate_args(argv, argc - i) == 1)
				raise_error_and_exit();
			push(&st, ft_atoi(argv[argc - i]), "no write");
			i++;
		}
	}
	show_stack(&st);
	if (is_ordered(&st) != 0)
		sort_stack(&st);
	show_stack(&st);
	free(st.ar);
	return (0);
}
