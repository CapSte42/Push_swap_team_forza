/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:29:01 by tpicchio          #+#    #+#             */
/*   Updated: 2023/12/04 09:43:02 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(ssize_t *a, ssize_t *b)
{
	ssize_t	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	ft_quick_sort(ssize_t *stack, ssize_t start, ssize_t end)
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

static ssize_t	*ft_fill_stack(t_list **lst)
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

void	**indexing(t_list **lst)
{
	ssize_t	*stack;
	ssize_t	i;
	ssize_t	j;
	t_list	*tmp;

	if (lst == NULL)
		ft_error(-3, NULL, NULL);
	tmp = *lst;
	stack = ft_fill_stack(lst);
	if (!stack)
		ft_error(-4, NULL, lst);
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
}
