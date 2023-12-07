/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_crcl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:55:52 by fdonati           #+#    #+#             */
/*   Updated: 2023/12/07 10:41:04 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static t_list	*ft_lstcutm(t_list *lst, size_t m, int *error)
{
	t_list	*cutm_lst;
	t_list	*node;

	cutm_lst = NULL;
	while (lst != NULL)
	{
		if ((((t_data *) lst->content)->index) > m)
		{
			node = ft_lstnew(lst->content);
			if (node == NULL)
			{
				*error = 4;
				ft_lstclean(&cutm_lst);
				return (NULL);
			}
			ft_lstadd_back(&cutm_lst, node);
		}
		lst = lst->next;
	}
	return (cutm_lst);
}

static int	ft_lis_crcl_indx(t_list *lis_lst, t_list *lst, size_t m, int *error)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		if (*(size_t *) lis_lst->content == (((t_data *) lst->content)->index))
			return (i);
		if ((((t_data *) lst->content)->index) > m)
			i++;
		lst = lst->next;
	}
	*error = 3;
	return (-1);
}

t_list	*ft_lis_crcl(t_list *lis_lst, t_list *lst, int *error)
{
	size_t	m;
	int		n;
	t_list	*cutm_lst;
	t_list	*lis_lst_crcl;

	m = (*(size_t *) ft_lstlast(lis_lst)->content);
	n = ft_lis_crcl_indx(lis_lst, lst, m, error);
	if (n == 0 || n == -1)
		return (NULL);
	cutm_lst = ft_lstcutm(lst, m, error);
	if (cutm_lst == NULL)
		return (NULL);
	lis_lst_crcl = ft_lis_lin(cutm_lst, n);
	ft_lstclean(&cutm_lst);
	if (lis_lst_crcl == NULL)
	{
		*error = 4;
		return (NULL);
	}
	return (lis_lst_crcl);
}
