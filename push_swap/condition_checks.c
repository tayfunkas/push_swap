/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:19:38 by tkasapog          #+#    #+#             */
/*   Updated: 2024/07/26 14:44:46 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current && current->next)
	{
		if (current->nbr > current->next->nbr)
			return (false);
		current = current->next;
	}
	return (true);
}

bool	has_duplicate(t_stack *stack, int num)
{
	t_node	*current;

	current = stack->top;
	while (current)
	{
		if (current->nbr == num)
			return (true);
		current = current->next;
	}
	return (false);
}

void	print_error_and_exit(t_stack *a, char **args, int free_args)
{
	if (a)
		free_stack(a);
	if (free_args)
		free_splits(args);
	write(2, "Error\n", 6);
	exit(1);
}

bool	is_valid_number(const char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0')
		return (false);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (false);
		str++;
	}
	return (true);
}

bool	is_whitespace(const char *str)
{
	while (*str)
	{
		if (!(*str == 32 || (*str >= 9 && *str <= 13)))
			return (false);
		str++;
	}
	return (true);
}
