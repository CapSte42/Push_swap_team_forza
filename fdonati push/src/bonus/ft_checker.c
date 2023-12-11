/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:33:49 by fdonati           #+#    #+#             */
/*   Updated: 2023/12/11 13:33:50 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_put_message(int they_are_cool, int illegal_moves)
{
	if (they_are_cool == 1)
	{
		ft_printf(1, "OK");
		if (illegal_moves != 0)
			ft_printf(1, "but  with %d illegal moves", illegal_moves);
	}
	else
	{
		ft_printf(1, "KO");
		if (illegal_moves != 0)
			ft_printf(1, " with %d illegal moves", illegal_moves);
	}
	ft_printf(1, "\n");
}

int	main(int ac, char **av)
{
	char	**token;
	int		illegal_moves;
	int		they_are_cool;
	t_list	*stack_a;
	t_list	*stack_b;

	they_are_cool = 0;
	illegal_moves = 0;
	token = ft_split_input_into_token(ac, av);
	ft_check_token(token);
	ft_set_list(&stack_a, token);
	stack_b = NULL;
	illegal_moves = ft_parse_moves(&stack_a, &stack_b);
	they_are_cool = ft_stacks_are_cool(&stack_a, &stack_b);
	ft_free_matrix(token);
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	token = NULL;
	ft_put_message(they_are_cool, illegal_moves);
	return (0);
}
