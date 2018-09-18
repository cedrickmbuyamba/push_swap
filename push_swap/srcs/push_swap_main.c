/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmbuyamb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 15:10:17 by cmbuyamb          #+#    #+#             */
/*   Updated: 2018/09/05 16:00:08 by mntumba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		push_swap(t_stack *stack)
{
	t_stack	*rev_stack;

	main_algo(stack);
	rev_stack = reverse_stack(stack);
	main_algo(rev_stack);
	m_stack(stack, rev_stack);
	which_rotate(stack);
	remove_rev_stack(&rev_stack);
}

void		ft_display(int instr)
{
	char	*arr[11];

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
	ft_putstr(arr[instr]);
}

void		initialize_stack(t_stack *stack, int argc)
{
	stack->stack_a = (int*)malloc(sizeof(int) * argc);
	stack->stack_b = (int*)ft_memalloc(sizeof(int) * argc);
	stack->size = argc;
	stack->stack_a_size = argc;
	stack->stack_b_size = 0;
	stack->ops = ft_strnew(0);
	stack->rev = false;
}

t_stack		*get_values(int ac, char **av)
{
	int				i;
	int				j;
	t_stack			*stack;

	(ac-- == 1) ? exit(0) : av++;
	stack = (t_stack*)malloc(sizeof(t_stack));
	if (ac == 1)
	{
		av = ft_strsplit(av[0], ' ');
		ac = 0;
		while (av && av[ac])
			ac++;
	}
	initialize_stack(stack, ac);
	i = ac;
	while (i-- > 0)
	{
		stack->stack_a[i] = check(av[i]);
		j = i;
		while (++j < ac)
			(stack->stack_a[j] == stack->stack_a[i] &&
			write(1, "Error\n", 6)) ? exit(1) : 0;
	}
	(is_sorted(stack->stack_a)) ? exit(1) : 0;
	return (stack);
}

int			main(int ac, char **av)
{
	t_stack		*stack;
	t_stack		*cp_stack;
	char		*ops;
	int			instr;

	stack = get_values(ac, av);
	cp_stack = copy_stack(stack);
	push_swap(stack);
	ops = stack->ops;
	if (ops)
		while ((instr = get_instr(&ops)) != -1)
			ft_display(instr);
	remove_stack(&stack);
	remove_stack(&cp_stack);
}
