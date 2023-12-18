/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:28:13 by tpicchio          #+#    #+#             */
/*   Updated: 2023/12/13 14:24:02 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sx(t_list **stack)
{
	t_list	*tmp;

	if (ft_lstsize(*stack) < 2)
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
