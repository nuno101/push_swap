/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:00:31 by nlouro            #+#    #+#             */
/*   Updated: 2022/02/23 12:37:08 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_Stack *st, int size)
{
	st->array = malloc(size * sizeof(int));
	st->top = 0;
}

int		push(t_Stack *st, int val)
{
	st->array[st->top] = val;
	st->top++;
	return (val);
}


int		pop(t_Stack *st)
{
	int	val;

	val = st->array[st->top - 1];
	st->array[st->top - 1] = 0;
	st->top--;
	return (val);
}

void	show_stack(t_Stack *st)
{
	int i;

	i = 0;
	while(i < st->top)
	{
		printf("Stack [%i]: %i\n", i, st->array[i]);
		i++;
	}
	//printf("Stack len: %d\n", st->top);
}

/*
 * return 0 if stack is_ordered
 */
int		is_ordered(t_Stack *s)
{
	int i;
	int	val;

	i = s->top - 1;
	val = s->array[i];
	while(i > 0)
	{
		i--;
		if (s->array[i] > val)
			val = s->array[i];
		else
		{
			i = -1;
			break;	
		}
	}
	return (i);
}

int	main(int argc, char **argv)
{
	t_Stack	st;
	t_Stack	tmp;
	int		i;
	int		val;

	if (argc < 2)
	{
		printf("ERROR! Call as: push_swap <integers list>\n");
		return (1);
	}
	init_stack(&st, argc - 1);
	init_stack(&tmp, argc - 1);
	i = 0;
	while (i < argc - 1) 
	{
		// TODO: create ft_strict_atoi
		val = ft_atoi(argv[argc - 1 - i]);
		//if ((val == 0 && ft_strncmp(argv[i + 1], "0", 2) > 0) || (val == -1 && ft_strncmp(argv[i + 1], "-1", 2) > 0))
        if (0)
		{
			printf("Error: invalid parameter found\n");
			return(0);
		}
		if (val != push(&st, val))
			printf("Error: inserting value [%d]\n", val);
		i++;
	}
	if (is_ordered(&st) == 0)
	{
		show_stack(&st);
		printf("OK: ordered\n");
	}
	else
	{
		show_stack(&st);
		printf("NOK: sorting...\n");
		sort_stack(&st);
		show_stack(&st);
	}
	//printf("Pop value: %i\n", pop(&st));
	//show_stack(&st);
	return (0);
}
