/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmbuyamb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 15:11:29 by cmbuyamb          #+#    #+#             */
/*   Updated: 2018/09/05 15:11:32 by cmbuyamb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stack *stack)
{
	int		tmp;
	int		i;

	if (stack->stack_a_size < 2)
		return ;
	tmp = stack->stack_a[0];
	i = 1;
	while (i++ < stack->stack_a_size)
		stack->stack_a[i - 2] = stack->stack_a[i - 1];
	stack->stack_a[stack->stack_a_size - 1] = tmp;
}

void	rb(t_stack *stack)
{
	int		tmp;
	int		i;

	if (stack->stack_b_size < 2)
		return ;
	tmp = stack->stack_b[0];
	i = 1;
	while (i++ < stack->stack_b_size)
		stack->stack_b[i - 2] = stack->stack_b[i - 1];
	stack->stack_b[stack->stack_b_size - 1] = tmp;
}

void	rr(t_stack *stack)
{
	ra(stack);
	rb(stack);
}
