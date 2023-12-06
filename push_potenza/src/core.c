/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:02:41 by tpicchio          #+#    #+#             */
/*   Updated: 2023/12/05 15:07:40 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_remove_ra(t_list **stack_a, char *moves)
{
	char	*new;
	char	**split;
	int		size;
	int		cont;

	split = ft_split(moves, '\n');
	size = 0;
	while (split[size])
		size++;
	while (size != 0 && split[size - 1][0] == 'r' && split[size - 1][1] == 'a')
	{
		ft_rrx(stack_a);
		size--;
	}
	new = ft_calloc(((size + 1) * 2), sizeof(char));
	cont = -1;
	while (++cont < size)
	{
		new = ft_strjoin(new, split[cont]);
		new = ft_strjoin(new, "\n");
	}
	free(moves);
	ft_free_matrix(split);
	return (new);
}

static char	*ft_set_stacks(t_list **stack_a, t_list **stack_b,
		t_list *lis, char *moves)
{
	int		i;

	i = ft_lstsize(*stack_a);
	while (moves && --i >= 0)
	{
		if (((t_data *)((*stack_a)->content))->dist == 1)
			moves = ft_strjoin(moves, "sa\n");
		if (((t_data *)((*stack_a)->content))->index
			== (*(size_t *)lis->content))
		{
			ft_rx(stack_a);
			moves = ft_strjoin(moves, "ra\n");
			if (lis->next)
				lis = lis->next;
		}
		else
		{
			ft_px(stack_b, stack_a);
			moves = ft_strjoin(moves, "pb\n");
		}
	}
	return (moves);
}

char	*ft_push_swap(t_list **stack_a, t_list *lis)
{
	t_list	*stack_b;
	t_list	*obm;
	char	*moves;

	stack_b = NULL;
	moves = ft_calloc(1, sizeof(char));
	moves = ft_set_stacks(stack_a, &stack_b, lis, moves);
	moves = ft_remove_ra(stack_a, moves);
	while (stack_b)
	{
		ft_set_obm_distb(stack_a, &stack_b);
		obm = ft_obm_score(stack_b);
		moves = ft_push_best(stack_a, &stack_b, obm, moves);
	}
	moves = ft_last_rotate(stack_a, moves);
	ft_lstclear(&stack_b, free);
	ft_lstclear(&lis, free);
	ft_lstclear(stack_a, free);
	return (moves);
}
