/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_apply.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostin <acostin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 01:06:25 by acostin           #+#    #+#             */
/*   Updated: 2023/07/10 01:06:25 by acostin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

int	apply_rarb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->value != c && find_place_b(*b, c) > 0)
			rr(a, b, 0);
		while ((*a)->value != c)
			ra(a, 0);
		while (find_place_b(*b, c) > 0)
			rb(b, 0);
		pb(a, b, 0);
	}
	else
	{
		while ((*b)->value != c && find_place_a(*a, c) > 0)
			rr(a, b, 0);
		while ((*b)->value != c)
			rb(b, 0);
		while (find_place_a(*a, c) > 0)
			ra(a, 0);
		pa(a, b, 0);
	}
	return (-1);
}

int	apply_rrarrb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->value != c && find_place_b(*b, c) > 0)
			rrr(a, b, 0);
		while ((*a)->value != c)
			rra(a, 0);
		while (find_place_b(*b, c) > 0)
			rrb(b, 0);
		pb(a, b, 0);
	}
	else
	{
		while ((*b)->value != c && find_place_a(*a, c) > 0)
			rrr(a, b, 0);
		while ((*b)->value != c)
			rrb(b, 0);
		while (find_place_a(*a, c) > 0)
			rra(a, 0);
		pa(a, b, 0);
	}
	return (-1);
}

int	apply_rrarb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->value != c)
			rra(a, 0);
		while (find_place_b(*b, c) > 0)
			rb(b, 0);
		pb(a, b, 0);
	}
	else
	{
		while (find_place_a(*a, c) > 0)
			rra(a, 0);
		while ((*b)->value != c)
			rb(b, 0);
		pa(a, b, 0);
	}
	return (-1);
}

int	apply_rarrb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->value != c)
			ra(a, 0);
		while (find_place_b(*b, c) > 0)
			rrb(b, 0);
		pb(a, b, 0);
	}
	else
	{
		while (find_place_a(*a, c) > 0)
			ra(a, 0);
		while ((*b)->value != c)
			rrb(b, 0);
		pa(a, b, 0);
	}
	return (-1);
}
