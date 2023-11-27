/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:02:41 by tpicchio          #+#    #+#             */
/*   Updated: 2023/11/27 18:30:18 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*set_stacks(t_list **stack_a, t_list **stack_b, t_list *not_push);

char	*ft_calculate(t_list **stack_a, t_list *not_push)
{
	t_list	*stack_b;
	t_list	*node;
	char	*moves;

	stack_b = NULL;
	moves = set_stacks(stack_a, &stack_b, not_push);
	//moves = ft_remove_ra(moves); rimuove tutti i ra alla fine TODO
	while (stack_b)
	{
		ft_set_obm_distb(stack_a, &stack_b);
		node = ft_obm_score(stack_b);
		moves = ft_push_best(stack_a, &stack_b, node, moves);
	}
	moves = ft_last_rotate(stack_a, moves);
	ft_print_status(*stack_a, stack_b, moves);
	return (moves);
}

char	*set_stacks(t_list **stack_a, t_list **stack_b, t_list *not_push)
{
	char	*moves;
	int		i;

	moves = ft_calloc(1, sizeof(char));
	i = ft_lstsize(*stack_a);
	while (moves && --i >= 0)
	{
		if (((t_data *)((*stack_a)->content))->index
			== ((t_data *)not_push->content)->index)
		{
			ft_rx(stack_a);
			moves = ft_strjoin(moves, "ra\n");
			ft_print_status(*stack_a, *stack_b, moves);
			if (not_push->next)
				not_push = not_push->next;
		}
		else
		{
			ft_px(stack_b, stack_a);
			moves = ft_strjoin(moves, "pb\n");
			ft_print_status(*stack_a, *stack_b, moves);
		}
	}
	return (moves);
}
/* char	*ft_remove_ra(char *moves)
{
	char	*new;
	int		size;
	int		cont;

	size = ft_strlen(moves) - 1;
	cont = 0;
	while (moves[size] == "ra" || moves[size] == '\n')
	{
		if (moves[size] == "ra")
			cont++;
		size--;
	}
	new = ft_calloc(ft_strlen(moves) - cont + 1, sizeof(char));
	ft_strlcpy(new, moves, ft_strlen(moves) - cont + 1);
	free(moves);
	return (new);
} */
