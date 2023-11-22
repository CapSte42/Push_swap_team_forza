/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:29:01 by smontuor          #+#    #+#             */
/*   Updated: 2023/11/22 06:16:48 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(ssize_t *a, ssize_t *b);
void	ft_quick_sort(ssize_t *stack, size_t start, size_t end);
t_list	*indexing(t_list *lst);

int	main(void)
{
	t_list	*lst;
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->index = 0;
	data->value = 56;
	lst = ft_lstnew((t_data *)data);
	data = malloc(sizeof(t_data));
	data->index = 0;
	data->value = 34;
	lst->next = ft_lstnew((t_data *)data);
	indexing(lst);
	return (0);
}

t_list	*indexing(t_list *lst)
{
	ssize_t	*stack;
	size_t	i;
	t_data	tmp;

	tmp = *(t_data *)lst->content;
	stack = malloc(sizeof(ssize_t) * ft_lstsize(lst));
	i = 0;
	while (lst)
	{
		stack[i] = tmp.value;
		lst = lst->next;
		i++;
	}
	ft_quick_sort(stack, 0, i - 1);
	printf("%ld %ld\n", stack[0], stack[1]);
	return (lst);
}

void	ft_quick_sort(ssize_t *stack, size_t start, size_t end)
{
	size_t	pivot;
	size_t	i;
	size_t	j;

	if (start < end)
	{
		pivot = start;
		i = start;
		j = end;
		while (i < j)
		{
			while (stack[i] <= stack[pivot] && i < end)
				i++;
			while (stack[j] > stack[pivot])
				j--;
			if (i < j)
				ft_swap(&stack[i], &stack[j]);
		}
		ft_swap(&stack[pivot], &stack[j]);
		ft_quick_sort(stack, start, j - 1);
		ft_quick_sort(stack, j + 1, end);
	}
}

void	ft_swap(ssize_t *a, ssize_t *b)
{
	ssize_t	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
