/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis_crcl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:55:52 by fdonati           #+#    #+#             */
/*   Updated: 2023/11/29 17:12:49 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lis_crcl_indx(t_list *lis_lst, t_list *lst, size_t m)
{
	int		i;
	t_list	*node;

	i = 0;
	node = lst;
	while (node != NULL)
	{
		if (*(size_t *) lis_lst->content == (((t_data *) node->content)->index))
			return (i);
		if ((((t_data *) node->content)->index) > m)
			i++;
		node = node->next;
	}
	return (-1);
}

t_list	*ft_lis_crcl(t_list *lis_lst, t_list *lst)
{
	size_t	m;
	int		n;
	t_list	*cutm_lst;
	t_list	*lis_lst_crcl;

	m = (*(size_t *) ft_lstlast(lis_lst)->content);
	n = ft_lis_crcl_indx(lis_lst, lst, m);
	if (n == 0)
		return (NULL);							// non e' un errore
	cutm_lst = ft_lstcutm(lst, m);
	if (cutm_lst == NULL)
		return (NULL);
	lis_lst_crcl = ft_lis_lin(cutm_lst, n);
	ft_lstclean(&cutm_lst);
	if (lis_lst_crcl == NULL)
		return (NULL);
	return (lis_lst_crcl);
}
