/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 06:18:17 by smontuor          #+#    #+#             */
/*   Updated: 2023/12/01 10:37:30 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char	**token;
	t_list	**lst;
	t_list	**lis;

	token = ft_split_input_into_token(ac,av);
	ft_check_token(token);
	ft_set_list(&lst);
	indexing(&lst);
	ft_set_swap(&lst);
	lis = ft_lis(lst);
	ft_printf(1, "%s", ft_calculate(&lst, lis));

    return (0);
}


