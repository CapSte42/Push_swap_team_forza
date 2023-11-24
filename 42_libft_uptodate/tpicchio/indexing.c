/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:29:01 by tpicchio          #+#    #+#             */
/*   Updated: 2023/11/24 17:23:00 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(ssize_t *a, ssize_t *b);
void	ft_quick_sort(ssize_t *stack, ssize_t start, ssize_t end);
t_list	**indexing(t_list **lst);
ssize_t	*ft_fill_stack(t_list **lst);

t_list	**indexing(t_list **lst)
{
	ssize_t	*stack;
	ssize_t	i;
	ssize_t	j;
	t_list	*tmp;

	tmp = *lst;
	stack = ft_fill_stack(lst);
	if (!stack)
		return (NULL);
	ft_quick_sort(stack, 0, ft_lstsize(*lst) - 1);
	tmp = *lst;
	i = ft_lstsize(*lst);
	while (tmp)
	{
		j = -1;
		while (++j < i)
			if (((t_data *)tmp->content)->value == stack[j])
				((t_data *)tmp->content)->index = j + 1;
		tmp = tmp->next;
	}
	free(stack);
	return (lst);
}

void	ft_quick_sort(ssize_t *stack, ssize_t start, ssize_t end)
{
	ssize_t	pivot;
	ssize_t	i;
	ssize_t	j;

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

ssize_t	*ft_fill_stack(t_list **lst)
{
	ssize_t	i;
	t_list	*tmp;
	ssize_t	*stack;

	tmp = *lst;
	stack = malloc(sizeof(ssize_t) * ft_lstsize(*lst));
	if (!stack)
		return (NULL);
	i = -1;
	while (tmp)
	{
		stack[++i] = ((t_data *)tmp->content)->value;
		tmp = tmp->next;
	}
	return (stack);
}

int main(void)
{
	t_list	*lst;
	t_list	*not_push;
	t_list	*new;
	t_data	*data;
	ssize_t	num[15] = {-292, -917, 242, -123, 69, -385, 58, 436, 807, -812, 730, -283, 343, -26, -792};
	//size_t	index[10] = {2, 10, 3, 9, 8, 5, 7, 6, 4, 1};
	size_t	lis[5] = {1, 4, 9, 13, 15};
	int		i;

	data = malloc(sizeof(t_data));
	data->value = num[0];
	data->index = 0;
	lst = ft_lstnew(data);
	i = 1;
	while (i < 15)
	{
		data = malloc(sizeof(t_data));
		data->value = num[i];
		data->index = 0;
		data->dist = 0;
		data->friend = NULL;
		new = ft_lstnew(data);
		ft_lstadd_back(&lst, new);
		i++;
	}
	data = malloc(sizeof(t_data));
	data->value = 0;
	data->index = lis[0];
	not_push = ft_lstnew(data);
	i = 1;
	while (i < 5)
	{
		data = malloc(sizeof(t_data));
		data->value = 0;
		data->index = lis[i];
		data->dist = 0;
		data->friend = NULL;
		new = ft_lstnew(data);
		ft_lstadd_back(&not_push, new);
		i++;
	}
	indexing(&lst);
	ft_calculate(&lst, not_push);
	return (0);
}

/* //print the index of each element of the list
	new = lst;
	while (new)
	{
		printf("value: %ld\tindex: %ld\n",
			((t_data *)new->content)->value,
			((t_data *)new->content)->index);
		new = new->next;
	}
	//print index of not_push
	new = not_push;
	while (new)
	{
		printf("%ld ", ((t_data *)new->content)->index);
		new = new->next;
	}
	printf("\n"); */