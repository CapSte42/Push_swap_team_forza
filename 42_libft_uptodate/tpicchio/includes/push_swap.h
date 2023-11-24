/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:23:50 by tpicchio          #+#    #+#             */
/*   Updated: 2023/11/24 15:39:56 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_data
{
	size_t			index;
	ssize_t			value;
	size_t			dist;
	struct s_data	*friend;
}	t_data;

char	*ft_calculate(t_list **stack_a, t_list *not_push);
void	ft_px(t_list **stack_a, t_list **stack_b);
void	ft_rx(t_list **stack);

#endif