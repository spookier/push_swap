#include "../incs/push_swap.h"

void	add_node_to_stack(t_stack **stack, t_stack *stack_new)
{
	if (!stack)
		return ;
	if (!*stack)
		*stack = stack_new;
	else
		(find_last_in_list(*stack))->next = stack_new;
}

t_stack	*create_new_node(int content)
{
	t_stack	*new;

	new = malloc(sizeof (t_stack));
	if (!new)
		error_msg();
	new->value = content;
	new->next = NULL;
	return (new);
}
