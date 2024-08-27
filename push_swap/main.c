/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:46:57 by tkasapog          #+#    #+#             */
/*   Updated: 2024/07/26 18:09:08 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		free_args;

	free_args = 0;
	if (argc < 2)
		return (0);
	if (is_whitespace(argv[1]) && !argv[2])
		return (0);
	init_stack(&a);
	init_stack(&b);
	argv = handle_argc(argc, argv, &free_args);
	parse_arguments(argv, &a, free_args);
	if (is_sorted(&a))
	{
		cleanup(&a, &b, argv, free_args);
		return (0);
	}
	else
		check_and_sort_stack(&a, &b);
	cleanup(&a, &b, argv, free_args);
	return (0);
}

void	parse_arguments(char **argv, t_stack *a, int free_args)
{
	long	num;
	t_node	*new_node;
	char	**original_argv;

	original_argv = argv;
	if (!*argv)
		print_error_and_exit(a, original_argv, free_args);
	while (*argv)
	{
		if (!is_valid_number(*argv))
			print_error_and_exit(a, original_argv, free_args);
		num = ft_atol(*argv, argv, a, free_args);
		if (num > INT_MAX || num < INT_MIN)
			print_error_and_exit(a, original_argv, free_args);
		if (has_duplicate(a, (int)num))
			print_error_and_exit(a, original_argv, free_args);
		new_node = ft_addnew((int)num);
		if (!new_node)
			print_error_and_exit(a, original_argv, free_args);
		ft_addback(a, new_node);
		argv++;
	}
}

long	ft_atol(const char *str, char **argv, t_stack *a, int free_args)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		if (result * sign > INT_MAX || result * sign < INT_MIN)
			print_error_and_exit(a, argv, free_args);
		str++;
	}
	if (*str != '\0')
		print_error_and_exit(a, argv, free_args);
	return (result * sign);
}

char	**handle_argc(int argc, char **argv, int *free_args)
{
	if (argc == 2)
	{
		if (ft_strchr(argv[1], ' ' ) != NULL)
		{
			*free_args = 1;
			return (ft_split(argv[1], ' ' ));
		}
		return (&argv[1]);
	}
	return (argv + 1);
}

void	cleanup(t_stack *a, t_stack *b, char **args, int free_args)
{
	if (free_args)
		free_splits(args);
	free_stack(a);
	free_stack(b);
}
