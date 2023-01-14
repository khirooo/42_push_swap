/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfergani <kfergani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 01:29:53 by kfergani          #+#    #+#             */
/*   Updated: 2022/07/23 01:57:36 by kfergani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_backtrack(char **array, int i, t_stack **a, int mode)
{
	t_stack	*temp;

	if (mode == 1)
	{
		while (i-- >= 0)
			free(array[i]);
		free(array);
	}
	else
	{
		if (!(*a))
			return ;
		temp = *a;
		while ((*a)->nxt)
		{
			(*a) = (*a)->nxt;
			free(temp);
			temp = *a;
		}
		free(temp);
	}
}

t_max	ft_get_min(t_stack *a, int argc)
{
	int		i;
	t_max	min;

	min.m1 = a->x;
	min.m2 = 0;
	i = 0;
	while (a)
	{
		if (a->x < min.m1)
		{
			min.m1 = a->x;
			min.m2 = i;
		}
		i++;
		a = a->nxt;
	}
	return (min);
}

int	*ft_copy_array(int *args, int argc)
{
	int	*array;
	int	i;

	array = (int *)malloc(sizeof(int) * argc);
	i = 0;
	while (i < argc)
	{
		array[i] = args[i];
		i++;
	}
	return (array);
}

int	*ft_sort_array(int *args, int argc)
{
	int	i;
	int	j;
	int	temp;
	int	*array;

	array = ft_copy_array(args, argc);
	i = 0;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (array);
}

int	ft_last1(t_stack *a)
{
	int	x;

	if (a)
		x = a->x;
	while (a)
	{
		x = a->x;
		a = a->nxt;
	}
	return (x);
}
