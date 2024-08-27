/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:16:24 by tkasapog          #+#    #+#             */
/*   Updated: 2024/07/01 12:36:00 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack)
{
	stack -> top = NULL;
	stack -> bottom = NULL;
}

t_node	*ft_addnew(int nbr)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		return (NULL);
	new_node -> nbr = nbr;
	new_node -> next = NULL;
	new_node -> prev = NULL;
	return (new_node);
}

void	ft_addback(t_stack *stack, t_node *new_node)
{
	if (new_node == NULL)
		return ;
	if (stack->bottom == NULL)
	{
		stack->top = new_node;
		stack->bottom = new_node;
	}
	else
	{
		stack->bottom->next = new_node;
		new_node->prev = stack->bottom;
		stack->bottom = new_node;
	}
}

int	find_max(t_stack *stack)
{
	int		max;
	t_node	*current;

	if (stack->top == NULL)
		return (0);
	max = stack->top->nbr;
	current = stack->top->next;
	while (current != NULL)
	{
		if (current->nbr > max)
			max = current->nbr;
		current = current->next;
	}
	return (max);
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	current = stack->top;
	while (current)
	{
		next = current->next;
		free (current);
		current = next;
	}
	stack->top = NULL;
	stack->bottom = NULL;
}
