#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../libft/libft.h"

# define INT_MAX 2147483647

typedef struct s_stack
{
	long			value;
	long			index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;



// void sa(t_stack **node, int print_flag);
// void sb(t_stack **node, int print_flag);
// void ss(t_stack **a, t_stack **b);
// void pa(t_stack **a, t_stack **b);
// void pb(t_stack **a, t_stack **b);
// void ra(t_stack **a, int print_flag);
// void rb(t_stack **b, int print_flag);
// void rr(t_stack **a, t_stack **b);
// void rra(t_stack **a, int print_flag);
// void rrb(t_stack **b, int print_flag);
// void rrr(t_stack **a, t_stack **b);

// OPERATIONS

void		ra(t_stack **a, int j);
void		rb(t_stack **b, int j);
void		sa(t_stack **a, int j);
void		pa(t_stack **a, t_stack **b, int j);
void		pb(t_stack **stack_a, t_stack **stack_b, int j);
void		rra(t_stack **a, int j);
void		ss(t_stack **a, t_stack **b, int j);
void		rr(t_stack **a, t_stack **b, int j);
void		rrr_sub(t_stack **b, int j);
void		rrr(t_stack **a, t_stack **b, int j);
void		rrb(t_stack **b, int j);

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
t_stack			*init_process(int argc, char **argv);
t_stack			*create_new_node(int content);
void			add_node_to_stack(t_stack **stack, t_stack *stack_new);


// ROTATIONS
int			rotate_type_ba(t_stack *a, t_stack *b);
int			rotate_type_ab(t_stack *a, t_stack *b);


// ALGORITHM
void		sort(t_stack **stack_a);
t_stack		*sort_b(t_stack **stack_a);
t_stack		**sort_a(t_stack **stack_a, t_stack **stack_b);
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