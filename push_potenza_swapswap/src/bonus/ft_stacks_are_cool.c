

#include "push_swap.h"
#include "libft.h"

int ft_stacks_are_cool(t_list **stack_a, t_list **stack_b)
{
	t_data *current_data;
	t_data *next_data;

	if (*stack_b)
	{
		return (0);
	}
	while (*stack_a != NULL && (*stack_a)->next != NULL)
	{
        current_data = (t_data *)((*stack_a)->content);
        next_data = (t_data *)((*stack_a)->next->content);

        if (current_data->value > next_data->value)
            return (0);

        *stack_a = (*stack_a)->next;
    }
    return (1);
}