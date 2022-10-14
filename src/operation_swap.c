/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:48:07 by rlins             #+#    #+#             */
/*   Updated: 2022/10/14 17:27:55 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	swap_stacks(t_stack *first, t_stack *second);

void	swap_a(t_stack *stack_a)
{
	swap_stacks(stack_a, stack_a->next);
	write(1, "sa\n", 3);
	test_print_list(stack_a);
}

void	swap_b(t_stack *stack_b)
{
	swap_stacks(stack_b, stack_b->next);
	write(1, "sb\n", 3);
}

void	swap_swap(t_stack *stack_a, t_stack *stack_b)
{
	swap_stacks(stack_a, stack_a->next);
	swap_stacks(stack_b, stack_b->next);
	write(1, "ss\n", 3);
}

/**
 * @brief Will swap the stacks passed by param
 * @param first First Element
 * @param second Second Element
 */
static void	swap_stacks(t_stack *first, t_stack *second)
{
	int		aux;

	aux = first->value;
	first->value = second->value;
	second->value = aux;
}
