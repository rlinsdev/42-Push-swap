/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rot_aux.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:11:46 by rlins             #+#    #+#             */
/*   Updated: 2022/10/18 07:15:23 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	aux_rev_rotate_both(t_stack **stack_a, t_stack **stack_b, int *cost_a,
						int *cost_b)
{
	// Just when both have negative cost, then we will reverse rotate both
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		rr_rotate(stack_a, stack_b);
	}
}

void	aux_rotate_both(t_stack **stack_a, t_stack **stack_b, int *cost_a,
					int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rotate_rotate(stack_a, stack_b);
	}
}

void	aux_rotate_a(t_stack **stack_a, int *cost)
{
	// If exist any cost, rotate A until let in head the correct value
	while (*cost)
	{
		if (*cost > 0)
		{
			rotate_a(stack_a);
			(*cost)--;
		}
		// If cost is negative, Reverse rotate
		else if (*cost < 0)
		{
			r_rotate_a(stack_a);
			(*cost)++;
		}
	}
}

void	aux_rotate_b(t_stack **stack_b, int *cost)
{
	// If exist any cost, rotate B until let in head the correct value
	while (*cost)
	{
		if (*cost > 0)
		{
			rotate_b(stack_b);
			(*cost)--;
		}
		// If cost is negative, Reverse rotate
		else if (*cost < 0)
		{
			r_rotate_b(stack_b);
			(*cost)++;
		}
	}
}