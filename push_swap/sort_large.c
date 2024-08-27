/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kurkela.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:28:59 by tkasapog          #+#    #+#             */
/*   Updated: 2024/07/17 14:30:26 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_large(t_stack *a, t_stack *b)
{
	int	size;
	int	chunks;
	int	i;
	int	chunk_size;

	size = ft_stacksize(a);
	chunk_size = get_chunk_size(size);
	chunks = (size + chunk_size - 1) / chunk_size;
	i = 0;
	assign_indexes(a);
	while (i < chunks)
	{
		push_chunk(a, b, i * chunk_size, (i + 1) * chunk_size - 1);
		i++;
	}
	while (ft_stacksize(b) > 0)
	{
		smart_push_to_a(a, b);
	}
}

int	get_chunk_size(int size)
{
	if (size <= 100)
		return (18);
	else if (size <= 500)
		return (27);
	else
		return (size / 12);
}

void	push_chunk(t_stack *a, t_stack *b, int min, int max)
{
	int	pushed;
	int	target;

	pushed = 0;
	target = max - min + 1;
	while (pushed < target && a->top)
	{
		if (a->top->index >= min && a->top->index <= max)
		{
			pb(b, a);
			pushed++;
		}
		else
		{
			rotate_to_range(a, min, max);
		}
	}
}

void	smart_push_to_a(t_stack *a, t_stack *b)
{
	int	max_index;
	int	pos;
	int	size;

	max_index = find_max_index(b);
	pos = find_position_by_index(b, max_index);
	size = ft_stacksize(b);
	while (b->top->index != max_index)
	{
		if (pos <= size / 2)
		{
			rb(b);
		}
		else
		{
			rrb(b);
		}
	}
	pa(a, b);
}

int	find_closest_in_range(t_stack *a, int min, int max)
{
	t_node	*current;
	int		closest_pos;
	int		pos;

	current = a->top;
	closest_pos = -1;
	pos = 0;
	while (current)
	{
		if (current->index >= min && current->index <= max)
		{
			closest_pos = pos;
			break ;
		}
		pos++;
		current = current->next;
	}
	return (closest_pos);
}
