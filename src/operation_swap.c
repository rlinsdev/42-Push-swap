/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:48:07 by rlins             #+#    #+#             */
/*   Updated: 2022/10/18 10:23:51 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	swap(t_stack *stack);

void	swap_a(t_stack **stack_a)
{
	swap(*stack_a);
	write(1, "sa\n", 3);
	ft_print_list(*stack_a, 'A');
}

void	swap_b(t_stack **stack_b)
{
	swap(*stack_b);
	write(1, "sb\n", 3);
}

void	swap_swap(t_stack **stack_a, t_stack **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	write(1, "ss\n", 3);
}

/** [Passed]
 * @brief Will swap the stacks passed by param. Swap value and index
 * @param stack Stack with 2 elements to swap
 */
static void	swap(t_stack *stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	// Update Value
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
	// TODO: Other operations work with index to?
	// Update Index
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
}
