/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:23:43 by rlins             #+#    #+#             */
/*   Updated: 2022/10/15 15:04:56 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

// get_target
static int	update_target_position(t_stack **stack_a, int stack_b_index, int target_index, int target_pos);

void	handler_target_position(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_stack_b;
	int		target_pos;

	tmp_stack_b = *stack_b;
	// Initialize position on stack_A
	update_position(stack_a);
	// Initialize position on stack_B
	update_position(stack_b);
	target_pos = 0;
	while (tmp_stack_b)
	{
		// Will get the target position to B
		target_pos = update_target_position(stack_a, tmp_stack_b->index, INT_MAX, target_pos);

		tmp_stack_b->tar_pos = target_pos;
		tmp_stack_b = tmp_stack_b->next;
	}
}

/**
 * @brief Will get a target position to stack B
 *
 * @param stack_a
 * @param stack_b_index
 * @param target_pos
 * @return int
 */
static int	update_target_position(t_stack **stack_a, int stack_b_index, int target_index, int target_pos)
{
	t_stack	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->index > stack_b_index && tmp->index < target_index)
		{
			//TODO: Quando entrará aqui?
			target_index = tmp->index;
			target_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	// TODO: Remove this condition. Will never happen
	if (target_index != INT_MAX)
		return (target_pos);
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->index < target_index)
		{
			target_index = tmp->index;
			target_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	// return (target_pos - 1); // TODO: Fix moment. Revisit.
	return (target_pos); // TODO: Fix moment. Revisit.
}

/**
 * @brief Update position will simple loop though all elements and put a number * in position. This must be update when the position in pill change. Will
 * initialize and update position of stack
 *		value:		[1]	[3]	[4]
 *		index:		[1]	[0]	[2]
 *		position:	[0]	[1] [2]
 * @param stack
 */
void	update_position(t_stack **stack)
{
	t_stack	*stack_tmp;
	int		i;

	stack_tmp = *stack;
	i = 0;
	while (stack_tmp)
	{
		// Set a new position
		stack_tmp->pos = i;
		// Update the Stack to the next
		stack_tmp = stack_tmp->next;
		i++;
	}
}

// TODO: Index or positon. Get Better name.
int	get_lowest_index_position(t_stack **stack)
{
	t_stack	*tmp;
	int		lowest_index;
	int		lowest_pos;

	tmp = *stack;
	lowest_index = INT_MAX;
	update_position(stack);
	lowest_pos = tmp->pos;
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			lowest_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	// return (lowest_pos - 1); // TODO: Fix moment. Revisit.
	return (lowest_pos); // TODO: Fix moment. Revisit.
}
