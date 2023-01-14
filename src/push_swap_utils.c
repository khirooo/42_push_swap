/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfergani <kfergani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:19:37 by kfergani          #+#    #+#             */
/*   Updated: 2022/07/21 07:48:13 by kfergani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_is_valid(char *num, int argc, char **argv, int index)
{
	int		i;
	char	*temp;

	temp = num;
	while (temp && *temp)
	{
		if (*temp != '-' && *temp != '+' && !ft_isdigit(*temp))
			return (0);
		temp++;
	}
	i = 0;
	while (i < argc)
	{
		if (i != index && !ft_strncmp(num, argv[i], ft_strlen(num))
			&& (ft_strlen(num) == ft_strlen(argv[i])))
			return (0);
		i++;
	}
	return (1);
}

t_arr	ft_get_args(int *argc, char **argv)
{
	t_arr	string_args;
	int		i;

	string_args.free = 0;
	if (*argc == 2)
	{
		string_args.ar = ft_split(argv[1], ' ');
		string_args.free = 1;
		i = 0;
		while (string_args.ar[i])
		{
			i++;
		}
		*argc = i;
	}
	else
	{
		(*argc)--;
		string_args.ar = argv + 1;
	}
	return (string_args);
}

void	ft_init_stack(t_stack **a, int *argc, char **argv)
{
	int		i;
	t_arr	args;

	if (!a)
		return ;
	if (*argc > 2 && !ft_is_valid(argv[1], 0, argv, 0))
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	args = ft_get_args(argc, argv);
	i = *argc - 1;
	while (i >= 0)
	{
		if (!ft_is_valid(args.ar[i], *argc - 1, args.ar, i))
		{
			write(1, "Error\n", 6);
			exit(1);
		}
		ft_add(a, ft_new(ft_atoi(args.ar[i])));
		i--;
	}
	if (args.free)
		free_backtrack(args.ar, *argc, NULL, 1);
}

t_array	ft_get_int_args(t_stack *a)
{
	t_array	int_args;
	int		i;
	t_stack	*temp;

	temp = a;
	i = 0;
	while (temp)
	{
		i++;
		temp = temp->nxt;
	}
	int_args.a = (int *)malloc(sizeof(int) * i);
	int_args.size = i;
	i = 0;
	while (a)
	{
		int_args.a[i++] = a->x;
		a = a->nxt;
	}
	return (int_args);
}

t_max	ft_get_max(t_stack *b)
{
	t_max	m;
	t_array	ar;
	t_h		h;

	ar = ft_get_int_args(b);
	h.j = 0;
	m.m1 = INT_MIN;
	m.m2 = INT_MIN;
	m.m3 = INT_MIN;
	while (h.j++ < 3)
	{
		h.i = 0;
		while (h.i < ar.size)
		{
			if (m.m1 < ar.a[h.i])
				m.m1 = ar.a[h.i];
			if (m.m1 != ar.a[h.i] && m.m2 < ar.a[h.i])
				m.m2 = ar.a[h.i];
			if (m.m1 != ar.a[h.i] && m.m2 != ar.a[h.i] && m.m3 < ar.a[h.i])
				m.m3 = ar.a[h.i];
			h.i++;
		}
	}
	free(ar.a);
	return (m);
}
