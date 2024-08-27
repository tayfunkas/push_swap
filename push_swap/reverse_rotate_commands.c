/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_commands.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:11:35 by tkasapog          #+#    #+#             */
/*   Updated: 2024/06/28 16:24:06 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a)
{
	t_node	*bottom;
	t_node	*second_last;

	if (a->top && a->top->next)
	{
		bottom = a->bottom;
		second_last = a->bottom->prev;
		bottom->prev->next = NULL;
		a->top->prev = bottom; 
		bottom->prev = NULL; 
		bottom->next = a->top;
		a->top = bottom;
		a->bottom = second_last;
	}
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	t_node	*bottom;
	t_node	*second_last;

	if (b->top && b->top->next)
	{
		bottom = b->bottom;
		second_last = b->bottom->prev;
		bottom->prev->next = NULL;
		b->top->prev = bottom;
		bottom->prev = NULL;
		bottom->next = b->top;
		b->top = bottom;
		b->bottom = second_last;
	}
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}
