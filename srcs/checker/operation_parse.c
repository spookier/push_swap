/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostin <acostin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 00:55:31 by acostin           #+#    #+#             */
/*   Updated: 2023/07/10 00:58:03 by acostin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/checker.h"

void	exec_operation2(t_stack **stack_a, t_stack **stack_b, char *operation)
{
	if (ft_strcmp(operation, "rra") == 0)
		rra(stack_a, 1);
	else if (ft_strcmp(operation, "rrb") == 0)
		rrb(stack_b, 1);
	else if (ft_strcmp(operation, "rrr") == 0)
		rrr(stack_a, stack_b, 1);
	else
		error_free_and_exit(stack_a, operation);
}

void	exec_operation(t_stack **stack_a, t_stack **stack_b, char *operation)
{
	if (ft_strcmp(operation, "sa") == 0)
		sa(stack_a, 1);
	else if (ft_strcmp(operation, "sb") == 0)
		sb(stack_b, 1);
	else if (ft_strcmp(operation, "ss") == 0)
		ss(stack_a, stack_b, 1);
	else if (ft_strcmp(operation, "pa") == 0)
		pa(stack_a, stack_b, 1);
	else if (ft_strcmp(operation, "pb") == 0)
		pb(stack_a, stack_b, 1);
	else if (ft_strcmp(operation, "ra") == 0)
		ra(stack_a, 1);
	else if (ft_strcmp(operation, "rb") == 0)
		rb(stack_b, 1);
	else if (ft_strcmp(operation, "rr") == 0)
		rr(stack_a, stack_b, 1);
	else
		exec_operation2(stack_a, stack_b, operation);
}

int	check_operation(t_stack **stack_a, t_stack **stack_b, char *operation)
{
	if (ft_strcmp(operation, "Error") == 0)
		error_free_and_exit(stack_a, operation);
	else
		exec_operation(stack_a, stack_b, operation);
	return (0);
}

char	*alloc_operation(void)
{
	char	*operation;
	int		i;
	char	c;

	operation = malloc(sizeof(char) * 8);
	if (!operation)
		return (NULL);
	i = 0;
	while (i < 7 && read(0, &c, 1) > 0 && c != '\n')
	{
		operation[i] = c;
		i++;
	}
	operation[i] = '\0';
	return (operation);
}

int	start_operations(t_stack **stack_a)
{
	char	*operation;
	t_stack	*stack_b;

	stack_b = NULL;
	while (1)
	{
		operation = alloc_operation();
		if (operation == NULL)
			return (-1);
		if (operation[0] == '\0')
		{
			free(operation);
			break ;
		}
		check_operation(stack_a, &stack_b, operation);
		free(operation);
	}
	if (stack_b)
		return (-1);
	return (0);
}
