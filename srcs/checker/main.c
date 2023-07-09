#include "../../incs/checker.h"


// ONLY FOR DEBUG TO SHOW STACK A
void print_stack(t_stack **a)
{
	t_stack *tmp;
	int i;

	if (*a == NULL) {
		printf("Stack is empty\n");
		return;
	}

	i = 1;
	tmp = *a;

	// print the value of the head node
	printf("IN STACK A = %ld\n", tmp->value);
	
	tmp = tmp->next;
	
	// iterate through the list until we encounter the head node again
	while (tmp != *a && tmp != NULL)
	{
		printf("IN STACK A = %ld\n", tmp->value);
		tmp = tmp->next;
		i++;
	}
}


int error_free_and_exit(t_stack **stack_a, char *operation)
{
	write(1, "Error\n", 6);
	if(stack_a)
		free_stack(stack_a);
	if(operation)
		free(operation);
	exit(-1);
}

void check_program(t_stack **stack_a)
{
	if (check_duplicate(*stack_a) == 1)
	{
		write(1, "Error\n", 6);
		if(stack_a)
			free_stack(stack_a);
		exit(-1);
	}
	if(start_operations(stack_a) == -1)
	{
		write(1, "KO\n", 3);
		if(stack_a)
			free_stack(stack_a);
		exit(-1);
	}
	if(check_if_sorted(*stack_a) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int main(int argc, char **argv)
{
	t_stack *stack_a;
	int i;

	i = 1;
	stack_a = NULL;
	if(argc <= 1)
		return(-1);
	while (i < argc)
	{
		process_arg_and_add_to_stack(&stack_a, argv[i]);
		i++;
	}
	check_program(&stack_a);
	if(stack_a)
		free_stack(&stack_a);
	return(0);
}
