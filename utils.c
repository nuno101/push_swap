/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:00:31 by nlouro            #+#    #+#             */
/*   Updated: 2022/03/07 17:01:51 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int		ft_is_int(const char *str)
{
	int		i;
	int		sign;
	long	nr;

	i = 0;
	sign = 1;
	nr = 0;
	if (*(str + i) == '-')
	{
		sign = -1;
		i++;
	}
	if (!ft_isdigit(*(str + i)))
		return (0);
	while (ft_isdigit(*(str + i)))
	{
		nr = nr * 10 + (*(str + i) - '0');
		if (sign == 1 && nr > 2147483647)
			return (0);
		if (sign == -1 && nr > 2147483648)
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_duplicate(char **argv, int i, int val)
{
	int	j;

	j = 1;
	while (j < i)
	{
		if (val == ft_atoi(argv[j]))
			return (1);
		j++;
	}
	return (0);
}
