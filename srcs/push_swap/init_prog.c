/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostin <acostin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 01:06:58 by acostin           #+#    #+#             */
/*   Updated: 2023/07/14 20:56:04 by acostin          ###   ########.fr       */
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
