/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfergani <kfergani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:58:21 by kfergani          #+#    #+#             */
/*   Updated: 2022/07/21 11:40:23 by kfergani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
}

int	ft_atoi(const char *str)
{
	int				sign;
	unsigned int	num;

	sign = 1;
	num = 0;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		num = num * 10 + (*str - 48);
		if ((num > 2147483647 && sign == 1) || (num > 2147483648 && sign == -1))
		{
			write(1, "Error\n", 6);
			exit (1);
		}
		str++;
	}
	return (num * sign);
}
