/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:27:30 by fdonati           #+#    #+#             */
/*   Updated: 2023/11/28 15:16:03 by fdonati          ###   ########.fr       */
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

t_list	*ft_lstcutm(t_list *lst, size_t m);
size_t	ft_lstto_nmb(t_list *lst, int index);
t_list	*ft_lis(t_list *lst);
t_list	*ft_lis_lst(t_list *lst, int parent[], int max_index);
void	ft_lis_algrtm(t_list *lst, int n, int lis[], int parent[]);
int		ft_lis_maxindex(int lis[], int n);
t_list	*ft_lis_lin(t_list *lst, int n);
int		ft_lis_crcl_indx(t_list *lis_lst, t_list *lst, size_t m);
t_list	*ft_lis_crcl(t_list *lis_lst, t_list *lst);
void	ft_lstclean(t_list **lst);
t_list	*ft_lis_build(t_list *node, t_list *lst);

#endif