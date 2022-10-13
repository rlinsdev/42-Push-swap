/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 09:05:17 by rlins             #+#    #+#             */
/*   Updated: 2022/10/13 14:08:15 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	push_all_but_three(t_stack **stack_a, t_stack **stack_b, int stack_size);

void	simple_sort(t_stack **stack_a)
{
	// If sorted, just get out.
	if (is_stack_sorted(*stack_a))
		return ;
	// 2 is the number when call Simple sort (0, 1, 2)
	else if ((*stack_a)->index == 2)
		// do_ra(stack_a);
		rotate_a(stack_a);
	else if ((*stack_a)->next->index == 2)
		// do_rra(stack_a);
		r_rotate_a(*stack_a);
	if ((*stack_a)->index > (*stack_a)->next->index)
		// do_sa(*stack_a);
		swap_a(*stack_a);
}

void	core_sort_stack(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	// Send all integers to Stack B, but 3
	push_all_but_three(stack_a, stack_b, stack_size);

	// Sort the 3 items in A
	simple_sort(stack_a);

}

/**
 * @brief Send all integers to B, but stay with 3 in stack A.
 *
 * @param stack_a
 * @param stack_b
 */
static void	push_all_but_three(t_stack **stack_a, t_stack **stack_b, int
stack_size)
{
	int	pushed;
	int	i;

	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			push_b(stack_a, stack_b);
			pushed++;
			// test_print_list(stack_a);
			// test_print_list(stack_b);
		}
		else
		{
			rotate_a(stack_a);
			// test_print_list(stack_a);
			// test_print_list(stack_b);
		}
		i++;
	}
	// 2 to 6 items in stack
	while (stack_size - pushed > 3)
	{
		push_b(stack_a, stack_b);
		pushed++;
		test_print_list(*stack_a);
		test_print_list(*stack_b);
	}
}
