/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis_crcl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:55:52 by fdonati           #+#    #+#             */
/*   Updated: 2023/11/23 19:28:33 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lis_crcl_indx(t_list *lis_lst, t_list *lst, int m)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		if (*(int *) lis_lst->content == *(int *) lst->content)
			return (i);
		if (*(int *) lst->content > m)
			i++;
		lst = lst->next;
	}
	return (-1);
}

t_list	*ft_lis_crcl(t_list *lis_lst, t_list *lst)
{
	int		m;
	int		n;
	t_list	*cutm_lst;
	t_list	*lis_lst_crcl;

	m = (*(int *) ft_lstlast(lis_lst)->content);
	n = ft_lis_crcl_indx(lis_lst, lst, m);
	cutm_lst = ft_lstcutm(lst, m);
	if (cutm_lst == NULL)
		return (NULL);
	lis_lst_crcl = ft_lis_lin(cutm_lst, n);
	ft_lstclear(&cutm_lst, free);
	if (lis_lst_crcl == NULL)
		return (NULL);
	return (lis_lst_crcl);
}
