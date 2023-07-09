#ifndef CHECKER_H

#define	CHECKER_H

#include <unistd.h>
#include <stdlib.h>
# include "../libft/libft.h"
# include "../incs/push_swap.h"


char 	*alloc_operation(void);
int 	start_operations(t_stack **a);
int 	error_free_and_exit(t_stack **stack_a, char *operation);

#endif