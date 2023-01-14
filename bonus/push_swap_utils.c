/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfergani <kfergani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:19:37 by kfergani          #+#    #+#             */
/*   Updated: 2022/07/21 01:28:45 by kfergani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
		free_backtrack(args.ar, *argc);
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

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(src);
	if (dstsize != 0)
	{
		i = 0;
		while (i < dstsize - 1 && i < len)
		{
			dst[i] = src[i];
			i++;
		}
			dst[i] = '\0';
	}
	return (len);
}
