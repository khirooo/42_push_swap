/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfergani <kfergani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:53:31 by kfergani          #+#    #+#             */
/*   Updated: 2022/07/23 01:51:00 by kfergani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include <limits.h>

typedef struct s_stack
{
	int				x;
	struct s_stack	*nxt;
}	t_stack;

typedef struct s_array
{
	int	*a;
	int	size;
}	t_array;

typedef struct s_index
{
	int	pos;
	int	chunk;
}	t_index;

typedef struct s_max
{
	int	m1;
	int	m2;
	int	m3;
}t_max;

typedef struct s_h
{
	int		i;
	int		j;
	int		k;
	t_max	*m;
	t_array	ar;
}	t_h;

typedef struct s_arr
{
	char	**ar;
	int		free;
}	t_arr;

void	ft_sa(t_stack **stack_a);
void	ft_pa(t_stack **stack_a, t_stack **stack_b);
void	ft_ra(t_stack **stack_a);
void	ft_rra(t_stack **stack_a);
void	ft_sb(t_stack **stack_b);
void	ft_pb(t_stack **stack_b, t_stack **stack_a);
void	ft_rb(t_stack **stack_b);
void	ft_rrb(t_stack **stack_b);
void	ft_ss(t_stack **stack_a, t_stack **stack_b);
void	ft_rr(t_stack **stack_a, t_stack **stack_b);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);
void	ft_add(t_stack **stack, t_stack	*node);
t_stack	*ft_new(int x);
int		ft_is_valid(char *num, int argc, char **argv, int index);
void	ft_init_stack(t_stack **a, int *argc, char **argv);
t_array	ft_get_int_args(t_stack *a);
void	free_backtrack(char **array, int i, t_stack **a, int mode);
t_max	ft_get_min(t_stack *a, int argc);
int		*ft_sort_array(int *args, int argc);
t_index	ft_scan_top(t_stack *stack, t_array args, int chunk, int n);
t_index	ft_scan_bottom(t_stack *stack, t_array args, int chunk, int n);
void	ft_move_to_b(t_stack **a, t_stack **b, t_index top, t_index bottom);
void	ft_move_to_a(t_stack **a, t_stack **b);
t_max	ft_get_max(t_stack *b);
int		ft_last1(t_stack *a);
void	free_list(t_stack **a);

#endif