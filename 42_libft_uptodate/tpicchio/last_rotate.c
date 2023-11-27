/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:01:16 by tpicchio          #+#    #+#             */
/*   Updated: 2023/11/27 18:33:35 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static ssize_t	ft_min_dist(t_list *stack_a)
{
	t_list	*node;
	size_t	i;
	size_t	size;

	node = stack_a;
	i = 0;
	size = ft_lstsize(stack_a);
	while (((t_data *)node->content)->index != 1)
	{
		i++;
		node = node->next;
	}
	if (i <= size / 2)
		return (((t_data *)node->content)->dist = i);
	else
		return (((t_data *)node->content)->dist = i - size);
}

char	*ft_last_rotate(t_list **stack_a, char *moves)
{
	ssize_t	min_dist;

	min_dist = ft_min_dist(*stack_a);
	while (min_dist != 0)
	{
		if (min_dist > 0)
		{
			ft_rx(stack_a);
			moves = ft_strjoin(moves, "ra\n");
			ft_print_status(*stack_a, NULL, moves);
			min_dist--;
		}
		else if (min_dist < 0)
		{
			ft_rrx(stack_a);
			moves = ft_strjoin(moves, "rra\n");
			ft_print_status(*stack_a, NULL, moves);
			min_dist++;
		}
	}
	return (moves);
}
