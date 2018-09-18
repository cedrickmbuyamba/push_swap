/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmbuyamb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 15:06:16 by cmbuyamb          #+#    #+#             */
/*   Updated: 2018/09/05 16:14:59 by mntumba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <limits.h>

int			check(char *str)
{
	long long	res;
	char		*s;

	s = str;
	while (s && *s)
	{
		if (!ft_isdigit(*s) && *s != '-' && write(1, "Error\n", 6))
			exit(1);
		s++;
	}
	res = ft_atoi(str);
	if ((res > INT32_MAX || res < INT32_MIN) && write(1, "Error\n", 6))
		exit(1);
	return ((int)res);
}

int			is_sorted(int *a)
{
	int		i;

	i = 0;
	while (a[i])
	{
		if (a[i] > a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void		which_rotate(t_stack *stack)
{
	int		i;
	int		small_ind;

	i = 0;
	small_ind = 0;
	while (++i < stack->stack_a_size)
		if (stack->stack_a[i] < stack->stack_a[small_ind])
			small_ind = i;
	i = -1;
	if (small_ind <= stack->stack_a_size / 2)
		while (++i < small_ind)
			execute(stack, RA);
	else
		while (++i < stack->stack_a_size - small_ind)
			execute(stack, RRA);
}

int			get_instr(char **instr)
{
	int		ret;

	ret = -1;
	if (!(**instr))
		return (-1);
	(ft_strncmp(*instr, "sa\n", 3) == 0) ? ret = SA : (0);
	(ft_strncmp(*instr, "sb\n", 3) == 0) ? ret = SB : (0);
	(ft_strncmp(*instr, "ss\n", 3) == 0) ? ret = SS : (0);
	(ft_strncmp(*instr, "pa\n", 3) == 0) ? ret = PA : (0);
	(ft_strncmp(*instr, "pb\n", 3) == 0) ? ret = PB : (0);
	(ft_strncmp(*instr, "ra\n", 3) == 0) ? ret = RA : (0);
	(ft_strncmp(*instr, "rb\n", 3) == 0) ? ret = RB : (0);
	(ft_strncmp(*instr, "rr\n", 3) == 0) ? ret = RR : (0);
	(ft_strncmp(*instr, "rra\n", 4) == 0) ? ret = RRA : (0);
	(ft_strncmp(*instr, "rrb\n", 4) == 0) ? ret = RRB : (0);
	(ft_strncmp(*instr, "rrr\n", 4) == 0) ? ret = RRR : (0);
	if (ret != -1)
		(*instr) += 3;
	if (ret >= RRA)
		(*instr)++;
	return (ret);
}

int			*ft_calc(t_stack *stack, int ind_a)
{
	int		ind_b;
	int		tmp;
	int		*oper;

	ind_b = (stack->stack_b_size < 2) ? 0 : which_ind(stack, ind_a);
	oper = (int*)malloc(sizeof(int) * 6);
	oper[0] = (BEGIN(ind_a, stack->stack_a_size)) +
			(BEGIN(ind_b, stack->stack_b_size));
	oper[1] = 0;
	oper[2] = stack->stack_a[ind_a];
	oper[3] = stack->stack_b[ind_b];
	oper[4] = INSTR_A(ind_a, stack->stack_a_size);
	oper[5] = INSTR_B(ind_b, stack->stack_b_size);
	if ((tmp = NBR_RR(ind_a, ind_b)) <= oper[0])
	{
		oper[0] = tmp;
		oper[1] = RR;
	}
	if ((tmp = NBR_RRR(ind_a, ind_b, stack->stack_a_size,
					stack->stack_b_size)) <= oper[0])
	{
		oper[0] = tmp;
		oper[1] = RRR;
	}
	return (oper);
}
