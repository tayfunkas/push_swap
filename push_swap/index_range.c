/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_range.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:50:12 by tkasapog          #+#    #+#             */
/*   Updated: 2024/07/22 19:17:28 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_indexes(t_stack *a)
{
	t_node	*current;
	t_node	*compare;
	int		index;

	current = a->top;
	while (current)
	{
		index = 0;
		compare = a->top;
		while (compare)
		{
			if (compare->nbr < current->nbr)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

int	find_max_index(t_stack *stack)
{
	t_node	*current;
	int		max_index;

	current = stack->top;
	max_index = current->index;
	while (current)
	{
		if (current->index > max_index)
			max_index = current->index;
		current = current->next;
	}
	return (max_index);
}

int	has_elements_in_range(t_stack *a, int min, int max)
{
	t_node	*current;

	current = a->top;
	while (current)
	{
		if (current->index >= min && current->index <= max)
		{
			return (1);
		}
		current = current->next;
	}
	return (0);
}

int	find_position_by_index(t_stack *a, int index)
{
	t_node	*current;
	int		position;

	current = a->top;
	position = 0;
	while (current)
	{
		if (current->index == index)
			return (position);
		position++;
		current = current->next;
	}
	return (-1);
}

void	rotate_to_range(t_stack *a, int min, int max)
{
	int	pos;

	pos = find_closest_in_range(a, min, max);
	if (pos >= 0)
	{
		while (pos != 0)
		{
			if (pos <= ft_stacksize(a) / 2)
			{
				ra(a);
				pos--;
			}
			else
			{
				rra(a);
				pos++;
				if (pos == ft_stacksize(a)) 
					pos = 0;
			}
		}
	}
}
