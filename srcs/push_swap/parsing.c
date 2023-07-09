#include "../../incs/push_swap.h"

void	norminette_atoi(int *flag, const char **str)
{
	*flag = -1;
	(*str)++;
}

int	ps_atoi(const char *str, t_stack **a)
{
	int				flag;
	long int 		i;

	i = 0;
	flag = 1;
	if (!*str)
		error_msg_atoi(a);
	if (*str == '-')
		norminette_atoi(&flag, &str);
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			error_msg_atoi(a);
		i = i * 10 + (*str - 48);
		str++;
	}
	if ((flag * i) > INT_MAX || (flag * i) < INT_MIN)
		error_msg_atoi(a);
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
	int	number;

	number = stack_a->value;
	while (stack_a)
	{
		if (number > stack_a->value)
			return (0);
		number = stack_a->value;
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
