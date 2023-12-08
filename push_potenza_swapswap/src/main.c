/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:39:29 by tpicchio          #+#    #+#             */
/*   Updated: 2023/12/08 13:21:53 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char	**token;
	char	*moves;
	t_list	*lst;
	t_list	*lis;

	token = ft_split_input_into_token(ac, av);
	ft_check_token(token);
	ft_set_list(&lst, token);
	ft_free_matrix(token);
	ft_set_index(&lst);
	if (ft_lstsize(lst) > 2)
		ft_set_swap(&lst);
	lis = ft_lis(&lst);
	moves = ft_push_swap(&lst, lis);
	ft_printf(1, "%s", moves);
	free(moves);
	return (0);
}
