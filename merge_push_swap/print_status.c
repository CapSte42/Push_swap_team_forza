/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:12:03 by tpicchio          #+#    #+#             */
/*   Updated: 2023/11/30 15:41:26 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_status(t_list *lis, t_list *stack_a, t_list *stack_b, char *moves)
{
	printf("\033[2J\033[H");
	printf("L.I.S.\tStack A\tStack B\n");
	while (stack_a || stack_b != NULL)
	{
		if (lis)
		{
			printf("  %zu\t   ", (*(size_t *)lis->content));
			lis = lis->next;
		}
		else
			printf("\t   ");
		if (stack_a)
		{
			printf("%zu\t   ", ((t_data *)stack_a->content)->index);
			stack_a = stack_a->next;
		}
		else
			printf("\t   ");
		if (stack_b != NULL)
		{
			printf("%zu\n", ((t_data *)stack_b->content)->index);
			stack_b = stack_b->next;
		}
		else
			printf("\n");
	}
	printf("\nMove:%s\n", moves);
	sleep(1);
}

void ft_animation(t_list *lis, t_list *stack_a, t_list *stack_b, char *moves)
{
	char	**split;
	int		i;

	split = ft_split(moves, '\n');
	i = 0;
	while (split[i])
	{
		if (split[i][0] == 's' && split[i][1] == 'a' && split[i][2] == '\0')
			ft_sx(&stack_a);
		else if (split[i][0] == 's' && split[i][1] == 'b' && split[i][2] == '\0')
			ft_sx(&stack_b);
		else if (split[i][0] == 's' && split[i][1] == 's' && split[i][2] == '\0')
			ft_ss(&stack_a, &stack_b);
		else if (split[i][0] == 'p' && split[i][1] == 'a' && split[i][2] == '\0')
			ft_px(&stack_a, &stack_b);
		else if (split[i][0] == 'p' && split[i][1] == 'b' && split[i][2] == '\0')
			ft_px(&stack_b, &stack_a);
		else if (split[i][0] == 'r' && split[i][1] == 'a' && split[i][2] == '\0')
			ft_rx(&stack_a);
		else if (split[i][0] == 'r' && split[i][1] == 'b' && split[i][2] == '\0')
			ft_rx(&stack_b);
		else if (split[i][0] == 'r' && split[i][1] == 'r' && split[i][2] == '\0')
			ft_rr(&stack_a, &stack_b);
		else if (split[i][0] == 'r' && split[i][1] == 'r' && split[i][2] == 'a')
			ft_rrx(&stack_a);
		else if (split[i][0] == 'r' && split[i][1] == 'r' && split[i][2] == 'b')
			ft_rrx(&stack_b);
		else if (split[i][0] == 'r' && split[i][1] == 'r' && split[i][2] == 'r')
			ft_rrr(&stack_a, &stack_b);
		ft_print_status(lis, stack_a, stack_b, split[i]);
		i++;
	}
	printf("\nAll moves:\n%stot: %d\n", moves, i);
}
