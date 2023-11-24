/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 06:18:17 by smontuor          #+#    #+#             */
/*   Updated: 2023/11/24 10:57:33 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int error)
{
	ft_printf(2, "Error\n");
	exit(error);
}

int	ft_is_all_digit(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		if (av[i][j + 1] != '\0' && ft_issign(av[i][j]) == 1 )
			j++;
		while (av[i][j] != '\0')
		{
			while (av[i][j] != '\0' && ft_isspace(av[i][j]) == 1)
				j++;
			if (av[i][j] != '\0' && ft_isdigit(av[i][j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_within_int(int ac, char **av)
{
	int	i;
	int	num;
	int error;

	i = 1;
	error= 0;
	while (i < ac)
	{
		num = 0;
		num = ft_atoi(av[i], &error);
		if (error == 1)
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_unique(int ac, char **av)
{
	int	i;
	int	j;
	int e;

	i = 1;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_atoi(av[i], &e) == ft_atoi(av[j], &e))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_param(int ac, char **av)
{
	if (ac == 1)
		return (0); //input vuoto
	if (ac < 2)
		return (-1); //terminare
	if (ft_is_all_digit(ac, av) == 0)
		return (-2);
	if (ft_within_int(ac, av) == 0)
		return (-3);
	if (ft_is_unique(ac, av) == 0)
		return (-4);
	return (1); //input valido
}

t_list	*ft_mount_lst(int size, char **value_arrey)
{
	t_list	*lst;
	t_data	*data;
	t_list	*new_node;
	int		i;
	int		error;

	lst = NULL;
	i = 1;
	while (i < size)
	{
		data = malloc(sizeof(t_data));
		if (!data)
		{
			// liberare la lista se necessario
			return (NULL);
		}
		error = 0;
		data->value = (ssize_t)ft_atoi(value_arrey[i], &error);
		if (error != 0)
		{
			free(data);
			//liberare la lista se necessario
			return (NULL);
		}
		data->index = 0;
		new_node = ft_lstnew(data);
		if (!new_node)
		{
			free(data);
			//liberare la lista
			return (NULL);
		}
		ft_lstadd_back(&lst, new_node);
		i++;
	}
	return lst;
}

ssize_t	*ft_fill_stack(t_list **lst)
{
	ssize_t	i;
	t_list	*tmp;
	ssize_t	*stack;

	tmp = *lst;
	stack = malloc(sizeof(ssize_t) * ft_lstsize(*lst));
	if (!stack)
		return (NULL);
	i = -1;
	while (tmp)
	{
		stack[++i] = ((t_data *)tmp->content)->value;
		tmp = tmp->next;
	}
	return (stack);
}
void	ft_swap(ssize_t *a, ssize_t *b)
{
	ssize_t	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_quick_sort(ssize_t *stack, ssize_t start, ssize_t end)
{
	ssize_t	pivot;
	ssize_t	i;
	ssize_t	j;

	if (start < end)
	{
		pivot = start;
		i = start;
		j = end;
		while (i < j)
		{
			while (stack[i] <= stack[pivot] && i < end)
				i++;
			while (stack[j] > stack[pivot])
				j--;
			if (i < j)
				ft_swap(&stack[i], &stack[j]);
		}
		ft_swap(&stack[pivot], &stack[j]);
		ft_quick_sort(stack, start, j - 1);
		ft_quick_sort(stack, j + 1, end);
	}
}

t_list	**indexing(t_list **lst)
{
	ssize_t	*stack;
	ssize_t	i;
	ssize_t	j;
	t_list	*tmp;

	tmp = *lst;
	stack = ft_fill_stack(lst);
	if (!stack)
		return (NULL);
	ft_quick_sort(stack, 0, ft_lstsize(*lst) - 1);
	tmp = *lst;
	i = ft_lstsize(*lst);
	while (tmp)
	{
		j = -1;
		while (++j < i)
			if (((t_data *)tmp->content)->value == stack[j])
				((t_data *)tmp->content)->index = j + 1;
		tmp = tmp->next;
	}
	free(stack);
	return (lst);
}

int main(int ac, char **av)
{
	t_list *lst;
	t_list **indexed_lst;
	t_list *temp;
	t_data *data;
	int check;

	check = ft_check_param(ac, av);
	if (check <= 0)
	{
		ft_error(check);
	}
    lst = ft_mount_lst(ac, av);
    if (!lst)
	{
		ft_error(-5);
	}
	indexed_lst = indexing(&lst);
	if (!indexed_lst)
	{
		ft_error(-6);
	}
	temp = lst;
	while (temp != NULL)
	{
		data = (t_data *)temp->content;
		printf("Value: %zd, Index: %zu\n", data->value, data->index);
		temp = temp->next;
	}

	/*
	giocate qua
	
	
	
	
	
	
	
	*/
    // Pulisci la lista alla fine
    return 0;
}


