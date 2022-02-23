/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:01:38 by nlouro            #+#    #+#             */
/*   Updated: 2022/02/23 15:45:12 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> 
#include <stdlib.h> // used for exit
#include "libft.h"

typedef struct	Stack
{
	int *array;
	int	top;
}	t_Stack;

void	init_stack(t_Stack *st, int size);
int		push(t_Stack *st, int val);
int		pop(t_Stack *st);
void	sort_stack(t_Stack *s);
