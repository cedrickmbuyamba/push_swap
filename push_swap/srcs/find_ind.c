/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_ind.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmbuyamb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 15:08:38 by cmbuyamb          #+#    #+#             */
/*   Updated: 2018/09/05 16:15:22 by mntumba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	find_ind1(t_stack *stack, int val_a)
{
	int		i;
	int		max_ind_b;
	int		min_ind_b;

	i = 0;
	min_ind_b = 0;
	max_ind_b = 0;
	while (++i < stack->stack_b_size)
		if (stack->stack_b[i] < stack->stack_b[min_ind_b])
			min_ind_b = i;
		else if (stack->stack_b[i] > stack->stack_b[max_ind_b])
			max_ind_b = i;
	if (val_a > stack->stack_b[max_ind_b])
		return (max_ind_b);
	if (val_a < stack->stack_b[min_ind_b])
		return (min_ind_b + 1) % stack->stack_b_size;
	i = -1;
	while (++i < stack->stack_b_size)
		if (stack->stack_b[i] > val_a &&
				stack->stack_b[(i + 1) % stack->stack_b_size] < val_a)
			return (i + 1) % stack->stack_b_size;
	return (-1);
}

static int	find_rev_ind(t_stack *stack, int val_a)
{
	int		i;
	int		max_ind_b;
	int		min_ind_b;

	i = 0;
	max_ind_b = 0;
	min_ind_b = 0;
	while (++i < stack->stack_b_size)
		if (stack->stack_b[i] < stack->stack_b[min_ind_b])
			min_ind_b = i;
		else if (stack->stack_b[i] > stack->stack_b[max_ind_b])
			max_ind_b = i;
	if (val_a > stack->stack_b[max_ind_b])
		return (max_ind_b + 1) % stack->stack_b_size;
	if (val_a < stack->stack_b[min_ind_b])
		return (min_ind_b);
	i = -1;
	while (++i < stack->stack_b_size)
		if (stack->stack_b[i] < val_a &&
				stack->stack_b[(i + 1) % stack->stack_b_size] > val_a)
			return (i + 1) % stack->stack_b_size;
	return (-1);
}

static int	**nbr_ops(t_stack *stack)
{
	int		ind_a;
	int		**ops;

	ind_a = -1;
	ops = malloc(sizeof(int*) * stack->stack_a_size);
	while (++ind_a < stack->stack_a_size)
	{
		ops[ind_a] = ft_calc(stack, ind_a);
	}
	return (ops);
}

int			which_ind(t_stack *stack, int ind)
{
	return (stack->rev ? find_rev_ind(stack, stack->stack_a[ind]) :
			find_ind1(stack, stack->stack_a[ind]));
}

int			*find_ind(t_stack *stack)
{
	int				i;
	int				**ops;
	int				min_ind;
	int				*rot;

	ops = nbr_ops(stack);
	min_ind = -1;
	i = -1;
	while (++i < stack->stack_a_size)
		if (min_ind == -1 || ops[i][0] < ops[min_ind][0])
		{
			(min_ind != -1) ? free(ops[min_ind]) : (0);
			min_ind = i;
		}
		else
			free(ops[i]);
	rot = (int*)malloc(sizeof(int) * 6);
	i = -1;
	while (++i < 6)
		rot[i] = ops[min_ind][i];
	free(ops[min_ind]);
	free(ops);
	return (rot);
}
