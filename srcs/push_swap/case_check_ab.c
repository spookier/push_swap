#include "../../incs/push_swap.h"

int	case_rarb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = find_place_b(b, c);
	if (i < get_index(a, c))
		i = get_index(a, c);
	return (i);
}


int	case_rrarrb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (find_place_b(b, c))
		i = find_list_size(b) - find_place_b(b, c);
	if ((i < (find_list_size(a) - get_index(a, c))) && get_index(a, c))
		i = find_list_size(a) - get_index(a, c);
	return (i);
}

int	case_rrarb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (get_index(a, c))
		i = find_list_size(a) - get_index(a, c);
	i = find_place_b(b, c) + i;
	return (i);
}

int	case_rarrb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (find_place_b(b, c))
		i = find_list_size(b) - find_place_b(b, c);
	i = get_index(a, c) + i;
	return (i);
}
