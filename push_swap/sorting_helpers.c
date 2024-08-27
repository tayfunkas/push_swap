/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:36:46 by tkasapog          #+#    #+#             */
/*   Updated: 2024/07/01 17:46:31 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stacksize(t_stack *stack)
{
	int		size;
	t_node	*current;

	size = 0;
	current = stack->top;
	while (current != NULL)
	{
		size++;
		current = current->next;
	}
	return (size);
}

int	find_min(t_stack *stack)
{
	int		min;
	t_node	*current;

	if (stack->top == NULL)
		return (INT_MAX);
	min = stack->top->nbr;
	current = stack->top->next;
	while (current != NULL)
	{
		if (current->nbr < min)
			min = current->nbr;
		current = current->next;
	}
	return (min);
}

int	find_position(t_stack *stack, int num)
{
	int		position;
	t_node	*current;

	position = 0;
	current = stack->top;
	while (current)
	{
		if (current->nbr == num)
			return (position);
		position++;
		current = current->next;
	}
	return (-1);
}

int	find_closest_larger(t_stack *stack, int num)
{
	t_node	*current;
	int		position;
	int		target_position;
	int		closest_largest;

	current = stack->top;
	position = 0;
	target_position = -1;
	closest_largest = INT_MAX;
	while (current)
	{
		if (current->nbr > num && current->nbr < closest_largest)
		{
			closest_largest = current->nbr;
			target_position = position;
		}
		position++;
		current = current->next;
	}
	return (target_position);
}

void	check_and_sort_stack(t_stack *a, t_stack *b)
{
	int	size;

	size = ft_stacksize(a);
	if (size == 2)
	{
		if (a->top->nbr > a->top->next->nbr)
			sa(a);
	}
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
		sort_four(a, b);
	else if (size == 5)
		sort_five(a, b);
	else
		sort_large(a, b);
	return ;
}
