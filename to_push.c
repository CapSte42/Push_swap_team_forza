void	ft_rx(t_list **stack)
{
	t_list	*last;
	t_list	*first;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	last = ft_lstlast(*stack);
	*stack = (*stack)->next;
	last->next = first;
	first->next = NULL;
}

void	ft_rrx(t_list **stack)
{
	t_list	*first;
	t_list	*last;
	t_list	*second_last;
	t_list	*tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	first = *stack;
	last = ft_lstlast(*stack);
	while (tmp->next != last)
		tmp = tmp->next;
	second_last = tmp;
	last->next = first;
	*stack = last;
	second_last->next = NULL;
}

void	ft_rr(t_list **stack_a, t_list **stack_b)
{
	ft_rx(stack_a);
	ft_rx(stack_b);
}

void	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	ft_rrx(stack_a);
	ft_rrx(stack_b);
}

void	ft_px(t_list **stack_reciver, t_list **stack_giver)
{
	t_list	*tmp;

	if (*stack_giver == NULL)
		ft_ferror();
	tmp = (*stack_giver)->next;
	(*stack_giver)->next = *stack_reciver;
	*stack_reciver = *stack_giver;
	*stack_giver = tmp;
}

void	ft_swapx(t_list **stack)
{
	t_list	*tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		ft_ferror();
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}