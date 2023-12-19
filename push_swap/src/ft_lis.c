/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:37:58 by tpicchio          #+#    #+#             */
/*   Updated: 2023/12/19 15:23:14 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_lis_algo(size_t *arr, size_t *lis, ssize_t *prev_ind, int size)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	while (++i < size)
	{
		j = -1;
		while (++j < i)
		{
			if (arr[j] < arr[i] && lis[j] + 1 > lis[i])
			{
				lis[i] = lis[j] + 1;
				prev_ind[i] = j;
			}
		}
	}
	max = 0;
	i = -1;
	while (++i < size)
		if (lis[i] > lis[max])
			max = i;
	return (max);
}

static int	ft_lst_to_arr(t_list *lst, size_t **arr)
{
	t_list	*tmp;
	int		i;

	*arr = malloc(sizeof(size_t) * ft_lstsize(lst));
	if (!*arr)
		return (0);
	i = 0;
	tmp = lst;
	while (tmp && *(size_t *)tmp->content != 1)
		tmp = tmp->next;
	while (tmp)
	{
		(*arr)[i] = *(size_t *)tmp->content;
		tmp = tmp->next;
		i++;
	}
	tmp = lst;
	while (tmp && *(size_t *)tmp->content != 1)
	{
		(*arr)[i] = *(size_t *)tmp->content;
		tmp = tmp->next;
		i++;
	}
	return (1);
}

static int	ft_set_arrays(size_t **lis, ssize_t **prev_ind, int size)
{
	int	i;

	*lis = malloc(sizeof(size_t) * size);
	*prev_ind = malloc(sizeof(ssize_t) * size);
	if (!*lis || !*prev_ind)
		return (0);
	i = -1;
	while (++i < size)
	{
		(*lis)[i] = 1;
		(*prev_ind)[i] = -1;
	}
	return (1);
}

static int	ft_find_lis(t_list **lis_lst, t_list *lst, int size)
{
	size_t	*new;
	size_t	*arr;
	size_t	*lis;
	ssize_t	*prev_ind;
	int		i;

	if (ft_set_arrays(&lis, &prev_ind, size) == 1
		&& ft_lst_to_arr(lst, &arr) == 1)
	{
		i = ft_lis_algo(arr, lis, prev_ind, size);
		while (i >= 0)
		{
			new = malloc(sizeof(size_t));
			if (!new)
			{
				ft_lstclear(lis_lst, free);
				ft_free_arrays((void *)&arr, (void *)&lis, (void *)&prev_ind);
				return (0);
			}
			*new = arr[i];
			ft_lstadd_front(lis_lst, ft_lstnew(new));
			i = prev_ind[i];
		}
	}
	return (ft_free_arrays((void *)&arr, (void *)&lis, (void *)&prev_ind));
}

t_list	*ft_lis(t_list *lst)
{
	t_list	*lis_lst;
	t_list	*tmp;
	t_list	*tmp2;
	size_t	rot;

	lis_lst = NULL;
	if (ft_find_lis(&lis_lst, lst, ft_lstsize(lst)) != 3)
		ft_error(2, NULL, &lst);
	tmp = lst;
	rot = 0;
	while (tmp && rot == 0)
	{
		tmp2 = lis_lst;
		while (tmp2)
		{
			if (*(size_t *)tmp->content == *(size_t *)tmp2->content)
				rot = *(size_t *)tmp2->content;
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	while (*(size_t *)lis_lst->content != rot)
		ft_rx(&lis_lst);
	return (lis_lst);
}
