/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:27:12 by tkasapog          #+#    #+#             */
/*   Updated: 2024/06/28 16:32:05 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	t_node	*node_to_push;

	if (b == NULL || b->top == NULL)
		return ;
	node_to_push = pop(b);
	if (a->top == NULL)
	{
		a->top = node_to_push;
		a->bottom = node_to_push;
	}
	else
	{
		node_to_push->next = a->top;
		a->top->prev = node_to_push;
		a->top = node_to_push;
	}
	write(1, "pa\n", 3);
}

void	pb(t_stack *b, t_stack *a)
{
	t_node	*node_to_push;	

	if (a == NULL || a->top == NULL)
		return ;
	node_to_push = pop(a);
	if (b->top == NULL)
	{
		b->top = node_to_push;
		b->bottom = node_to_push;
	}
	else
	{
		node_to_push->next = b->top;
		b->top->prev = node_to_push;
		b->top = node_to_push;
	}
	write(1, "pb\n", 3);
}

t_node	*pop(t_stack *stack)
{
	t_node	*top_node;

	if (stack->top == NULL)
		return (NULL);
	top_node = stack->top;
	stack->top = stack->top->next;
	if (stack->top == NULL)
	{
		stack->bottom = NULL;
	}
	else
	{
		stack->top->prev = NULL;
	}
	top_node->next = NULL;
	top_node->prev = NULL;
	return (top_node);
}
