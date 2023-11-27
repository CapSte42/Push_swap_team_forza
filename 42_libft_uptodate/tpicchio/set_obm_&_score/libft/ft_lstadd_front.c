/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:45:03 by fdonati           #+#    #+#             */
/*   Updated: 2023/10/13 16:22:46 by fdonati          ###   ########.fr       */
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

/*
int	main()
{
	t_list *lst;
	t_list *new;

	lst = ft_lstnew(NULL);
	new = ft_lstnew("exodia");
	ft_lstadd_front(&lst, new);
	printf("%s\n", (char *) lst->content);
	printf("%s\n", (char *) lst->next->content);
	return (0);
}
*/
