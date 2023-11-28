/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:02:41 by tpicchio          #+#    #+#             */
/*   Updated: 2023/11/28 18:23:37 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <fcntl.h>

char	*set_stacks(t_list **stack_a, t_list **stack_b, t_list *not_push);

char	*ft_calculate(t_list **stack_a, t_list *not_push)
{
	t_list	*stack_b;
	t_list	*node;
	char	*moves;
	int		fd;

	stack_b = NULL;
	moves = set_stacks(stack_a, &stack_b, not_push);
	//ft_print_status(*stack_a, stack_b, moves);
	moves = ft_remove_ra(stack_a, moves);
	//ft_print_status(*stack_a, stack_b, moves);
	while (stack_b)
	{
		ft_set_obm_distb(stack_a, &stack_b);
		node = ft_obm_score(stack_b);
		moves = ft_push_best(stack_a, &stack_b, node, moves);
	}
	moves = ft_last_rotate(stack_a, moves);
	//printf("%s", moves);
	fd = open("moves.txt", O_RDWR);
	write(fd, moves, ft_strlen(moves));
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
			if (((t_data *)((*stack_a)->content))->dist == 1)
				moves = ft_strjoin(moves, "sa\n");
			ft_rx(stack_a);
			moves = ft_strjoin(moves, "ra\n");
			if (not_push->next)
				not_push = not_push->next;
		}
		else
		{
			if (((t_data *)((*stack_a)->content))->dist == 1)
				moves = ft_strjoin(moves, "sa\n");
			ft_px(stack_b, stack_a);
			moves = ft_strjoin(moves, "pb\n");
		}
	}
	return (moves);
}

char	*ft_remove_ra(t_list **stack_a, char *moves)
{
	char	*new;
	char	**split;
	int		size;
	int		cont;

	split = ft_split(moves, '\n');
	size = 0;
	while (split[size])
		size++;
	while (--size >= 0 && split[size][0] == 'r' && split[size][1] == 'a')
			ft_rrx(stack_a);
	new = ft_calloc(((size + 1) * 2) + 1, sizeof(char));
	cont = -1;
	while (++cont <= size)
	{
		new = ft_strjoin(new, split[cont]);
		new = ft_strjoin(new, "\n");
	}
	free(moves);
	return (new);
}
