/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmbuyamb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 15:09:51 by cmbuyamb          #+#    #+#             */
/*   Updated: 2018/09/05 15:09:57 by cmbuyamb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stack *stack)
{
	int tmp;

	if (stack->stack_a_size < 2)
		return ;
	tmp = stack->stack_a[0];
	stack->stack_a[0] = stack->stack_a[1];
	stack->stack_a[1] = tmp;
}

void	sb(t_stack *stack)
{
	int tmp;

	if (stack->stack_b_size < 2)
		return ;
	tmp = stack->stack_b[0];
	stack->stack_b[0] = stack->stack_b[1];
	stack->stack_b[1] = tmp;
}

void	ss(t_stack *stack)
{
	sa(stack);
	sb(stack);
}

void	pa(t_stack *stack)
{
	int		i;

	if (!stack->stack_b_size)
		return ;
	i = stack->stack_a_size;
	while (i-- > 0)
		stack->stack_a[i + 1] = stack->stack_a[i];
	stack->stack_a[0] = stack->stack_b[0];
	i = 0;
	while (i++ < stack->stack_b_size - 1)
		stack->stack_b[i - 1] = stack->stack_b[i];
	stack->stack_a_size++;
	stack->stack_b_size--;
}

void	pb(t_stack *stack)
{
	int		i;

	if (!stack->stack_a_size)
		return ;
	i = stack->stack_b_size;
	while (i-- > 0)
		stack->stack_b[i + 1] = stack->stack_b[i];
	stack->stack_b[0] = stack->stack_a[0];
	i = 0;
	while (i++ < stack->stack_a_size - 1)
		stack->stack_a[i - 1] = stack->stack_a[i];
	stack->stack_b_size++;
	stack->stack_a_size--;
}
