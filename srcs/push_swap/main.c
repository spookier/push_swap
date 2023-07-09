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
	if(!check_if_sorted(a))
		sort(&a);
	free_stack(&a);
	return (0);
}
