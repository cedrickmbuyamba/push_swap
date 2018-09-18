/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmbuyamb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 16:12:18 by cmbuyamb          #+#    #+#             */
/*   Updated: 2018/09/05 16:18:04 by mntumba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct		s_stack
{
	int				*stack_a;
	int				*stack_b;
	int				stack_a_size;
	int				stack_b_size;
	int				size;
	char			*ops;
	bool			rev;
}					t_stack;

# define SA	0
# define SB	1
# define SS	2
# define PA	3
# define PB	4
# define RA 5
# define RB 6
# define RR	7
# define RRA 8
# define RRB 9
# define RRR 10

# define MAX(x, y) x > y ? x : y
# define BEGIN(stack, size) (stack) > ((size) / 2) ? (size) - (stack) : (stack)
# define INSTR_A(stack_a, size) (stack_a) > ((size) / 2) ? (RRA) : (RA)
# define INSTR_B(stack_b, size) (stack_b) > ((size) / 2) ? (RRB) : (RB)
# define NBR_RR(stack_a, stack_b) MAX((stack_a), (stack_b))
# define NBR_RRR(stack_a, stack_b, i, j) MAX((i) - (stack_a), (j) - (stack_b))

int					check(char *str);
int					is_sorted(int *a);
int					which_ind(t_stack *stack, int ind);
void				main_algo(t_stack *inf);
void				sa(t_stack *stack);
void				sb(t_stack *stack);
void				ss(t_stack *stack);
void				pa(t_stack *stack);
void				pb(t_stack *stack);
void				ra(t_stack *stack);
void				rb(t_stack *stack);
void				rr(t_stack *stack);
void				rra(t_stack *stack);
void				rrb(t_stack *stack);
void				rrr(t_stack *stack);
int					*ft_calc(t_stack *stack, int i_a);
int					*find_ind(t_stack *stack);
void				ajout_instr(t_stack *stack, int instr);
void				run_instr(t_stack *stack, int instr);
void				execute(t_stack *stack, int instr);
void				remove_stack(t_stack **stack);
void				remove_rev_stack(t_stack **rev_stack);
t_stack				*reverse_stack(t_stack *stack);
void				m_stack(t_stack *stack, t_stack *rev_stack);
t_stack				*copy_stack(t_stack *stack);
void				which_rotate(t_stack *stack);
int					get_instr(char **instr);

#endif
