/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:26:12 by tkasapog          #+#    #+#             */
/*   Updated: 2024/06/28 16:40:21 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	t_node	*first;

	if (a->top && a->top->next)
	{
		first = a->top;
		a->top = a->top->next;
		a->top->prev = NULL;
		a->bottom->next = first;
		first->prev = a->bottom;
		first->next = NULL;
		a->bottom = first;
	}
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	t_node	*first;

	if (b->top && b->top->next)
	{
		first = b->top;
		b->top = b->top->next;
		b->top->prev = NULL;
		b->bottom->next = first;
		first->prev = b->bottom;
		first->next = NULL;
		b->bottom = first;
	}
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}
