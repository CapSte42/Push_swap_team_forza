/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:50:36 by tpicchio          #+#    #+#             */
/*   Updated: 2023/12/07 11:28:10 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//															swap stack OK
void	ft_sx(t_list **stack)
{
	t_list	*tmp;

	/* if (*stack == NULL || ( *stack)->next == NULL)
		ft_ferror(); */
	tmp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	tmp->next = *stack;
	*stack = tmp;
}

//															swap both stack OK
void	ft_ss(t_list **stack_a, t_list **stack_b)
{
	ft_sx(stack_a);
	ft_sx(stack_b);
}
