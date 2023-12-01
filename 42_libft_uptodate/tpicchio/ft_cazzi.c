/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cazzi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:25:41 by fdonati           #+#    #+#             */
/*   Updated: 2023/11/29 18:30:24 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_cazzi(t_list **stack_a, t_list **stack_b,
			size_t size, char *moves)
{
	if (((((t_data *)(*stack_a)->content)->index)
		> (((t_data *)(*stack_a)->next->content)->index))
		&& (((((t_data *)(*stack_a)->content)->index) > size / 2
		&& (((t_data *)(*stack_a)->next->content)->index) > size / 2)
		|| ((((t_data *)(*stack_a)->content)->index) <= size / 2
		&& (((t_data *)(*stack_a)->next->content)->index) <= size / 2)))
	{
		if (*stack_b != NULL && (*stack_b)->next != NULL)
		{
			if (((((t_data *)(*stack_b)->content)->index)
				< (((t_data *)(*stack_b)->next->content)->index))
				&& (((((t_data *)(*stack_b)->content)->index) > size / 2
				&& (((t_data *)(*stack_b)->next->content)->index) > size / 2)
				|| ((((t_data *)(*stack_b)->content)->index) <= size / 2
				&& (((t_data *)(*stack_b)->next->content)->index) <= size / 2)))
			{
				ft_ss(stack_a, stack_b);
				moves = ft_strjoin(moves, "ss\n");
			}
		}
		else
		{
			ft_sx(stack_a);
			moves = ft_strjoin(moves, "sa\n");
		}
	}
	return (moves);
}
