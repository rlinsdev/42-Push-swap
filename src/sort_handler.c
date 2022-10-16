/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 09:05:17 by rlins             #+#    #+#             */
/*   Updated: 2022/10/16 08:22:46 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	shift_stack(t_stack **stack_a);

void	simple_sort(t_stack **stack_a)
{
	int		high_index;
	// TODO: Remove this check (is sorted)
	// If sorted, just get out.
	// if (is_stack_sorted(*stack_a))
	// 	return ;
	high_index = find_highest_index(*stack_a);
	// 3 is the number when call Simple sort (1, 2, 3)
	if ((*stack_a)->index == high_index) //(3,2,1). Highest first
		rotate_a(stack_a);
	else if ((*stack_a)->next->index == high_index) //(1,3,2)
		r_rotate_a(stack_a);
	if ((*stack_a)->index > (*stack_a)->next->index)
		swap_a(stack_a);
}

void	core_sort_stack(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	// Send all integers to Stack B, but 3
	push_all_but_three(stack_a, stack_b, stack_size);

	// Sort the 3 items in A
	simple_sort(stack_a);

	while (*stack_b)
	{
		handler_target_position(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		exec_cheapest_move(stack_a, stack_b);
	}
	if (!is_stack_sorted (*stack_a))
		shift_stack(stack_a);
}

/**
 * @brief
 *
 * @param stack_a
 */
static void	shift_stack(t_stack **stack_a)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = get_stack_size(*stack_a);
	lowest_pos = get_lowest_index_position(stack_a);
	if (lowest_pos > stack_size / 2)
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
