/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:23:50 by tpicchio          #+#    #+#             */
/*   Updated: 2023/12/01 09:41:31 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct s_data
{
	size_t			index;
	ssize_t			value;
	ssize_t			dist;
	struct s_data	*obm;
}	t_data;

char	**ft_split_input_into_token(int ac, char **av);
void	ft_error(int error, char **token, t_list **lst);
void	ft_check_token(char **token);
char	*ft_calculate(t_list **stack_a, t_list *not_push);

#endif