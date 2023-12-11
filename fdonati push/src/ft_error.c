/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:30:57 by fdonati           #+#    #+#             */
/*   Updated: 2023/12/11 13:30:59 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int error, char **token, t_list **lst)
{
	if (token)
		ft_free_matrix(token);
	if (lst)
		ft_lstclear(lst, free);
	if (error == 1)
		ft_printf(2, "Error\n");
	if (error == 2)
		ft_printf(2, "Error\n");
	if (error == 3)
		ft_printf(2, "Error\n");
	if (error == 4)
		ft_printf(2, "Error\n");
	if (error == 5)
		ft_printf(2, "Error: ...-0? Really?\n");
	if (error < 0)
		return ;
	exit(error);
}
