/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_r_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:33:52 by rlins             #+#    #+#             */
/*   Updated: 2022/10/15 14:52:49 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	r_rotate_stack(t_stack **stack);
static t_stack	*get_stack_tail(t_stack *stack);
static t_stack	*get_stack_before_tail(t_stack *stack);

void	r_rotate_a(t_stack **stack_a)
{
	r_rotate_stack(stack_a);
	write(1, "rra\n", 4);
	ft_print_list(*stack_a);
}

void	r_rotate_b(t_stack **stack_b)
{
	r_rotate_stack(stack_b);
	write(1, "rrb\n", 4);
	ft_print_list(*stack_b);
}

void	rr_rotate(t_stack **stack_a, t_stack **stack_b)
{
	r_rotate_stack(stack_a);
	r_rotate_stack(stack_b);
	write(1, "rrr\n", 4);
}

/**
 * @brief
 *
 * @param stack
 */
static void	r_rotate_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;
	t_stack	*before_tail;

	tail = get_stack_tail(*stack);
	before_tail = get_stack_before_tail(*stack);
	tmp = *stack;
	*stack = tail;
	(*stack)->next = tmp;
	before_tail->next = NULL;
}

// TODO: NAO DARIA CERTO JA PEGAR PELO INDEX AQUI?
/**
 * @brief will return the last element
 * @param stack
 * @return t_stack* Pointer to last stack
 */
static t_stack	*get_stack_tail(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

/**
 * @brief Get the before last element
 * @param stack
 * @return t_stack* before the end
 */
static t_stack	*get_stack_before_tail(t_stack *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}
