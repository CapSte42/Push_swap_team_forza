

#include "push_swap.h"
#include "libft.h"

int	ft_stacks_are_cool(t_list **stack_a, t_list **stack_b)
{
	t_data	*current_data;
	t_data	*next_data;
	t_list	*temp;

	if (*stack_b)
	{
		return (0);
	}
	temp = *stack_a;
	while (temp != NULL && temp->next != NULL)
	{
		current_data = (t_data *)(temp->content);
		next_data = (t_data *)(temp->next->content);
		if (current_data->value > next_data->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}
