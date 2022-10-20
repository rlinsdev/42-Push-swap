/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:23:43 by rlins             #+#    #+#             */
/*   Updated: 2022/10/20 09:51:23 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	update_target_position(t_stack **stack_a, int stack_b_index,
				int target_index, int target_pos);

void	handler_target_position(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_stack_b;
	int		target_pos;

	tmp_stack_b = *stack_b;
	update_position(stack_a);
	update_position(stack_b);
	target_pos = 0;
	while (tmp_stack_b)
	{
		target_pos = update_target_position(stack_a, tmp_stack_b->index,
				INT_MAX, target_pos);
		tmp_stack_b->tar_pos = target_pos;
		tmp_stack_b = tmp_stack_b->next;
	}
}

/**
 * @brief
 * Practically will verify the index coming in B, and calculate where to put
 * in A. Compare must be between Index of A, with index of B.
 * Handle the best Target position to put the element B in the stack A
 * First, verify if the index in B is small then B, and return Target Position
 * In the first execution, frequently, the first element will be put in the
 * first place in A (position 0).
 * @param stack_a Stack A to check and verify all elements
 * @param stack_b_index Index in Stack B coming to compare (loop).
 * @param target_index coming INT_MAX, but will change inside the loop
 * @param target_pos
 * @return int
 */
static int	update_target_position(t_stack **stack_a, int stack_b_index,
				int target_index, int target_pos)
{
	t_stack	*tmp_a;

	tmp_a = *stack_a;
	while (tmp_a)
	{
		if (tmp_a->index > stack_b_index && tmp_a->index < target_index)
		{
			target_index = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	if (target_index != INT_MAX)
		return (target_pos);
	tmp_a = *stack_a;
	while (tmp_a)
	{
		if (tmp_a->index < target_index)
		{
			target_index = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	return (target_pos);
}

void	update_position(t_stack **stack)
{
	t_stack	*stack_tmp;
	int		i;

	stack_tmp = *stack;
	i = 0;
	while (stack_tmp)
	{
		stack_tmp->pos = i;
		stack_tmp = stack_tmp->next;
		i++;
	}
}

int	get_position_lower_element(t_stack **stack)
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
	return (lowest_pos);
}
