/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:00:31 by nlouro            #+#    #+#             */
/*   Updated: 2022/03/09 15:44:34 by nlouro           ###   ########.fr       */
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

void	raise_error_and_exit(void)
{
	write(2, "Error\n", 6);
	exit (0);
}

void	validate_and_load_input(t_Stack *st, char **array, int index, int min)
{
	while (index >= min)
	{
		if (validate_args(array, index) == 1)
			raise_error_and_exit();
		push(st, ft_atoi(array[index]), "no write");
		index--;
	}
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
	int		index;
	int		i;

	if (argc < 2)
		raise_error_and_exit();
	init_stack(&st, argc - 1);
	if (argc == 2)
	{
		//if (ft_strchr(argv[1], ' ') == NULL)
		//	exit(0);
		i = 0;
		while (i < ft_strlen(argv[1]))
		{
			if (!(ft_isdigit(argv[1][i]) != 0 || argv[1][i] == '-' || argv[1][i] == ' '))
			{
				//printf("%c\n", argv[1][i]); 
				raise_error_and_exit();
			}
			i++;
		}
		tmp = ft_split(argv[1], ' ');
		//if (tmp == NULL)
		//	raise_error_and_exit();
		index = 0;
		while (tmp[index] != NULL)
			index++;
		index--;
		validate_and_load_input(&st, tmp, index, 0);
		free(tmp);
	}
	else
		validate_and_load_input(&st, argv, argc - 1, 1);
	if (is_ordered(&st) != 0)
		sort_stack(&st);
	free(st.ar);
	return (0);
}
