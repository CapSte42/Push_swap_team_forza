/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:27:30 by fdonati           #+#    #+#             */
/*   Updated: 2023/11/26 17:45:27 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_data
{
	size_t			index;
	ssize_t			value;
	ssize_t			dist;
	struct s_data	*obm;
}	t_data;

size_t	ft_min_index(t_list *stack_a);
t_data	*ft_set_obm_dista(t_list **stack_a, size_t index);
void	ft_set_obm_distb(t_list **stack_a, t_list **stack_b);
size_t	ft_bggr(ssize_t a, ssize_t b);
ssize_t	ft_smllr(ssize_t a, ssize_t b);
size_t	ft_mod(ssize_t a);
size_t	ft_calc_score(t_data *content);
t_list	*ft_obm_score(t_list *stack_b);

#endif