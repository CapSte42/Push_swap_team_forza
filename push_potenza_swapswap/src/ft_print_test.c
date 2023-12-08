/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:30:10 by fdonati           #+#    #+#             */
/*   Updated: 2023/12/08 15:40:25 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_test(t_list *stack_a, t_list *stack_b, t_list *lis)
{
	t_list	*node_a;
	t_list	*node_b;
	t_list	*node_lis;

	node_a = stack_a;
	node_b = stack_b;
	node_lis = lis;
	printf("lis\tstack_a\tstack_b\n");
	while(node_lis || node_a || node_b)
	{
		if (node_lis)
		{
			printf("%zu\t ", (*(size_t *)(node_lis->content)));
			node_lis = node_lis->next;
		}
		else
			printf("\t ");
		if (node_a)
		{
			printf("%zu\t      ", ((t_data *)(node_a->content))->index);
			node_a = node_a->next;
		}
		else
			printf("\t      ");
		if (node_b)
		{
			printf("%zu\t", ((t_data *)(node_b->content))->index);
			node_b = node_b->next;
		}
		else
			printf("\t");
		printf("\n");
	}
}
