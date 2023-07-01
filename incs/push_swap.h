#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stack
{
	long			value;
	struct s_stack	*next;
}	t_stack;


// OPERATIONS
void		ra(t_stack **a, int print_flag);
void		rb(t_stack **b, int print_flag);
void		sa(t_stack **a, int print_flag);
void		pa(t_stack **a, t_stack **b, int print_flag);
void		pb(t_stack **stack_a, t_stack **stack_b, int print_flag);
void		rra(t_stack **a, int print_flag);
void		ss(t_stack **a, t_stack **b, int print_flag);
void		rr(t_stack **a, t_stack **b, int print_flag);
void		rrr_sub(t_stack **b, int print_flag);
void		rrr(t_stack **a, t_stack **b, int print_flag);
void		rrb(t_stack **b, int print_flag);

// PARSING + CHECKS
int			check_duplicate(t_stack *a);
void		error_msg(void);
int			ps_atoi(const char *str);
int			check_if_sorted(t_stack *stack_a);
int			find_list_size(t_stack *lst);
int			find_max(t_stack *a);
int			find_min(t_stack *a);
int			get_index(t_stack *a, int nbr);
int 		find_place_a(t_stack *stack_b, int nbr_push);
int 		find_place_b(t_stack *stack_b, int nbr_push);
t_stack		*find_last_in_list(t_stack *lst);


// MEMORY
t_stack			*init_prog(int argc, char **argv);
int 			process_arg_and_add_to_stack(t_stack **a, char *argv);
void 			free_stack(t_stack **stack);

// ROTATIONS
int			rotate_type_ba(t_stack *a, t_stack *b);
int			rotate_type_ab(t_stack *a, t_stack *b);

// ALGORITHM
t_stack		*sort_b(t_stack **stack_a);
t_stack		**sort_a(t_stack **stack_a, t_stack **stack_b);
void		sort(t_stack **stack_a);
int 		sort_two(t_stack **a, char **argv);
void		sort_b_till_3(t_stack **stack_a, t_stack **stack_b);
void		sort_only_3(t_stack **stack_a);

// CASE CHECK A STACK
int			case_rarb_a(t_stack *a, t_stack *b, int c);
int			case_rrarrb_a(t_stack *a, t_stack *b, int c);
int			case_rarrb_a(t_stack *a, t_stack *b, int c);
int			case_rrarb_a(t_stack *a, t_stack *b, int c);

//CASE APPLY
int			apply_rarb(t_stack **a, t_stack **b, int c, char s);
int			apply_rrarrb(t_stack **a, t_stack **b, int c, char s);
int			apply_rrarb(t_stack **a, t_stack **b, int c, char s);
int			apply_rarrb(t_stack **a, t_stack **b, int c, char s);

// CASE CHECK A + B STACK
int			case_rarb(t_stack *a, t_stack *b, int c);
int			case_rrarrb(t_stack *a, t_stack *b, int c);
int			case_rrarb(t_stack *a, t_stack *b, int c);
int			case_rarrb(t_stack *a, t_stack *b, int c);


#endif