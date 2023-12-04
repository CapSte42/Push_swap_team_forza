/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:58:19 by fdonati           #+#    #+#             */
/*   Updated: 2023/11/29 12:38:35 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_min_index(t_list *stack_a)
{
	t_list	*node;
	size_t	index;

	index = 1;
	while (index <= 500)
	{
		node = stack_a;
		while (node != NULL)
		{
			if (((t_data *)node->content)->index == index)
				return (index);
			node = node->next;
		}
		index++;
	}
	return (0);										// non dovrebbe mai arrivare qui, errore
}

void	ft_lstclean(t_list **lst)
{
	t_list	*node;
	t_list	*temp;

	node = *lst;
	while (node != NULL)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
	*lst = NULL;
}

size_t	ft_lstto_nmb(t_list *lst, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		lst = lst->next;
		i++;
	}
	return (((t_data *) lst->content)->index);
}

t_list	*ft_lstcutm(t_list *lst, size_t m)
{
	t_list	*cutm_lst;
	t_list	*node;

	cutm_lst = NULL;
	while (lst != NULL)
	{
		if ((((t_data *) lst->content)->index) > m)
		{
			node = ft_lstnew(lst->content);
			if (node == NULL)
			{
				ft_lstclear(&cutm_lst, free);
				return (NULL);
			}
			ft_lstadd_back(&cutm_lst, node);
		}
		lst = lst->next;
	}
	return (cutm_lst);
}
