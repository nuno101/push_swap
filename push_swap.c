/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:00:31 by nlouro            #+#    #+#             */
/*   Updated: 2022/03/10 17:40:28 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	init_stack(st, index + min);
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

int	array_len(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i] != NULL)
		i++;
	return (i - 1);
}

void	free_mem(t_Stack *s, char **tmp, int i)
{
	if (tmp != NULL)
	{
		while (i >= 0)
		{
			free(tmp[i]);
			i--;
		}
		free(tmp);
	}
	free(s->ar);
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

	tmp = NULL;
	i = 0;
	if (argc < 2)
		raise_error_and_exit(&st);
	while (argc == 2 && i < ft_strlen(argv[1]))
	{
		if (!(isdgt(argv[1][i]) != 0 || argv[1][i] == '-' || argv[1][i] == ' '))
			raise_error_and_exit(&st);
		i++;
	}
	if (argc == 2)
	{
		tmp = ft_split(argv[1], ' ');
		i = array_len(tmp);
		validate_and_load_input(&st, tmp, i, 0);
	}
	else
		validate_and_load_input(&st, argv, argc - 1, 1);
	sort_stack(&st);
	free_mem(&st, tmp, i);
	return (0);
}
