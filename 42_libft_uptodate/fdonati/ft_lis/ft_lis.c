/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:55:36 by fdonati           #+#    #+#             */
/*   Updated: 2023/11/23 19:29:34 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lis(t_list *lst)
{
	t_list	*lis_lst;
	t_list	*lis_lst_crcl;

	lis_lst = ft_lis_lin(lst, ft_lstsize(lst));
	if (lis_lst == NULL)
		return (NULL);
	lis_lst_crcl = ft_lis_crcl(lis_lst, lst);
	ft_lstadd_front(lis_lst, ft_lstlast(lis_lst_crcl));
	lis_lst = lis_lst_crcl;
	return (lis_lst);
}
