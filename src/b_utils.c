/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfergani <kfergani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 15:31:26 by kfergani          #+#    #+#             */
/*   Updated: 2022/07/19 23:51:19 by kfergani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sb(t_stack **stack_b)
{
	t_stack	*temp;
	int		temp2;

	if (stack_b)
	{
		temp = *stack_b;
		if (temp && temp->nxt)
		{
			temp2 = temp->x;
			temp->x = temp->nxt->x;
			temp->nxt->x = temp2;
			ft_printf("sb\n");
		}
	}
}

void	ft_pb(t_stack **stack_b, t_stack **stack_a)
{
	t_stack	*temp_a;

	if (!stack_b || !stack_a)
		return ;
	temp_a = *stack_a;
	if (!temp_a)
		return ;
	*stack_a = temp_a->nxt;
	temp_a->nxt = *stack_b;
	*stack_b = temp_a;
	ft_printf("pb\n");
}

void	ft_rb(t_stack **stack_b)
{
	t_stack	*temp;
	int		i;

	if (!stack_b)
		return ;
	temp = *stack_b;
	if (!temp || !temp->nxt)
		return ;
	i = temp->x;
	while (temp->nxt)
	{
		temp->x = temp->nxt->x;
		temp = temp->nxt;
	}
	temp->x = i;
	ft_printf("rb\n");
}

void	ft_rrb(t_stack **stack_b)
{
	t_stack	*temp;
	int		i;
	int		j;

	if (!stack_b)
		return ;
	temp = *stack_b;
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
	(*stack_b)->x = j;
	ft_printf("rrb\n");
}
