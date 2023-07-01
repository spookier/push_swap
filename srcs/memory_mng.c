#include "../incs/push_swap.h"

static void	add_node_to_stack(t_stack **stack, t_stack *stack_new)
{
	if (!stack)
		return ;
	if (!*stack)
		*stack = stack_new;
	else
		find_last_in_list(*stack)->next = stack_new;
}

static t_stack	*create_new_node(int number)
{
	t_stack	*new;

	new = malloc(sizeof (t_stack));
	if (!new)
		return(NULL);
	new->value = number;
	new->next = NULL;
	return (new);
}


int process_arg_and_add_to_stack(t_stack **a, char *argv)
{
	t_stack *new_node;
	int number;

    number = ps_atoi(argv);
    new_node = create_new_node(number);
    if(!new_node)
    {
        free_stack(a);
		free(new_node);
        return (-1);
    }
    add_node_to_stack(a, new_node);
    return (0);
}

void	free_stack(t_stack **stack) 
{
    t_stack *current_node;
    t_stack *next_node;

    if (!stack || !*stack)
        return;

    current_node = *stack;
    while (current_node != NULL)
    {
        next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }
    *stack = NULL;
}
