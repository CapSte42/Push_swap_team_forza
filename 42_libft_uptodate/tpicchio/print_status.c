/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:12:03 by tpicchio          #+#    #+#             */
/*   Updated: 2023/11/29 16:58:04 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_status(t_list *stack_a, t_list *stack_b, char *moves)
{
	printf("\033[2J\033[H");
	printf("\tStack A\t\tStack B\n");
	while (stack_a || stack_b != NULL)
	{
		if (stack_a)
		{
			printf("\t   %zu\t\t   ", ((t_data *)stack_a->content)->index);
			stack_a = stack_a->next;
		}
		else
			printf("\t\t\t   ");
		if (stack_b != NULL)
		{
			printf("%zu\n", ((t_data *)stack_b->content)->index);
			stack_b = stack_b->next;
		}
		else
			printf("\n");
	}
	printf("Moves:%s\n", moves);
	sleep(1);
}

void ft_animation(t_list *stack_a, t_list *stack_b, char *moves)
{
	char	**split;
	int		i;

	split = ft_split(moves, '\n');
	i = 0;
	while (split[i])
	{
		if (split[i][0] == 's' && split[i][1] == 'a' && split[i][2] == '\0')
		{
			ft_sx(&stack_a);
			ft_print_status(stack_a, stack_b, split[i]);
		}
		else if (split[i][0] == 's' && split[i][1] == 'b' && split[i][2] == '\0')
		{
			ft_sx(&stack_b);
			ft_print_status(stack_a, stack_b, split[i]);
		}
		else if (split[i][0] == 's' && split[i][1] == 's' && split[i][2] == '\0')
		{
			ft_sx(&stack_a);
			ft_sx(&stack_b);
			ft_print_status(stack_a, stack_b, split[i]);
		}
		else if (split[i][0] == 'p' && split[i][1] == 'a' && split[i][2] == '\0')
		{
			ft_px(&stack_a, &stack_b);
			ft_print_status(stack_a, stack_b, split[i]);
		}
		else if (split[i][0] == 'p' && split[i][1] == 'b' && split[i][2] == '\0')
		{
			ft_px(&stack_b, &stack_a);
			ft_print_status(stack_a, stack_b, split[i]);
		}
		else if (split[i][0] == 'r' && split[i][1] == 'a' && split[i][2] == '\0')
		{
			ft_rx(&stack_a);
			ft_print_status(stack_a, stack_b, split[i]);
		}
		else if (split[i][0] == 'r' && split[i][1] == 'b' && split[i][2] == '\0')
		{
			ft_rx(&stack_b);
			ft_print_status(stack_a, stack_b, split[i]);
		}
		else if (split[i][0] == 'r' && split[i][1] == 'r' && split[i][2] == '\0')
		{
			ft_rx(&stack_a);
			ft_rx(&stack_b);
			ft_print_status(stack_a, stack_b, split[i]);
		}
		else if (split[i][0] == 'r' && split[i][1] == 'r' && split[i][2] == 'a')
		{
			ft_rrx(&stack_a);
			ft_print_status(stack_a, stack_b, split[i]);
		}
		else if (split[i][0] == 'r' && split[i][1] == 'r' && split[i][2] == 'b')
		{
			ft_rrx(&stack_b);
			ft_print_status(stack_a, stack_b, split[i]);
		}
		else if (split[i][0] == 'r' && split[i][1] == 'r' && split[i][2] == 'r')
		{
			ft_rrx(&stack_a);
			ft_rrx(&stack_b);
			ft_print_status(stack_a, stack_b, split[i]);
		}
		i++;
	}
	//ft_print_status(stack_a, stack_b, "");
}
