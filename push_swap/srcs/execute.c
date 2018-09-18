/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmbuyamb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 15:08:16 by cmbuyamb          #+#    #+#             */
/*   Updated: 2018/09/05 15:08:22 by cmbuyamb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	save_instr(t_stack *stack, int instr)
{
	char	*arr[11];
	char	*s;

	arr[SA] = "sa\n";
	arr[SB] = "sb\n";
	arr[SS] = "ss\n";
	arr[PA] = "pa\n";
	arr[PB] = "pb\n";
	arr[RA] = "ra\n";
	arr[RB] = "rb\n";
	arr[RR] = "rr\n";
	arr[RRA] = "rra\n";
	arr[RRB] = "rrb\n";
	arr[RRR] = "rrr\n";
	s = stack->ops;
	stack->ops = ft_strjoin(stack->ops, arr[instr]);
	free(s);
}

void	run_instr(t_stack *stack, int instr)
{
	void	(*arr[11])(t_stack *stack);

	arr[SA] = sa;
	arr[SB] = sb;
	arr[SS] = ss;
	arr[PA] = pa;
	arr[PB] = pb;
	arr[RA] = ra;
	arr[RB] = rb;
	arr[RR] = rr;
	arr[RRA] = rra;
	arr[RRB] = rrb;
	arr[RRR] = rrr;
	arr[instr](stack);
}

void	execute(t_stack *stack, int instr)
{
	save_instr(stack, instr);
	run_instr(stack, instr);
}
