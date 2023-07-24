/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostin <acostin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 01:27:25 by acostin           #+#    #+#             */
/*   Updated: 2023/07/10 01:29:50 by acostin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	error_msg(void)
{
	write (2, "Error\n", 6);
	exit (1);
}

void	error_msg_atoi(t_stack **a)
{
	write (2, "Error\n", 6);
	free_stack(a);
	exit (1);
}
