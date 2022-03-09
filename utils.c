/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:00:31 by nlouro            #+#    #+#             */
/*   Updated: 2022/03/09 12:41:17 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_int(const char *str)
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
	if (!ft_isdigit(*(str + i)))
		return (0);
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

/*
 * find min position
 */
int	get_min_pos(t_Stack *s)
{
	int	i;
	int	min;
	int	pos;

	i = 0;
	min = s->ar[0];
	pos = 0;
	while (i < s->top)
	{
		if (s->ar[i] < min)
		{
			min = s->ar[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

/*
 * find the second  min position
 */
int	get_min2_pos(t_Stack *s, int pos1)
{
	int	i;
	int	min;
	int	min2;
	int	pos;

	i = 0;
	min = s->ar[pos1];
	min2 = s->ar[0];
	pos = 0;
	while (i < s->top)
	{
		if (s->ar[i] != min && s->ar[i] < min2)
		{
			min2 = s->ar[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

int	get_max_pos(t_Stack *s)
{
	int	i;
	int	val;
	int	pos;

	i = 0;
	val = s->ar[0];
	pos = 0;
	while (i < s->top)
	{
		if (s->ar[i] > val)
		{
			val = s->ar[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}
