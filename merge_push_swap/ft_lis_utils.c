/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:58:19 by fdonati           #+#    #+#             */
/*   Updated: 2023/12/01 12:56:13 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_list	*ft_lstcutm(t_list *lst, size_t m, int *error)
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
				*error = -4;
				ft_lstclear(&cutm_lst, free);
				return (NULL);
			}
			ft_lstadd_back(&cutm_lst, node);
		}
		lst = lst->next;
	}
	return (cutm_lst);
}
