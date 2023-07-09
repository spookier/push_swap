/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostin <acostin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 01:02:32 by acostin           #+#    #+#             */
/*   Updated: 2023/07/10 01:04:11 by acostin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H

# define CHECKER_H

# include	<unistd.h>
# include	<stdlib.h>
# include	"../libft/libft.h"
# include	"../incs/push_swap.h"

char	*alloc_operation(void);
int		start_operations(t_stack **a);
int		error_free_and_exit(t_stack **stack_a, char *operation);

#endif