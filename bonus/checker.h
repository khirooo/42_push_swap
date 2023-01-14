/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfergani <kfergani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 22:56:37 by kfergani          #+#    #+#             */
/*   Updated: 2022/07/21 01:05:38 by kfergani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../ft_printf/includes/ft_printf.h"
# include <limits.h>
# include <fcntl.h>
# include <sys/types.h>

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

typedef struct s_arr
{
	char	**ar;
	int		free;
}	t_arr;

# define BUFFER_SIZE 5

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
char	*get_next_line(int fd);
int		ft_new_line(char *s);
void	ft_copy(char *dest, char *src, int size);
char	*init_buffer(size_t size, char *buffer);
char	*ft_append(char	*dest, char	*src);
void	free_backtrack(char **array, int i);
#endif