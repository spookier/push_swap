/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostin <acostin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 01:22:38 by acostin           #+#    #+#             */
/*   Updated: 2023/07/10 01:25:56 by acostin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

int	ps_atoi(const char *str, t_stack **a)
{
	int			sign;
	long long	ret;
	long long	nbr;

	sign = 1;
	if (*str == '-' || *str == '+')
		norm_atoi(&str, &sign, a);
	ret = 0;
	while (*str)
	{
		if ('0' <= *str && *str <= '9')
			ret = ret * 10 + (*str - '0');
		else
			error_msg_atoi(a);
		str++;
	}
	nbr = sign * ret;
	if (nbr < -2147483648 || nbr > 2147483647)
		error_msg_atoi(a);
	return (nbr);
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
