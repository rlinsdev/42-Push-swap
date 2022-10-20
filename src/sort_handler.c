/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 09:05:17 by rlins             #+#    #+#             */
/*   Updated: 2022/10/20 09:48:36 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	set_head_stack(t_stack **stack_a);

void	simple_sort(t_stack **stack_a)
{
	int		high_index;

	high_index = find_highest_index(*stack_a);
	if ((*stack_a)->index == high_index)
		rotate_a(stack_a);
	else if ((*stack_a)->next->index == high_index)
		r_rotate_a(stack_a);
	if ((*stack_a)->index > (*stack_a)->next->index)
		swap_a(stack_a);
}

void	core_sort_stack(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	push_all_but_three(stack_a, stack_b, stack_size);
	simple_sort(stack_a);
	while (*stack_b)
	{
		handler_target_position(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		exec_cheapest_move(stack_a, stack_b);
	}
	if (!is_stack_sorted(*stack_a))
		set_head_stack(stack_a);
}

/**
 * @brief Will rotate (or reverse rotate) Stack A until the head stay in
 * position 0. (To order the list, this situation may occur). Just rotate to
 * the correct spot
 * @param stack_a
 */
static void	set_head_stack(t_stack **stack_a)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = get_stack_size(*stack_a);
	lowest_pos = get_position_lower_element(stack_a);
	if (lowest_pos > (stack_size / 2))
	{
		while (lowest_pos < stack_size)
		{
			r_rotate_a(stack_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			rotate_a(stack_a);
			lowest_pos--;
		}
	}
}
