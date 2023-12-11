/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:24:56 by fdonati           #+#    #+#             */
/*   Updated: 2023/12/11 13:24:57 by fdonati          ###   ########.fr       */
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
