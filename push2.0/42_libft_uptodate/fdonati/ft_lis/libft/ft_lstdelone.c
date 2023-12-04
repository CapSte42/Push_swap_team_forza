/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:22:06 by fdonati           #+#    #+#             */
/*   Updated: 2023/10/13 17:52:18 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	del(lst->content);
	free(lst);
}

/*
void	ft_del(void *content)
{
	free(content);
}


int	main()
{
	t_list	*node;
	t_list	*node2;
	t_list	*node3;
	void	(*del)(void*);

	node = ft_lstnew(ft_strdup("exodia"));
	node2 = ft_lstnew(ft_strdup("the forbidden one"));
	node3 = ft_lstnew(ft_strdup("necross"));
	del = &ft_del;
	ft_lstadd_back(&node, node2);
	ft_lstadd_back(&node, node3);
	ft_lstdelone(node3, del);
	printf("%s\n", (char *) node->content);
	printf("%s\n", (char *) node->next->content);
	printf("%s\n", (char *) node->next->next->content);
	return (0);
}
*/