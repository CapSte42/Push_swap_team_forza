/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_obm_dist_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:16:54 by fdonati           #+#    #+#             */
/*   Updated: 2023/11/26 18:17:17 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_max_index(t_list *stack_a)
{
	t_list	*node;
	size_t	index;

	index = 500;
	while (index > 0)
	{
		node = stack_a;
		while (node != NULL)
		{
			if (((t_data *)node->content)->index == index)
				return (index);
			node = node->next;
		}
		index--;
	}
	return (0);										// non dovrebbe mai arrivare qui, errore
}

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
