/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:29:57 by fdonati           #+#    #+#             */
/*   Updated: 2023/10/14 20:15:08 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	node = ft_lstlast(*lst);
	node->next = new;
}

/*
int	main()
{
	t_list *lst;
	t_list *new;
	t_list *new2;

	lst = NULL;
	new = ft_lstnew("the forbidden one");
	new2 = ft_lstnew("necross");
	ft_lstadd_back(&lst, new);
	ft_lstadd_back(&lst, new2);
	printf("%s\n", (char *) lst->content);
	printf("%s\n", (char *) lst->next->content);
	printf("%s\n", (char *) lst->next->next->content);
	return (0);
}
*/