/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:03:06 by fdonati           #+#    #+#             */
/*   Updated: 2023/10/13 16:16:40 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*node;

	size = 0;
	node = lst;
	while (node != NULL)
	{
		node = node->next;
		size++;
	}
	return (size);
}

/*
int	main()
{
	t_list *lst;
	t_list *new;
	
	lst = ft_lstnew("the forbidden one");
	new = ft_lstnew("exodia");
	ft_lstadd_front(&lst, new);
	printf("%d\n", ft_lstsize(lst));
	return (0);
}
*/