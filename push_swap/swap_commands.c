/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:40:52 by tkasapog          #+#    #+#             */
/*   Updated: 2024/06/28 16:48:31 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	t_node	*first;
	t_node	*second;

	if (a->top && a->top->next)
	{
		first = a->top;
		second = a->top->next;
		first->next = second-> next;
		if (second->next)
		{
			second->next->prev = first;
		}
		else 
		{
			a->bottom = first;
		}
		second->next = first;
		second->prev = NULL;
		first->prev = second;
		a->top = second;
	}
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	t_node	*first;
	t_node	*second;

	if (b->top && b->top->next)
	{
		first = b->top;
		second = b->top->next;
		first->next = second->next;
		if (second->next)
		{
			second->next->prev = first;
		}
		else
		{
			b->bottom = first;
		}
		second->next = first;
		second->prev = NULL;
		first->prev = second;
		b->top = second;
	}
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}

void	free_splits(char **splits)
{
	int	i;

	i = 0;
	while (splits[i])
	{
		free(splits[i]);
		i++;
	}
	free(splits);
}
