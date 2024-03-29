/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostin <acostin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 01:05:14 by acostin           #+#    #+#             */
/*   Updated: 2023/07/14 20:53:15 by acostin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

int	sort_two(t_stack **a, char **argv)
{
	int	i;

	i = 1;
	while (i < 3)
	{
		if (process_arg_and_add_to_stack(a, argv[i]) == -1)
			return (-1);
		i++;
	}
	return (0);
}
