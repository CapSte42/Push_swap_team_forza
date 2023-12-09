/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:50:36 by tpicchio          #+#    #+#             */
/*   Updated: 2023/12/08 11:35:42 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	ft_sx(t_list **stack)
{
	t_list	*tmp;

	if (!*stack)
		return (1);
	tmp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	tmp->next = *stack;
	*stack = tmp;
	return (0);
}


int	ft_ss(t_list **stack_a, t_list **stack_b)
{
	return (ft_sx(stack_a) + ft_sx(stack_b));
}
