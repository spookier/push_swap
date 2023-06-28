#include "../incs/push_swap.h"

int	find_list_size(t_stack *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_stack	*find_last_in_list(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}


int	get_index(t_stack *a, int nbr)
{
	int		i;

	i = 0;
	while (a->value != nbr)
	{
		i++;
		a = a->next;
	}
	return (i);
}

int find_place_b(t_stack *stack_b, int nbr_push)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (nbr_push > stack_b->value && nbr_push < find_last_in_list(stack_b)->value)
		i = 0;
	else if (nbr_push > find_max(stack_b) || nbr_push < find_min(stack_b))
		i = get_index(stack_b, find_max(stack_b));
	else
	{
		tmp = stack_b->next;
		while (stack_b->value < nbr_push || tmp->value > nbr_push)
		{
			stack_b = stack_b->next;
			tmp = stack_b->next;
			i++;
		}
	}
	return (i);
}

int	find_place_a(t_stack *stack_a, int nbr_push)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (nbr_push < stack_a->value && nbr_push > find_last_in_list(stack_a)->value)
		i = 0;
	else if (nbr_push > find_max(stack_a) || nbr_push < find_min(stack_a))
		i = get_index(stack_a, find_min(stack_a));
	else
	{
		tmp = stack_a->next;
		while (stack_a->value > nbr_push || tmp->value < nbr_push)
		{
			stack_a = stack_a->next;
			tmp = stack_a->next;
			i++;
		}
	}
	return (i);
}