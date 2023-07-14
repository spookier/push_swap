/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostin <acostin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 01:07:32 by acostin           #+#    #+#             */
/*   Updated: 2023/07/14 20:54:18 by acostin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;

	a = init_prog(argc, argv);
	if (!a || check_duplicate(a))
	{
		free_stack(&a);
		error_msg();
	}
	if (!check_if_sorted(a))
		sort(&a);
	free_stack(&a);
	return (0);
}
