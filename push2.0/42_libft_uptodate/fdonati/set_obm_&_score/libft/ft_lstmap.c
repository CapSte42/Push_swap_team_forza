/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:23:02 by fdonati           #+#    #+#             */
/*   Updated: 2023/10/16 16:40:28 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*node;
	void	*content;

	if (lst == NULL)
		return (NULL);
	newlst = NULL;
	while (lst != NULL)
	{
		content = f(lst->content);
		node = ft_lstnew(content);
		if (node == NULL)
		{
			del(content);
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, node);
		lst = lst->next;
	}
	return (newlst);
}

/*
static void	ft_del(void *content)
{
	free(content);
}

static char	ft_f2(unsigned int i, char c)
{
	if (i % 2 == 0 && c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}

static void	*ft_f(void *c)
{
	return (ft_strmapi((char *) c, ft_f2));
}

int	main()
{
	t_list *lst;
	t_list *new;
	t_list *newlist;
	void *(*f)(void*);
	void (*del)(void*);

	lst = ft_lstnew("the forbidden one");
	new = ft_lstnew("exodia");
	f = ft_f;
	del = ft_del;
	ft_lstadd_front(&lst, new);
	newlist = ft_lstmap(lst, f, del);
	printf("%s\n", (char *) lst->content);
	printf("%s\n", (char *) lst->next->content);
	printf("%s\n", (char *) newlist->content);
	printf("%s\n", (char *) newlist->next->content);
	return (0);
}
*/