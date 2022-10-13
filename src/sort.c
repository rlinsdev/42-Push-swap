/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 09:05:17 by rlins             #+#    #+#             */
/*   Updated: 2022/10/13 10:34:20 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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
