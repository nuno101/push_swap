/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:00:31 by nlouro            #+#    #+#             */
/*   Updated: 2022/03/12 20:20:51 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	validate_and_load_input(t_Stack *st, char **array, int index, int min)
{
	int	val;

	init_stack(st, index + min);
	while (index >= min)
	{
		if (ft_is_int(array[index]))
		{
			val = ft_atoi(array[index]);
			if (ft_is_duplicate(array, index, val, min))
				raise_error_and_exit();
		}
		else
			raise_error_and_exit();
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

void	free_mem(char **tmp, int i)
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
}

void	validate_allowed_chars(char *str)
{
	int	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (!(isdgt(str[i]) != 0 || str[i] == '-' || str[i] == ' '))
			raise_error_and_exit();
		i++;
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

	tmp = NULL;
	if (argc < 2)
		exit(0);
	if (argc == 2)
	{
		validate_allowed_chars(argv[1]);
		tmp = ft_split(argv[1], ' ');
		if (tmp[0] == NULL)
			exit(0);
		validate_and_load_input(&st, tmp, array_len(tmp), 0);
		free_mem(tmp, array_len(tmp));
	}
	else
		validate_and_load_input(&st, argv, argc - 1, 1);
	sort_stack(&st);
	free(st.ar);
	return (0);
}
