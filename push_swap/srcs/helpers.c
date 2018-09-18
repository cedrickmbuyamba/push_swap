/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmbuyamb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 15:09:04 by cmbuyamb          #+#    #+#             */
/*   Updated: 2018/09/05 16:01:36 by mntumba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	remove_stack(t_stack **stack)
{
	free((*stack)->stack_a);
	free((*stack)->stack_b);
	free((*stack)->ops);
	free(*stack);
	*stack = NULL;
}

void	remove_rev_stack(t_stack **rev_stack)
{
	free((*rev_stack)->ops);
	free(*rev_stack);
	*rev_stack = NULL;
}

void	m_stack(t_stack *stack, t_stack *rev_stack)
{
	char	*tmp;
	char	*ops;
	int		i;

	ops = ft_strnew(ft_strlen(rev_stack->ops));
	i = -1;
	stack->stack_a_size = stack->size;
	stack->stack_b_size = 0;
	while (rev_stack->ops[++i])
	{
		if (rev_stack->ops[i] == 'a')
			ops[i] = 'b';
		else if (rev_stack->ops[i] == 'b')
			ops[i] = 'a';
		else
			ops[i] = rev_stack->ops[i];
	}
	if (*ops)
	{
		tmp = stack->ops;
		stack->ops = ft_strjoin(stack->ops, ops);
		free(tmp);
	}
	free(ops);
}

t_stack	*copy_stack(t_stack *stack)
{
	t_stack	*copy_stack;

	copy_stack = (t_stack*)malloc(sizeof(t_stack));
	copy_stack->stack_a = (int *)malloc(sizeof(int) * stack->size);
	ft_memcpy(copy_stack->stack_a, stack->stack_a, sizeof(int) * stack->size);
	copy_stack->stack_a_size = stack->stack_a_size;
	copy_stack->stack_b = (int *)malloc(sizeof(int) * stack->size);
	ft_memcpy(copy_stack->stack_b, stack->stack_b, sizeof(int) * stack->size);
	copy_stack->stack_b_size = stack->stack_b_size;
	copy_stack->ops = ft_strdup(stack->ops);
	copy_stack->size = stack->size;
	copy_stack->rev = false;
	return (copy_stack);
}

t_stack	*reverse_stack(t_stack *stack)
{
	t_stack	*rev_stack;

	rev_stack = (t_stack*)malloc(sizeof(t_stack));
	rev_stack->stack_b = stack->stack_a;
	rev_stack->stack_b_size = stack->stack_a_size;
	rev_stack->stack_a = stack->stack_b;
	rev_stack->stack_a_size = stack->stack_b_size;
	rev_stack->ops = ft_strnew(0);
	rev_stack->size = stack->size;
	rev_stack->rev = true;
	return (rev_stack);
}
