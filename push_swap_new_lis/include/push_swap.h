/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:03:29 by tpicchio          #+#    #+#             */
/*   Updated: 2023/12/15 16:14:47 by tpicchio         ###   ########.fr       */
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

void	ft_set_index(t_list **lst);
void	ft_set_swap(t_list **lst);
char	*ft_push_swap(t_list **stack_a, t_list *not_push);

char	*ft_push_best(t_list **stack_a, t_list **stack_b,
			t_list *node, char *moves);
char	*ft_last_rotate(t_list **stack_a, char *moves);

t_list	*ft_lis(t_list *lst);

int		ft_rx(t_list **stack);
int		ft_rrx(t_list **stack);
int		ft_sx(t_list **stack);
int		ft_px(t_list **stack_a, t_list **stack_b);
int		ft_rr(t_list **stack_a, t_list **stack_b);
int		ft_rrr(t_list **stack_a, t_list **stack_b);
int		ft_ss(t_list **stack_a, t_list **stack_b);

size_t	ft_min_index(t_list *stack_a, size_t size);
t_data	*ft_set_obm_dista(t_list **stack_a, size_t index, size_t size_b);
void	ft_set_obm_distb(t_list **stack_a, t_list **stack_b);
size_t	ft_bggr(ssize_t a, ssize_t b);
ssize_t	ft_smllr(ssize_t a, ssize_t b);
size_t	ft_mod(ssize_t a);
size_t	ft_calc_score(t_data *content);
t_list	*ft_obm_score(t_list *stack_b);
size_t	ft_max_index(t_list *stack_a, size_t size);

char	**ft_split_input_into_token(int ac, char **av);
void	ft_error(int error, char **token, t_list **lst);
void	ft_check_token(char **token);
void	ft_set_list(t_list **lst, char **token);
void	ft_free_token_array(char **token);

int		ft_stacks_are_cool(t_list **stack_a, t_list **stack_b);
int		ft_parse_moves(t_list **stack_a, t_list **stack_b);

#endif
