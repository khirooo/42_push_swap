/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfergani <kfergani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:40:10 by kfergani          #+#    #+#             */
/*   Updated: 2022/07/21 07:47:52 by kfergani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	help_scan(t_h h, int *sorted, t_array args, t_index *pos)
{
	if ((h.ar.a[h.k] <= sorted[((args.size / h.j) * (h.i + 1)) - 1]
			&& h.ar.a[h.k] >= sorted[(args.size / h.j) * ((h.i + 1) - 1)])
		|| h.i == h.j || h.i + 1 == h.j)
	{
		pos->chunk = h.i + 1;
		return (1);
	}
	return (0);
}

t_index	ft_scan_bottom(t_stack *stack, t_array args, int chunk, int n)
{
	t_index	pos;
	int		*sorted;
	t_h		h;

	sorted = ft_sort_array(args.a, args.size);
	h.ar = ft_get_int_args(stack);
	h.k = h.ar.size - 1;
	pos.pos = 0;
	pos.chunk = chunk;
	while (h.k >= 0)
	{
		if (h.ar.a[h.k] <= sorted[((args.size / n) * chunk) - 1]
			&& h.ar.a[h.k] >= sorted[(args.size / n) * (chunk - 1)])
			return (pos);
		h.i = chunk;
		h.j = n;
		if (help_scan(h, sorted, args, &pos))
			return (pos);
		pos.pos++;
		h.k--;
	}
	pos.pos = -1;
	free(sorted);
	return (pos);
}

void	ft_move_to_b(t_stack **a, t_stack **b, t_index top, t_index bottom)
{
	if (bottom.pos != -1)
		bottom.pos++;
	if ((bottom.pos == -1 && top.pos != -1) || top.pos <= bottom.pos)
		while (top.pos-- > 0)
			ft_ra(a);
	else
		while (bottom.pos-- > 0)
			ft_rra(a);
	ft_pb(b, a);
	if (top.chunk == 0)
		ft_rb(b);
}

void	helper_move_a(t_stack	**a, t_stack **b, t_h h)
{
	while (h.j >= 0 && h.ar.a[h.j] != h.m->m1 && h.ar.a[h.j] != h.m->m2
		&& h.ar.a[h.j] != h.m->m3)
		h.j--;
	if (h.i == h.ar.size)
	{
		if ((*a)->x == h.m->m1)
			ft_sa(a);
		if ((*a)->x == h.m->m2)
			ft_rra(a);
		*h.m = ft_get_max(*b);
	}
	else
	{
		if (h.i < h.ar.size - h.j)
			while (h.i-- > 0)
				ft_rb(b);
		else
			while (h.j++ < h.ar.size)
				ft_rrb(b);
		if ((*a) && (*a)->x == h.m->m1 && (*a)->nxt && (*a)->nxt->x == h.m->m2)
			ft_sa(a);
		ft_pa(a, b);
		if ((*a) && (*a)->x == h.m->m3)
			ft_ra(a);
	}
}

void	ft_move_to_a(t_stack **a, t_stack **b)
{
	t_array	r;
	int		i;
	t_max	m;
	t_h		h;

	m = ft_get_max(*b);
	while (*b)
	{
		r = ft_get_int_args(*b);
		i = 0;
		while (i < r.size && r.a[i] != m.m1 && r.a[i] != m.m2 && r.a[i] != m.m3)
			i++;
		h.j = r.size - 1;
		h.i = i;
		h.m = &m;
		h.ar = r;
		helper_move_a(a, b, h);
		free(r.a);
	}
	if ((*a)->x == m.m1 && (*a)->nxt->x == m.m2)
		ft_sa(a);
	m = ft_get_max(*a);
	while (ft_last1(*a) != m.m1)
		ft_rra(a);
}
