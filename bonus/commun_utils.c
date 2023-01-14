/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commun_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfergani <kfergani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 15:35:09 by kfergani          #+#    #+#             */
/*   Updated: 2022/07/20 23:54:50 by kfergani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_sa(stack_a);
	ft_sb(stack_b);
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_ra(stack_a);
	ft_rb(stack_b);
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rra(stack_a);
	ft_rrb(stack_b);
}

t_stack	*ft_new(int x)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->x = x;
	stack->nxt = NULL;
	return (stack);
}

void	ft_add(t_stack **stack, t_stack	*node)
{
	if (!stack)
		return ;
	node->nxt = *stack;
	*stack = node;
}
