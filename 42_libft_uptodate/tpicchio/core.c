/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:02:41 by tpicchio          #+#    #+#             */
/*   Updated: 2023/11/23 18:22:58 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*set_stacks(t_list **stack_a, t_list **stack_b, t_list *not_push);

char	*ft_calculate(t_list **stack_a, t_list *not_push)
{
	t_list	*head_ind;
	t_list	*head_npush;
	t_list	*stack_b;
	char	*moves;

	stack_b = malloc(sizeof(t_list));
	if (!stack_b)
		return (NULL);
	head_ind = *stack_a;
	head_npush = not_push;
	moves = set_stacks(stack_a, &stack_b, not_push);
	return (moves);
}

char	*set_stacks(t_list **stack_a, t_list **stack_b, t_list *not_push)
{
	char	*moves;

	moves = NULL;
	while (not_push)
	{
		while (*stack_a)
		{
			if (((t_data *)((*stack_a)->content))->index
				== ((t_data *)not_push->content)->index)
			{
				//ft_ra(stack_a);
				moves = ft_strjoin(moves, "ra\n");
				*stack_a = (*stack_a)->next;
				break ;
			}
			else
			{
				//ft_pb(stack_a, stack_b);
				moves = ft_strjoin(moves, "pb\n");
			}
			*stack_a = (*stack_a)->next;
		}
		not_push = not_push->next;
	}
	return (moves);
}

int main(void)
{
	t_list	*lst;
	t_list	*not_push;
	t_list	*new;
	t_data	*data;
	ssize_t	num[10] = {31, 100, 38, 98, 97, 66, 83, 18, 62, 82};
	size_t	index[10] = {2, 10, 3, 9, 8, 5, 7, 1, 4, 6};
	size_t	lis[6] = {2, 3, 5, 7, 1};
	int		i;

	data = malloc(sizeof(t_data));
	data->value = num[0];
	data->index = index[0];
	lst = ft_lstnew(data);
	i = 1;
	while (i < 10)
	{
		data = malloc(sizeof(t_data));
		data->value = num[i];
		data->index = index[i];
		new = ft_lstnew(data);
		ft_lstadd_back(&lst, new);
		i++;
	}
	data = malloc(sizeof(t_data));
	data->value = 0;
	data->index = lis[0];
	not_push = ft_lstnew(data);
	i = 1;
	while (i < 6)
	{
		data = malloc(sizeof(t_data));
		data->value = 0;
		data->index = lis[i];
		new = ft_lstnew(data);
		ft_lstadd_back(&not_push, new);
		i++;
	}
	ft_calculate(&lst, not_push);
	return (0);
}

/* t_list *temp;

	// Print lst
	temp = lst;
	while (temp)
	{
		printf("Value: %zd\tIndex: %ld\n", ((t_data *)(temp->content))->value, ((t_data *)(temp->content))->index);
		temp = temp->next;
	}

	// Print not_push
	temp = not_push;
	while (temp)
	{
		printf("IndexLIS: %ld\n", ((t_data *)(temp->content))->index);
		temp = temp->next;
	} */