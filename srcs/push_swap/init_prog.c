/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostin <acostin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 01:06:58 by acostin           #+#    #+#             */
/*   Updated: 2023/07/10 01:07:22 by acostin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

t_stack	*init_prog(int argc, char **argv)
{
	t_stack	*a;
	int		i;

	i = 1;
	a = NULL;
	if (argc < 2)
		error_msg();
	if (argc == 3)
	{
		if (sort_two(&a, argv) == -1)
			return (NULL);
	}
	else
	{
		while (i < argc)
		{
			if (process_arg_and_add_to_stack(&a, argv[i]) == -1)
				return (NULL);
			i++;
		}
	}
	return (a);
}
