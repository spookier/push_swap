#include "../incs/push_swap.h"

int	ps_atoi(const char *str)
{
	int				flag;
	long int 		i;

	i = 0;
	flag = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
		|| *str == '\v' || *str == '\r')
		str++;
	if (*str == '-')
	{
		flag = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			error_msg();
		i = i * 10 + (*str - 48);
		str++;
	}
	if ((flag * i) > INT_MAX || (flag * i) < INT_MIN)
		error_msg();
	return (flag * i);
}

int	check_duplicate(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (a->value == tmp->value)
				return (1);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (0);
}

int	check_if_sorted(t_stack *stack_a)
{
	int	i;

	i = stack_a->value;
	while (stack_a)
	{
		if (i > stack_a->value)
			return (0);
		i = stack_a->value;
		stack_a = stack_a->next;
	}
	return (1);
}

int	find_min(t_stack *a)
{
	int		i;

	i = a->value;
	while (a)
	{
		if (a->value < i)
			i = a->value;
		a = a->next;
	}
	return (i);
}

int	find_max(t_stack *a)
{
	int		i;

	i = a->value;
	while (a)
	{
		if (a->value > i)
			i = a->value;
		a = a->next;
	}
	return (i);
}
