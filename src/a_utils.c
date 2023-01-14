/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfergani <kfergani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:58:21 by kfergani          #+#    #+#             */
/*   Updated: 2022/07/21 05:42:30 by kfergani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sa(t_stack **stack_a)
{
	t_stack	*temp;
	int		temp2;

	if (stack_a)
	{
		temp = *stack_a;
		if (temp && temp->nxt)
		{
			temp2 = temp->x;
			temp->x = temp->nxt->x;
			temp->nxt->x = temp2;
			ft_printf("sa\n");
		}
	}
}

void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_b;

	if (!stack_a || !stack_b)
		return ;
	temp_b = *stack_b;
	if (!temp_b)
		return ;
	*stack_b = temp_b->nxt;
	temp_b->nxt = *stack_a;
	*stack_a = temp_b;
	ft_printf("pa\n");
}

void	ft_ra(t_stack **stack_a)
{
	t_stack	*temp;
	int		i;

	if (!stack_a)
		return ;
	temp = *stack_a;
	if (!temp || !temp->nxt)
		return ;
	i = temp->x;
	while (temp->nxt)
	{
		temp->x = temp->nxt->x;
		temp = temp->nxt;
	}
	temp->x = i;
	ft_printf("ra\n");
}

void	ft_rra(t_stack **stack_a)
{
	t_stack	*temp;
	int		i;
	int		j;

	if (!stack_a)
		return ;
	temp = *stack_a;
	if (!temp || !temp->nxt)
		return ;
	j = temp->x;
	while (temp->nxt)
	{
		i = temp->nxt->x;
		temp->nxt->x = j;
		j = i;
		temp = temp->nxt;
	}
	(*stack_a)->x = j;
	ft_printf("rra\n");
}

t_index	ft_scan_top(t_stack *stack, t_array array, int chunk, int n)
{
	int		i;
	t_index	pos;
	int		*sorted;

	sorted = ft_sort_array(array.a, array.size);
	pos.pos = 0;
	pos.chunk = chunk;
	while (stack)
	{
		if (stack->x <= sorted[((array.size / n) * chunk) - 1]
			&& stack->x >= sorted[(array.size / n) * (chunk - 1)])
			return (pos);
		if ((stack->x <= sorted[((array.size / n) * (chunk + 1)) - 1]
				&& stack->x >= sorted[(array.size / n) * ((chunk + 1) - 1)])
			|| chunk == array.size / n || chunk + 1 == array.size / n)
		{
			pos.chunk = chunk + 1;
			return (pos);
		}
		stack = stack->nxt;
		pos.pos++;
	}
	pos.pos = -1;
	free(sorted);
	return (pos);
}
