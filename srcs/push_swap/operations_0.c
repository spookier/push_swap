#include "../../incs/push_swap.h"

void	ra(t_stack **a, int print_flag)
{
	t_stack	*tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = find_last_in_list(*a);
	(*a)->next = tmp;
	*a = tmp->next;
	tmp->next = NULL;
	if (print_flag == 0)
		write(1, "ra\n", 3);
}

void	sa(t_stack **a, int print_flag)
{
	t_stack	*tmp;

	if (!*a || !((*a)->next))
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	if (print_flag == 0)
		write(1, "sa\n", 3);
}

void	pa(t_stack **a, t_stack **b, int print_flag)
{
	t_stack	*tmp;

	if (!*b)
		return ;
	tmp = *a;
	*a = *b;
	*b = (*b)->next;
	(*a)->next = tmp;
	if (print_flag == 0)
		write(1, "pa\n", 3);
}


void	rra(t_stack **a, int print_flag)
{
	t_stack	*tmp;
	int		i;

	if (!*a || !(*a)->next)
		return ;
	i = 0;
	tmp = *a;
	while ((*a)->next)
	{
		*a = (*a)->next;
		i++;
	}
	(*a)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	if (print_flag == 0)
		write(1, "rra\n", 4);
}

void	ss(t_stack **a, t_stack **b, int print_flag)
{
	t_stack	*tmp;

	if (!*a || !((*a)->next) || !*b || !((*b)->next))
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	if (print_flag == 0)
		write(1, "ss\n", 3);
}


void	rr(t_stack **a, t_stack **b, int print_flag)
{
	t_stack	*tmp;

	if (!*a || !((*a)->next) || !*b || !((*b)->next))
		return ;
	tmp = *a;
	*a = find_last_in_list(*a);
	(*a)->next = tmp;
	*a = tmp->next;
	tmp->next = NULL;
	tmp = *b;
	*b = find_last_in_list(*b);
	(*b)->next = tmp;
	*b = tmp->next;
	tmp->next = NULL;
	if (print_flag == 0)
		write(1, "rr\n", 3);
}

void	rrr_sub(t_stack **b, int print_flag)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *b;
	while ((*b)->next)
	{
		i++;
		*b = (*b)->next;
	}
	(*b)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	if (print_flag == 0)
		write(1, "rrr\n", 4);
}

// rrr : rra and rrb at the same time.
void	rrr(t_stack **a, t_stack **b, int print_flag)
{
	t_stack	*tmp;
	int		i;

	if (!*a || !((*a)->next) || !*b || !((*b)->next))
		return ;
	i = 0;
	tmp = *a;
	while ((*a)->next)
	{
		i++;
		*a = (*a)->next;
	}
	(*a)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	rrr_sub(b, print_flag);
}


void	pb(t_stack **stack_a, t_stack **stack_b, int print_flag)
{
	t_stack	*tmp;

	if (!*stack_a)
		return ;
	tmp = *stack_b;
	*stack_b = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_b)->next = tmp;
	if (print_flag == 0)
		write(1, "pb\n", 3);
}

void	rrb(t_stack **b, int print_flag)
{
	t_stack	*tmp;
	int		i;

	if (!*b || !(*b)->next)
		return ;
	i = 0;
	tmp = *b;
	while ((*b)->next)
	{
		i++;
		*b = (*b)->next;
	}
	(*b)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	if (print_flag == 0)
		write(1, "rrb\n", 4);
}

void	rb(t_stack **b, int print_flag)
{
	t_stack	*tmp;

	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	*b = find_last_in_list(*b);
	(*b)->next = tmp;
	*b = tmp->next;
	tmp->next = NULL;
	if (print_flag == 0)
		write(1, "rb\n", 3);
}


void	sb(t_stack **b, int print_flag)
{
	t_stack	*tmp;

	if (!*b || !((*b)->next))
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	if (print_flag == 0)
		write(1, "sb\n", 3);
}
