/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:02:41 by tpicchio          #+#    #+#             */
/*   Updated: 2023/11/24 13:06:44 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_status(t_list *stack_a, t_list *stack_b, char *moves);
char	*set_stacks(t_list **stack_a, t_list **stack_b, t_list *not_push);

char	*ft_calculate(t_list **stack_a, t_list *not_push)
{
	t_list	*stack_b;
	char	*moves;

	stack_b = malloc(sizeof(t_list));
	if (!stack_b)
		return (NULL);
	moves = set_stacks(stack_a, &stack_b, not_push);
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

void	ft_print_status(t_list *stack_a, t_list *stack_b, char *moves)
{
	printf("\033[2J\033[H");
	printf("\tStack A\t\tStack B\n");
	while (stack_a)
	{
		if (stack_a)
		{
			printf("\t   %ld\t\t   ", ((t_data *)stack_a->content)->index);
			stack_a = stack_a->next;
		}
		if (stack_b->content)
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

/* int main(void)
{
	t_list	*lst;
	t_list	*not_push;
	t_list	*new;
	t_data	*data;
	ssize_t	num[10] = {31, 100, 38, 98, 97, 66, 83, 18, 82, 62};
	size_t	index[10] = {2, 10, 3, 9, 8, 5, 7, 1, 6, 4};
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
	printf("<%s>", ft_calculate(&lst, not_push));
	return (0);
} */

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