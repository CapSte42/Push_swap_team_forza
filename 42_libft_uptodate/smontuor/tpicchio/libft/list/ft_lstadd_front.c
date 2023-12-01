/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:10:03 by smontuor          #+#    #+#             */
/*   Updated: 2023/11/27 16:50:29 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

/*Parameters lst:
	The address of a pointer to the first link of
	a list.
	new: The address of a pointer to the node to be
	added to the list.
Return value
	None
External functs
	None
Description
	Adds the node ’new’ at the beginning of the list.*/