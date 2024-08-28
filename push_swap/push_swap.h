/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:53:49 by tkasapog          #+#    #+#             */
/*   Updated: 2024/07/26 14:43:40 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

typedef struct s_node
{
	int				nbr;
	int				index;
	int				position;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom; 
}	t_stack;

//operations
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *b, t_stack *a);
t_node	*pop(t_stack *stack); 
// stack_init.c
void	init_stack(t_stack *stack);
t_node	*ft_addnew(int nbr);
void	ft_addback(t_stack *stack, t_node *new_node);
int		find_max(t_stack *stack);
void	free_stack(t_stack *stack);
// sorting_helpers.c
int		ft_stacksize(t_stack *stack);
int		find_min(t_stack *stack);
int		find_closest_larger(t_stack *stack, int num);
int		find_position(t_stack *stack, int num);
void	check_and_sort_stack(t_stack *a, t_stack *b);
// condition_check.c
bool	is_sorted(t_stack *stack);
bool	has_duplicate(t_stack *stack, int num);
void	print_error_and_exit(t_stack *a, char **args, int free_args);
bool	is_valid_number(const char *str);
void	free_splits(char **splits);
bool	is_whitespace(const char *str);
// main.c
void	parse_arguments(char **argv, t_stack *a, int free_args);
long	ft_atol(const char *str, char **argv, t_stack *a, int free_args);
char	**handle_argc(int argc, char **argv, int *free_args);
void	cleanup(t_stack *a, t_stack *b, char **args, int free_args);
// sort_small_stack.c
void	move_min_to_b(t_stack *a, t_stack *b);
void	sort_three(t_stack *a);
void	move_min_to_top(t_stack *a);
void	sort_four(t_stack *a, t_stack *b);
void	sort_five(t_stack *a, t_stack *b);
//sort_large.c
void	sort_large(t_stack *a, t_stack *b);
void	smart_push_to_a(t_stack *a, t_stack *b);
void	push_chunk(t_stack *a, t_stack *b, int min, int max);
int		find_closest_in_range(t_stack *a, int min, int max);
int		get_chunk_size(int size);
//index_range.c
void	assign_indexes(t_stack *a);
int		find_max_index(t_stack *stack);
void	rotate_to_range(t_stack *a, int min, int max);
int		find_position_by_index(t_stack *a, int index);
int		has_elements_in_range(t_stack *a, int min, int max);
char	**ft_split(const char *str, char c);
char	*ft_strchr(const char *s, int c);

#endif
