/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 09:05:17 by rlins             #+#    #+#             */
/*   Updated: 2022/10/18 07:46:34 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	set_head_stack(t_stack **stack_a);

void	simple_sort(t_stack **stack_a)
{
	int		high_index;

	high_index = find_highest_index(*stack_a);
	// 3 is the number when call Simple sort (1, 2, 3)
	// If the index of the first number is highest, do ra,
	if ((*stack_a)->index == high_index) //(3,2,1). Highest first
		rotate_a(stack_a);
	// Otherwise, if the index of the second number is highest, do rra,
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
	// We will mess the head of stack to order all numbers. Check if is all sort
	if (!is_stack_sorted(*stack_a))
		set_head_stack(stack_a);
}

/** [passed]
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
	// Verify if is better rotate or reverse rotate
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
			// Just rotate to fix the order
			rotate_a(stack_a);
			lowest_pos--;
		}
	}
}
