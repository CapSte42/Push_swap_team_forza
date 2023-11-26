/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:32:17 by fdonati           #+#    #+#             */
/*   Updated: 2023/10/14 16:28:19 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void*))
{
	t_list	*node;

	node = lst;
	while (node != NULL)
	{
		f(node->content);
		node = node->next;
	}
}

/*
void	ft_f(void *content)
{
	printf("%s\n", (char *) content);
}

int	main()
{
	t_list *lst;
	t_list *new;
	void (*f)(void*);

	lst = ft_lstnew("the forbidden one");
	new = ft_lstnew("exodia");
	f = ft_f;
	ft_lstadd_front(&lst, new);
	ft_lstiter(lst, f);
	return (0);
}
*/