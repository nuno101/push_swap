/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:00:31 by nlouro            #+#    #+#             */
/*   Updated: 2022/02/24 09:09:03 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_Stack *st, int size)
{
	st->array = malloc(size * sizeof(int));
	st->top = 0;
}

int		_push(t_Stack *st, int val)
{
	st->array[st->top] = val;
	st->top++;
	return (val);
}

int		push(t_Stack *st, int val, char *label)
{
	val = _push(st, val);
	write(1, label, 3);
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

/*
 * display stack content from top to bottom
 */
void	show_stack(t_Stack *st)
{
	int i;

	i = st->top;
	while(i-- > 0)
		printf("Stack [%i]: %i\n", i, st->array[i]);
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
		// TODO: create ft_strict_atoi
		val = ft_atoi(argv[argc - 1 - i]);
		//if ((val == 0 && ft_strncmp(argv[i + 1], "0", 2) > 0) || (val == -1 && ft_strncmp(argv[i + 1], "-1", 2) > 0))
        if (0)
		{
			printf("Error: invalid parameter found\n");
			return(0);
		}
		if (val != _push(&st, val))
			printf("Error: inserting value [%d]\n", val);
		i++;
	}
	show_stack(&st);
	sort_stack(&st);
	show_stack(&st);
	free(st.array);
	//getchar();
	return (0);
}
