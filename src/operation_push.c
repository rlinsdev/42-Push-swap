/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 07:04:06 by rlins             #+#    #+#             */
/*   Updated: 2022/10/14 15:12:13 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	push(t_stack **stack_orig, t_stack **stack_dest);

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
	test_print_list(*stack_a);
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
	test_print_list(*stack_a);
}

/**
 * @brief Push/send the top element of stack
 *
 * @param stack_orig
 * @param stack_dest
 */
static void	push(t_stack **stack_orig, t_stack **stack_dest)
{
	t_stack	*tmp;

	// Do Nothing if dest is null.
	if (*stack_orig == NULL)
		return ;
	tmp = (*stack_orig)->next;
	(*stack_orig)->next = *stack_dest;
	*stack_dest = *stack_orig;
	*stack_orig = tmp;
}
