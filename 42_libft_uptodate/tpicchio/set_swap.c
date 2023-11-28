/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:11:51 by tpicchio          #+#    #+#             */
/*   Updated: 2023/11/28 18:22:32 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_swap(t_list **lst)
{
	t_list	*tmp;
	t_list	*swap;

	tmp = *lst;
	while (tmp->next->next)
	{
		if (((t_data *)tmp->next->content)->index
			== ((t_data *)tmp->next->next->content)->index + 1)
		{
			swap = tmp->next;
			tmp->next = tmp->next->next;
			swap->next = tmp->next->next;
			tmp->next->next = swap;
			if ((*lst) == tmp->next)
				*lst = tmp;
			((t_data *)((*lst)->next->content))->dist = 1;
			tmp = tmp->next;
		}
		else
			tmp = tmp->next;
	}
	/* //print dist
	tmp = *lst;
	while (tmp)
	{
		printf("index: %zu\tdist: %zu\n", ((t_data *)tmp->content)->index, ((t_data *)tmp->content)->dist);
		tmp = tmp->next;
	} */
}
