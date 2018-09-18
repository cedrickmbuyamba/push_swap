/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmbuyamb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 15:05:40 by cmbuyamb          #+#    #+#             */
/*   Updated: 2018/09/05 15:05:45 by cmbuyamb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	algo(t_stack *stack)
{
	if (stack->stack_a_size == 3)
	{
		if (stack->stack_a[0] < stack->stack_a[2] &&
				stack->stack_a[2] < stack->stack_a[1])
			execute(stack, SA);
		else if (stack->stack_a[1] < stack->stack_a[0] &&
				stack->stack_a[0] < stack->stack_a[2])
			execute(stack, SA);
		else if (stack->stack_a[2] < stack->stack_a[1] &&
				stack->stack_a[1] < stack->stack_a[0])
			execute(stack, SA);
	}
}

void	main_algo(t_stack *s)
{
	int		*ind;

	while (((!s->rev && (s->stack_a_size > 3)) || s->rev) &&
			s->stack_a_size > 0)
	{
		ind = find_ind(s);
		while ((ind[0])-- > 0)
		{
			if (ind[1] && s->stack_a[0] != ind[2] && s->stack_b_size &&
					s->stack_b[0] != ind[3])
				execute(s, ind[1]);
			else if (ind[1] && s->stack_a[0] != ind[2])
				execute(s, ind[1] == RR ? RA : RRA);
			else if (ind[1] && s->stack_b[0] != ind[3])
				execute(s, ind[1] == RR ? RB : RRB);
			else if (s->stack_a[0] != ind[2])
				execute(s, ind[4]);
			else if (s->stack_b[0] != ind[3])
				execute(s, ind[5]);
		}
		free(ind);
		execute(s, PB);
	}
	if (!s->rev)
		algo(s);
}
