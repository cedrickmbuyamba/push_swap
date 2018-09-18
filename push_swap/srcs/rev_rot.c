/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmbuyamb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 15:11:07 by cmbuyamb          #+#    #+#             */
/*   Updated: 2018/09/05 15:11:10 by cmbuyamb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_stack *stack)
{
	int		tmp;
	int		i;

	if (stack->stack_a_size < 2)
		return ;
	tmp = stack->stack_a[stack->stack_a_size - 1];
	i = stack->stack_a_size;
	while (i-- > 1)
		stack->stack_a[i] = stack->stack_a[i - 1];
	stack->stack_a[0] = tmp;
}

void	rrb(t_stack *stack)
{
	int		tmp;
	int		i;

	if (stack->stack_b_size < 2)
		return ;
	tmp = stack->stack_b[stack->stack_b_size - 1];
	i = stack->stack_b_size;
	while (i-- > 1)
		stack->stack_b[i] = stack->stack_b[i - 1];
	stack->stack_b[0] = tmp;
}

void	rrr(t_stack *stack)
{
	rra(stack);
	rrb(stack);
}
