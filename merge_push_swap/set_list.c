#include "libft.h"
#include "push_swap.h"

static t_data	*set_t_data(t_data *new_data, ssize_t value)
{
	new_data = malloc(sizeof(t_data));
	if (new_data == NULL)
	{
		return (NULL);
	}
	new_data->value = value;
	new_data->index = 0;
	new_data->dist = 0;
	new_data->obm = NULL;
	return (new_data);
}

/* static t_list	*set_t_list(t_list *new_node, t_data *new_data)
{
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
	{
		return (NULL);
	}
	(t_data *)new_node->content = new_data;
	new_node->next = NULL;
	return (new_node);
} */

void	ft_set_list(t_list **lst, char **token)
{
	int		i;
	int		value;
	int		error;
	t_data	*new_data;
	t_list	*new_node;

	i = 0;
	error = 0;
	*lst = NULL;
	while (token[i] != NULL)
	{
		value = ft_atoi(token[i], &error);
		new_data = set_t_data(new_data, value);
		if (new_data == NULL)
		{
			ft_error(-4, token, lst);
		}
		new_node = ft_lstnew(new_data);
		if (new_node == NULL)
		{
			free(new_data);
			ft_error(-4, token, lst);
		}
		ft_lstadd_back(lst, new_node);
		i++;
	}
}

