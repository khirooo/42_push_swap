/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfergani <kfergani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 00:49:40 by kfergani          #+#    #+#             */
/*   Updated: 2022/07/21 15:54:19 by kfergani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_backtrack(char **array, int i)
{
	while (i-- >= 0)
		free(array[i]);
	free(array);
}

static int	ft_is_sorted(t_stack *a)
{
	if (!a)
		return (0);
	while (a->nxt)
	{
		if (a->x > a->nxt->x)
			break ;
		a = a->nxt;
	}
	if (!a->nxt)
		return (1);
	return (0);
}

void	ft_execute_a(t_stack **a, t_stack **b, char *inst)
{
	if (!ft_strncmp(inst, "pa\n", 3))
		ft_pa(a, b);
	if (!ft_strncmp(inst, "sa\n", 3))
		ft_sa(a);
	if (!ft_strncmp(inst, "rra\n", 4) || !ft_strncmp(inst, "rrr\n", 4))
		ft_rra(a);
	else if (!ft_strncmp(inst, "ra\n", 3) || !ft_strncmp(inst, "rr\n", 3))
		ft_ra(a);
}

void	ft_execute_b(t_stack **b, t_stack **a, char *inst)
{
	if (!ft_strncmp(inst, "pb\n", 3))
		ft_pb(b, a);
	if (!ft_strncmp(inst, "sb\n", 3))
		ft_sb(b);
	if (!ft_strncmp(inst, "rrb\n", 4) || !ft_strncmp(inst, "rrr\n", 4))
		ft_rrb(b);
	else if (!ft_strncmp(inst, "rb\n", 3) || !ft_strncmp(inst, "rr\n", 3))
		ft_rb(b);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	char	*inst;

	ft_init_stack(&a, &argc, argv);
	if (argc <= 1 || ft_is_sorted(a))
		return (0);
	inst = get_next_line(0);
	while (inst)
	{
		ft_execute_a(&a, &b, inst);
		ft_execute_b(&b, &a, inst);
		free(inst);
		inst = get_next_line(0);
	}
	if (ft_is_sorted(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}
