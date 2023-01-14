/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfergani <kfergani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 15:57:41 by kfergani          #+#    #+#             */
/*   Updated: 2022/07/23 02:17:42 by kfergani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	void	ft_sort_3(t_stack **a, t_stack **b, int argc)
{
	if (argc == 2)
	{
		if ((*a)->x > (*a)->nxt->x)
			ft_ra(a);
		return ;
	}
	if ((*a)->x > (*a)->nxt->x && (*a)->x < (*a)->nxt->nxt->x)
		ft_sa(a);
	else if ((*a)->nxt->nxt->x < (*a)->x
		&& (*a)->nxt->nxt->x > (*a)->nxt->x)
		ft_ra(a);
	else if ((*a)->x < (*a)->nxt->x && (*a)->x > (*a)->nxt->nxt->x)
		ft_rra(a);
	else if ((*a)->nxt->x > (*a)->nxt->nxt->x && (*a)->x > (*a)->nxt->x)
	{	
		ft_sa(a);
		ft_rra(a);
	}
	else if ((*a)->x < (*a)->nxt->nxt->x
		&& (*a)->nxt->nxt->x < (*a)->nxt->x)
	{
		ft_sa(a);
		ft_ra(a);
	}
}

static	void	ft_sort_5(t_stack **a, t_stack **b, int argc)
{
	t_max	min;
	t_max	max;

	min = ft_get_min(*a, argc);
	max = ft_get_max(*a);
	if (min.m2 < (5 - min.m2))
		while (min.m2-- > 0)
			ft_ra(a);
	else
		while (min.m2++ < 5)
			ft_rra(a);
	ft_pb(b, a);
	if (argc == 5)
	{
		while ((*a)->x != max.m1)
			ft_ra(a);
		ft_pb(b, a);
	}
	ft_sort_3(a, b, 3);
	ft_pa(a, b);
	if (*b)
	{
		ft_ra(a);
		ft_pa(a, b);
	}
}

static	void	ft_sort_100(t_stack **a, t_stack **b, int n)
{
	t_array	args;
	int		i;
	t_index	t;
	t_index	l;

	args = ft_get_int_args(*a);
	i = 1;
	while (i <= n)
	{
		t = ft_scan_top(*a, args, i, n);
		l = ft_scan_bottom(*a, args, i, n);
		while (t.pos != -1 || l.pos != -1)
		{
			if ((((l.pos == -1 && t.pos != -1) || t.pos <= l.pos + 1)
					&& t.chunk > i)
				|| (((t.pos == -1 && l.pos != -1) || t.pos > l.pos + 1)
					&& l.chunk > i))
					t.chunk = 0;
			ft_move_to_b(a, b, t, l);
			t = ft_scan_top(*a, args, i, n);
			l = ft_scan_bottom(*a, args, i, n);
		}
		i += 2;
	}
	free(args.a);
}

int	ft_is_sorted(t_stack *a)
{
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

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	ft_init_stack(&a, &argc, argv);
	if (argc <= 1 || ft_is_sorted(a))
		return (0);
	if (argc <= 3)
		ft_sort_3(&a, &b, argc);
	else if (argc <= 5)
		ft_sort_5(&a, &b, argc);
	else if (argc < 20)
		ft_sort_100(&a, &b, argc / 3);
	else if (argc < 200)
		ft_sort_100(&a, &b, argc / 10);
	else
		ft_sort_100(&a, &b, 16);
	ft_move_to_a(&a, &b);
	free_backtrack(NULL, 0, &a, 2);
	free_backtrack(NULL, 0, &b, 2);
	return (0);
}
