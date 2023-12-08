/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:58:26 by tpicchio          #+#    #+#             */
/*   Updated: 2023/12/07 19:27:42 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rx(t_list **stack)
{
	t_list	*first;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = (*stack)->next;
	ft_lstadd_back(stack, *stack);
	(*stack)->next = NULL;
	*stack = first;
}


void	ft_rrx(t_list **stack)
{
	t_list	*last;
	t_list	*second_last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = ft_lstlast(*stack);
	second_last = *stack;
	while (second_last->next != last)
		second_last = second_last->next;
	ft_lstadd_front(stack, last);
	second_last->next = NULL;
}


void	ft_rr(t_list **stack_a, t_list **stack_b)
{
	ft_rx(stack_a);
	ft_rx(stack_b);
}


void	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	ft_rrx(stack_a);
	ft_rrx(stack_b);
}


void	ft_px(t_list **stack_reciver, t_list **stack_giver)
{
	t_list	*tmp_giv;

	tmp_giv = (*stack_giver)->next;
	ft_lstadd_front(stack_reciver, *stack_giver);
	*stack_giver = tmp_giv;
}
