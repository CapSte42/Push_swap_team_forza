/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:09:27 by tpicchio          #+#    #+#             */
/*   Updated: 2023/12/13 14:24:02 by tpicchio         ###   ########.fr       */
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
		ft_printf(2, "Error\n");
	if (error < 0)
		return ;
	exit(error);
}
