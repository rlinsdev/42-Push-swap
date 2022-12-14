/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_r_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:33:52 by rlins             #+#    #+#             */
/*   Updated: 2022/10/21 08:15:07 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	r_rotate_stack(t_stack **stack);

void	r_rotate_a(t_stack **stack_a)
{
	r_rotate_stack(stack_a);
	write(1, "rra\n", 4);
	ft_print_list(*stack_a, 'A');
}

void	r_rotate_b(t_stack **stack_b)
{
	r_rotate_stack(stack_b);
	write(1, "rrb\n", 4);
	ft_print_list(*stack_b, 'B');
}

void	rr_rotate(t_stack **stack_a, t_stack **stack_b)
{
	r_rotate_stack(stack_a);
	r_rotate_stack(stack_b);
	write(1, "rrr\n", 4);
}

/**
 * @brief Reverse Rotate Stack
 * @param stack - by ref. Will rotate the list
 */
static void	r_rotate_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;
	t_stack	*before_tail;

	tail = get_last_stack(*stack);
	before_tail = get_stack_before_tail(*stack);
	tmp = *stack;
	*stack = tail;
	(*stack)->next = tmp;
	before_tail->next = NULL;
}
