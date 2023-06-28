#include "../incs/push_swap.h"

void	error_msg(void)
{	
	write (1, "Error\n", 6);
	exit(1);
}


t_stack	*init_prog(int argc, char **argv)
{
	t_stack	*a;
	int		i;

	i = 1;
	a = NULL;
	if (argc < 2)
		error_msg();
	if (argc == 2)
		printf("2 argc\n");
	else
	{
		while (i < argc)
		{
			if(process_arg_and_add_to_stack(&a, argv[i]) == -1)
				return (NULL);
			i++;
		}
	}
	return (a);
}
