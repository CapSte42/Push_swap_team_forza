/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:29:01 by tpicchio          #+#    #+#             */
/*   Updated: 2023/11/22 16:53:08 by tpicchio         ###   ########.fr       */
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

/* int	main(void)
{
	t_list	**lst;
	t_list	*new;
	t_data	*data;
	int		i;

	lst = malloc(sizeof(t_list *));
	*lst = NULL;
	i = 0;
	while (i < 10)
	{
		data = malloc(sizeof(t_data));
		data->value = rand() % 1000;
		data->index = 0;
		new = ft_lstnew(data);
		ft_lstadd_back(lst, new);
		i++;
	}
	indexing(lst);
	new = *lst;
	while (new)
	{
		printf("value: %ld\tindex: %ld\n",
			((t_data *)new->content)->value,
			((t_data *)new->content)->index);
		free(new->content);
		new = new->next;
		free(*lst);
		*lst = new;
	}
	free(new);
	free(*lst);
	free(lst);
	return (0);
} */
