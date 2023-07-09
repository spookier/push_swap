#include "../../incs/push_swap.h"

int	case_rarb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = find_place_a(a, c);
	if (i < get_index(b, c))
		i = get_index(b, c);
	return (i);
}

// This function calculates the required amount of rotation.
// Calculations are done for rra+rrb case.
int	case_rrarrb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (find_place_a(a, c))
		i = find_list_size(a) - find_place_a(a, c);
	if ((i < (find_list_size(b) - get_index(b, c))) && get_index(b, c))
		i = find_list_size(b) - get_index(b, c);
	return (i);
}

// This function calculates the required amount of rotation.
// Calculations are done for ra+rrb case.
int	case_rarrb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (get_index(b, c))
		i = find_list_size(b) - get_index(b, c);
	i = find_place_a(a, c) + i;
	return (i);
}

// This function calculates the required amount of rotation.
// Calculations are done for rra+rb case.
int	case_rrarb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (find_place_a(a, c))
		i = find_list_size(a) - find_place_a(a, c);
	i = get_index(b, c) + i;
	return (i);
}
