/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:33:52 by rlins             #+#    #+#             */
/*   Updated: 2022/10/18 09:19:43 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	rotate_stack(t_stack **stack);

void	rotate_a(t_stack **stack_a)
{
	rotate_stack(stack_a);
	write(1, "ra\n", 3);
	ft_print_list(*stack_a);
}

void	rotate_b(t_stack **stack_b)
{
	rotate_stack(stack_b);
	write(1, "rb\n", 3);
	ft_print_list(*stack_b);
}

void	rotate_rotate(t_stack **stack_a, t_stack **stack_b)
{
	rotate_stack(stack_a);
	rotate_stack(stack_b);
	write(1, "rr\n", 3);
}

/**
 * @brief Stack will receive the pointer to the next. The last one will receive
 * the temp variable
 * @param stack - by ref. Will rotate the list
 */
static void	rotate_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;

	tmp = *stack;
	*stack = (*stack)->next;
	tail = get_last_stack(*stack);
	tmp->next = NULL;
	tail->next = tmp;
}
