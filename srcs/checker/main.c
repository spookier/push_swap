/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostin <acostin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 00:49:24 by acostin           #+#    #+#             */
/*   Updated: 2023/07/10 00:58:57 by acostin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/checker.h"

int	error_free_and_exit(t_stack **stack_a, char *operation)
{
	write(1, "Error\n", 6);
	if (stack_a)
		free_stack(stack_a);
	if (operation)
		free(operation);
	exit (-1);
}

void	check_program(t_stack **stack_a)
{
	if (check_duplicate(*stack_a) == 1)
	{
		write(1, "Error\n", 6);
		if (stack_a)
			free_stack(stack_a);
		exit (-1);
	}
	if (start_operations(stack_a) == -1)
	{
		write(1, "KO\n", 3);
		if (stack_a)
			free_stack(stack_a);
		exit (-1);
	}
	if (check_if_sorted(*stack_a) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	int		i;

	i = 1;
	stack_a = NULL;
	if (argc <= 1)
		return (-1);
	while (i < argc)
	{
		process_arg_and_add_to_stack(&stack_a, argv[i]);
		i++;
	}
	check_program(&stack_a);
	if (stack_a)
		free_stack(&stack_a);
	return (0);
}
