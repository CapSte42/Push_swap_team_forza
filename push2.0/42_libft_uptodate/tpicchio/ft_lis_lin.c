/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis_lin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:29:43 by fdonati           #+#    #+#             */
/*   Updated: 2023/11/29 17:19:52 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lis_lst(t_list *lst, int parent[], int max_index)
{
	int		k;
	t_list	*lis_lst;
	t_list	*node;
	size_t	*nmb;

	k = max_index;
	lis_lst = NULL;
	while (k >= 0)
	{
		nmb = malloc(sizeof(size_t));
		if (nmb == NULL)
			return (NULL);
		*nmb = ft_lstto_nmb(lst, k);
		node = ft_lstnew(nmb);
		if (node == NULL)
		{
			free(nmb);
			ft_lstclear(&lis_lst, free);
			return (NULL);
		}
		ft_lstadd_front(&lis_lst, node);
		k = parent[k];
	}
	return (lis_lst);
}

void	ft_lis_algrtm(t_list *lst, int n, int lis[], int parent[])
{
	int	i;
	int	j;

	i = 1;
	while (i < n)
	{
		j = 0;
		while (j < i)
		{
			if (ft_lstto_nmb(lst, i) > ft_lstto_nmb(lst, j)
				&& lis[i] < lis[j] + 1)
			{
				lis[i] = lis[j] + 1;
				parent[i] = j;
			}
			j++;
		}
		i++;
	}
}

int	ft_lis_maxindex(int lis[], int n)
{
	int	i;
	int	max_index;

	i = 1;
	max_index = 0;
	while (i < n)
	{
		if (lis[max_index] <= lis[i])
		{
			max_index = i;
		}
		i++;
	}
	return (max_index);
}

t_list	*ft_lis_lin(t_list *lst, int n)
{
	int	lis[500];
	int	parent[500];
	int	max_index;
	int	i;

	i = 0;
	while (i < n)
	{
		lis[i] = 1;
		parent[i] = -1;
		i++;
	}
	ft_lis_algrtm(lst, n, lis, parent);
	max_index = ft_lis_maxindex(lis, n);
	return (ft_lis_lst(lst, parent, max_index));
}
