/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:58:26 by tpicchio          #+#    #+#             */
/*   Updated: 2023/11/24 16:50:51 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// 															rotate stack OK
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

// 															reverse rotate OK
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

// 															rotate both stack OK
void	ft_rr(t_list **stack_a, t_list **stack_b)
{
	ft_rx(stack_a);
	ft_rx(stack_b);
}

// 															rrr OK
void	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	ft_rrx(stack_a);
	ft_rrx(stack_b);
}

//															push to stack OK
void	ft_px(t_list **stack_reciver, t_list **stack_giver)
{
	t_list	*tmp_giv;

	/* if (*stack_giver == NULL)
		ft_ferror(); */
	tmp_giv = (*stack_giver)->next;
	ft_lstadd_front(stack_reciver, *stack_giver);
	*stack_giver = tmp_giv;
}
