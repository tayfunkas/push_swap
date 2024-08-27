/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:57:01 by tkasapog          #+#    #+#             */
/*   Updated: 2024/07/15 17:38:41 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_min_to_b(t_stack *a, t_stack *b)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	first = a->top;
	second = first->next;
	third = second->next;
	if (first->nbr < second->nbr && first->nbr < third->nbr)
		pb(b, a);
	else if (second-> nbr < first->nbr && second->nbr < third->nbr)
	{
		sa(a);
		pb(b, a);
	}
	else
	{
		rra(a);
		pb(b, a);
	}
}

void	sort_three(t_stack *a)
{
	int	third;
	int	second;

	if (!a || !a->top || !a->top->next || !a->top->next->next)
		return ;
	second = a->top->next->nbr;
	third = a->top->next->next->nbr;
	if (a->top->nbr > second && second < third && a->top->nbr < third)
		sa(a);
	else if (a->top->nbr > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (a->top->nbr > second && second < third && a->top->nbr > third)
		ra(a);
	else if (a->top->nbr < second && second > third && a->top->nbr < third)
	{
		sa(a);
		ra(a);
	}
	else if (a->top->nbr < second && second > third && a->top->nbr > third)
		rra(a);
}

void	move_min_to_top(t_stack *a)
{
	int	min;
	int	min_pos;
	int	size;

	min = find_min(a);
	min_pos = find_position(a, min);
	size = ft_stacksize(a);
	if (min_pos <= size / 2)
	{
		while (a->top->nbr != min)
			ra(a);
	}
	else
	{
		while (a->top->nbr != min)
			rra(a);
	}
}

void	sort_four(t_stack *a, t_stack *b)
{
	int	min;

	if (!a || !b || !a->top || ft_stacksize(a) != 4)
		return ;
	min = find_min(a);
	while (a->top->nbr != min)
		ra(a);
	pb(b, a);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	elements_to_push;

	elements_to_push = 2;
	while (elements_to_push > 0)
	{
		move_min_to_top(a);
		pb(b, a);
		elements_to_push--;
	}
	sort_three(a);
	while (b->top != NULL)
		pa(a, b);
}
