#include "libft.h"
#include "push_swap.h"

static t_data	*set_t_data(ssize_t value)
{
	t_data *new_data;
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
static t_list	*set_t_list(t_data *data)
{
	t_list *new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->content = data;
	new_node->next = NULL;
	return (new_node);
}
void	ft_set_list(t_list **lst, char **token)
{
	int	i;
	int	value;
	t_data	*new_data;
	t_list	*new_node;

	i = 0;
	while (token[i] != NULL)
	{
		value = ft_atoi(token[i], NULL);
		new_data = set_t_data(new_data);
		if (new_data == NULL)
		{
			ft_error(-4, token, lst);
		}
		new_node = set_t_list(new_data);
		if (new_node == NULL)
		{
			free(new_data);
			ft_error(-4, token, lst);
		}
		ft_lstadd_back(lst, new_node);
		i++;
	}
}

