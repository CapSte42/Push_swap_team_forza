/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:58:26 by tpicchio          #+#    #+#             */
/*   Updated: 2023/11/24 15:47:08 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// 															rotate OK
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

//															push OK
void	ft_px(t_list **stack_reciver, t_list **stack_giver)
{
	t_list	*tmp_giv;

	/* if (*stack_giver == NULL)
		ft_ferror(); */
	tmp_giv = (*stack_giver)->next;
	ft_lstadd_front(stack_reciver, *stack_giver);
	*stack_giver = tmp_giv;
}

void	ft_swapx(t_list **stack)
{
	t_list	*tmp;

	/* if (*stack == NULL || (*stack)->next == NULL)
		ft_ferror(); */
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}