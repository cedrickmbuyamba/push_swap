/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmbuyamb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 15:07:29 by cmbuyamb          #+#    #+#             */
/*   Updated: 2018/09/05 15:47:41 by mntumba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#define BUFF_SIZE 2048

void		instr_join(t_stack *stack)
{
	char	*buff;
	char	*s;

	buff = ft_memalloc(sizeof(char) * BUFF_SIZE);
	while (read(0, buff, BUFF_SIZE - 1))
	{
		if (stack->ops)
		{
			s = stack->ops;
			stack->ops = ft_strjoin(stack->ops, buff);
			free(s);
		}
		else
			stack->ops = buff;
		ft_bzero(buff, ft_strlen(buff));
	}
	free(buff);
}

void		initialize_info(t_stack *stack, int argc)
{
	stack->stack_a = (int*)malloc(sizeof(int) * argc);
	stack->stack_b = (int*)ft_memalloc(sizeof(int) * argc);
	stack->size = argc;
	stack->stack_a_size = argc;
	stack->stack_b_size = 0;
	stack->ops = ft_strnew(0);
	stack->rev = false;
}

t_stack		*get_values(int argc, char **argv)
{
	int			i;
	int			j;
	t_stack		*stack;

	(argc-- == 1) ? exit(0) : argv++;
	stack = (t_stack*)malloc(sizeof(t_stack));
	if (argc == 1)
	{
		argv = ft_strsplit(argv[0], ' ');
		argc = 0;
		while (argv && argv[argc])
			argc++;
	}
	initialize_info(stack, argc);
	i = argc;
	while (i-- > 0)
	{
		stack->stack_a[i] = check(argv[i]);
		j = i;
		while (++j < argc)
			(stack->stack_a[j] == stack->stack_a[i] &&
			write(1, "Error\n", 6)) ? exit(1) : 0;
	}
	return (stack);
}

int			main(int argc, char **argv)
{
	t_stack		*stack;
	int			instr;
	int			i;
	int			ret;

	ret = 1;
	stack = get_values(argc, argv);
	instr_join(stack);
	while ((instr = get_instr(&stack->ops)) != -1)
		run_instr(stack, instr);
	if (*stack->ops)
		ret = -1;
	i = 0;
	if (stack->stack_a_size != stack->size || stack->stack_b_size != 0)
		ret = 0;
	while (++i < stack->stack_a_size)
		if (stack->stack_a[i] < stack->stack_a[i - 1])
			ret = 0;
	if (ret == -1)
		write(1, "Error\n", 6);
	else if (ret == 0)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}
