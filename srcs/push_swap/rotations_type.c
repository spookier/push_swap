/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostin <acostin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 01:30:06 by acostin           #+#    #+#             */
/*   Updated: 2023/07/10 01:30:50 by acostin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

int	rotate_type_ba(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*tmp;

	tmp = b;
	i = case_rrarrb_a(a, b, b->value);
	while (tmp)
	{
		if (i > case_rarb_a(a, b, tmp->value))
			i = case_rarb_a(a, b, tmp->value);
		if (i > case_rrarrb_a(a, b, tmp->value))
			i = case_rrarrb_a(a, b, tmp->value);
		if (i > case_rarrb_a(a, b, tmp->value))
			i = case_rarrb_a(a, b, tmp->value);
		if (i > case_rrarb_a(a, b, tmp->value))
			i = case_rrarb_a(a, b, tmp->value);
		tmp = tmp->next;
	}
	return (i);
}

int	rotate_type_ab(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*tmp;

	tmp = a;
	i = case_rrarrb(a, b, a->value);
	while (tmp)
	{
		if (i > case_rarb(a, b, tmp->value))
			i = case_rarb(a, b, tmp->value);
		if (i > case_rrarrb(a, b, tmp->value))
			i = case_rrarrb(a, b, tmp->value);
		if (i > case_rarrb(a, b, tmp->value))
			i = case_rarrb(a, b, tmp->value);
		if (i > case_rrarb(a, b, tmp->value))
			i = case_rrarb(a, b, tmp->value);
		tmp = tmp->next;
	}
	return (i);
}
