#include "../incs/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;

	a = init_process(argc, argv);
	if (!a || check_duplicate(a))
	{
		//ft_free(&a);
		error_msg();
	}
	if(!check_if_sorted(a))
		sort(&a);
	return (0);
}
