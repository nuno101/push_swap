/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:01:38 by nlouro            #+#    #+#             */
/*   Updated: 2022/01/22 18:24:19 by nlouro           ###   ########.fr       */
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
