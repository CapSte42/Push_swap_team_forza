/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:23:50 by tpicchio          #+#    #+#             */
/*   Updated: 2023/11/29 14:19:05 by tpicchio         ###   ########.fr       */
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
	ssize_t			dist;
	struct s_data	*obm;
}	t_data;

t_list	**indexing(t_list **lst);
char	*ft_calculate(t_list **stack_a, t_list *not_push);
char	*ft_push_best(t_list **stack_a, t_list **stack_b,
			t_list *node, char *moves);
char	*ft_last_rotate(t_list **stack_a, char *moves);
void	ft_set_swap(t_list **lst);

void	ft_rx(t_list **stack);
void	ft_rrx(t_list **stack);
void	ft_sx(t_list **stack);
void	ft_px(t_list **stack_a, t_list **stack_b);
void	ft_rr(t_list **stack_a, t_list **stack_b);
void	ft_rrr(t_list **stack_a, t_list **stack_b);
void	ft_ss(t_list **stack_a, t_list **stack_b);

t_list	*ft_lis(t_list *lst);
void	ft_lstclean(t_list **lst);
size_t	ft_lstto_nmb(t_list *lst, int index);
t_list	*ft_lstcutm(t_list *lst, size_t m);
t_list	*ft_lis_lin(t_list *lst, int n);
t_list	*ft_lis_crcl(t_list *lis_lst, t_list *lst);
t_list	*ft_lis_build(t_list *node, t_list *lst);

size_t	ft_min_index(t_list *stack_a);
t_data	*ft_set_obm_dista(t_list **stack_a, size_t index);
void	ft_set_obm_distb(t_list **stack_a, t_list **stack_b);
size_t	ft_bggr(ssize_t a, ssize_t b);
ssize_t	ft_smllr(ssize_t a, ssize_t b);
size_t	ft_mod(ssize_t a);
size_t	ft_calc_score(t_data *content);
t_list	*ft_obm_score(t_list *stack_b);
size_t	ft_max_index(t_list *stack_a);

void	ft_print_status(t_list *stack_a, t_list *stack_b, char *moves);

#endif