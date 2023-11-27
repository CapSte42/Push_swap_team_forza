/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:55:36 by fdonati           #+#    #+#             */
/*   Updated: 2023/11/27 15:02:41 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lis(t_list *lst)
{
	t_list	*lis_lst;
	t_list	*lis_lst_crcl;

	lis_lst = ft_lis_lin(lst, ft_lstsize(lst));
	if (lis_lst == NULL)
		return (NULL);
	lis_lst_crcl = ft_lis_crcl(lis_lst, lst);
	if (lis_lst_crcl != NULL)
	{
		ft_lstadd_front(&lis_lst, ft_lstlast(lis_lst_crcl));
		lis_lst = lis_lst_crcl;
	}
	return (lis_lst);
}

int	main()
{
	t_list	*stack_a;
	t_list	*lis;
	t_list	*node;
	t_data	*data;
	size_t	arr_a[15] = {15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	int		i;

	stack_a = NULL;
	i = 0;
	while (i < 15)
	{
		data = malloc(sizeof(t_data));
		data->index = arr_a[i];
		data->value = arr_a[i];
		data->dist = 0;
		data->obm = NULL;
		ft_lstadd_back(&stack_a, ft_lstnew(data));
		i++;
	}
	node = stack_a;
	printf("\nstack_a:\n");
	while (node != NULL)
	{
		printf("index: %zu, value: %zd",
				((t_data *)node->content)->index,
				((t_data *)node->content)->value);
		node = node->next;
		printf("\n");
	}
	lis = ft_lis(stack_a);
	node = lis;
	printf("\nlis:\n");
	while (node != NULL)
	{
		printf("%zu ", (*(size_t *) node->content));
		node = node->next;
	}
	printf("\n");
	return (0);
}
