#include "../../incs/push_swap.h"

void	sort(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		i;

	stack_b = NULL;
	if (find_list_size(*stack_a) == 2)
		sa(stack_a, 0);
	else
	{
		stack_b = sort_b(stack_a);
		stack_a = sort_a(stack_a, &stack_b);
		i = get_index(*stack_a, find_min(*stack_a));
		if (i < find_list_size(*stack_a) - i)
		{
			while ((*stack_a)->value != find_min(*stack_a))
				ra(stack_a, 0);
		}
		else
		{
			while ((*stack_a)->value != find_min(*stack_a))
				rra(stack_a, 0);
		}			
	}	
}

t_stack	**sort_a(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*tmp;

	while (*stack_b)
	{
		tmp = *stack_b;
		i = rotate_type_ba(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == case_rarb_a(*stack_a, *stack_b, tmp->value))
				i = apply_rarb(stack_a, stack_b, tmp->value, 'b');
			else if (i == case_rarrb_a(*stack_a, *stack_b, tmp->value))
				i = apply_rarrb(stack_a, stack_b, tmp->value, 'b');
			else if (i == case_rrarrb_a(*stack_a, *stack_b, tmp->value))
				i = apply_rrarrb(stack_a, stack_b, tmp->value, 'b');
			else if (i == case_rrarb_a(*stack_a, *stack_b, tmp->value))
				i = apply_rrarb(stack_a, stack_b, tmp->value, 'b');
			else
				tmp = tmp->next;
		}
	}
	return (stack_a);
}


t_stack	*sort_b(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (find_list_size(*stack_a) > 3 && !check_if_sorted(*stack_a))
		pb(stack_a, &stack_b, 0);
	if (find_list_size(*stack_a) > 3 && !check_if_sorted(*stack_a))
		pb(stack_a, &stack_b, 0);
	if (find_list_size(*stack_a) > 3 && !check_if_sorted(*stack_a))
		sort_b_till_3(stack_a, &stack_b);
	if (!check_if_sorted(*stack_a))
		sort_only_3(stack_a);
	return (stack_b);
}


void	sort_b_till_3(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*tmp;

	while (find_list_size(*stack_a) > 3 && !check_if_sorted(*stack_a))
	{
		tmp = *stack_a;
		i = rotate_type_ab(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == case_rarb(*stack_a, *stack_b, tmp->value))
				i = apply_rarb(stack_a, stack_b, tmp->value, 'a');
			else if (i == case_rrarrb(*stack_a, *stack_b, tmp->value))
				i = apply_rrarrb(stack_a, stack_b, tmp->value, 'a');
			else if (i == case_rarrb(*stack_a, *stack_b, tmp->value))
				i = apply_rarrb(stack_a, stack_b, tmp->value, 'a');
			else if (i == case_rrarb(*stack_a, *stack_b, tmp->value))
				i = apply_rrarb(stack_a, stack_b, tmp->value, 'a');
			else
				tmp = tmp->next;
		}
	}
}

void	sort_only_3(t_stack **stack_a)
{
	if (find_min(*stack_a) == (*stack_a)->value)
	{
		rra(stack_a, 0);
		sa(stack_a, 0);
	}
	else if (find_max(*stack_a) == (*stack_a)->value)
	{
		ra(stack_a, 0);
		if (!check_if_sorted(*stack_a))
			sa(stack_a, 0);
	}
	else
	{
		if (get_index(*stack_a, find_max(*stack_a)) == 1)
			rra(stack_a, 0);
		else
			sa(stack_a, 0);
	}
}
