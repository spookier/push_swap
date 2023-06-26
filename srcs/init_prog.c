#include "../incs/push_swap.h"

void	error_msg(void)
{	
	write (1, "Error\n", 6);
	exit(1);
}

t_stack	*init_process(int argc, char **argv)
{
	t_stack	*a;
	int		number;
	int		i;

	i = 1;
	a = NULL;
	if (argc < 2)
		error_msg();
	if (argc == 2)
	{
		// TO DO: subprocess
		printf("2 argc\n");
	}
	else
	{
		while (i < argc)
		{
			number = ps_atoi(argv[i]);
			add_node_to_stack(&a, create_new_node(number));
			i++;
		}
	}
	return (a);
}
