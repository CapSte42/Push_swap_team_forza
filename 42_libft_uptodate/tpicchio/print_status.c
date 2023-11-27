/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:12:03 by tpicchio          #+#    #+#             */
/*   Updated: 2023/11/27 18:30:58 by tpicchio         ###   ########.fr       */
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
			printf("\t   %ld\t\t   ", ((t_data *)stack_a->content)->index);
			stack_a = stack_a->next;
		}
		else
			printf("\t\t\t   ");
		if (stack_b != NULL)
		{
			printf("%ld\n", ((t_data *)stack_b->content)->index);
			stack_b = stack_b->next;
		}
		else
			printf("\n");
	}
	printf("Moves:\n%s", moves);
	sleep(1);
}
