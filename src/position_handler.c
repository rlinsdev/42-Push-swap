/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:23:43 by rlins             #+#    #+#             */
/*   Updated: 2022/10/19 11:38:22 by rlins            ###   ########.fr       */
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
	// Initialize position on stack_A
	update_position(stack_a);
	ft_print_list(*stack_a, 'A');
	// Initialize position on stack_B
	update_position(stack_b);
	ft_print_list(*stack_b, 'B');
	target_pos = 0;
	while (tmp_stack_b)
	{
		// Will get the target position to B
		target_pos = update_target_position(stack_a, tmp_stack_b->index,
				INT_MAX, target_pos);
		// Update Target Position
		tmp_stack_b->tar_pos = target_pos;
		// Go to the next
		tmp_stack_b = tmp_stack_b->next;
	}
	ft_print_list(*stack_b, 'B');
}

/** [Todo comment]
 * @brief
 *	Picks the best target position in stack A for the given index of
 *	an element in stack B. First checks if the index of the B element can
 *	be placed somewhere in between elements in stack A, by checking whether
 *	there is an element in stack A with a bigger index. If not, it finds the
 *	element with the smallest index in A and assigns that as the target pos
 *	--- Example:
 *		tar_pos starts at INT_MAX
 *		B index: 3
 *		A contains indexes: 9 4 2 1 0
 *		9 > 3 && 9 < INT_MAX 	: targ_pos updated to 9
 *		4 > 3 && 4 < 9 			: targ pos updated to 4
 *		2 < 3 && 2 < 4			: no update!
 *	So tar_pos needs to be the position of index 4, since it is
 *	the closest index.
 *	--- Example:
 *		tar_pos starts at INT_MAX
 *		B index: 20
 *		A contains indexes: 16 4 3
 *		16 < 20					: no update! target_pos = INT_MAX
 *		4  < 20					: no update! target_pos = INT_MAX
 *		3  < 20					: no update! target_pos = INT_MAX
 *	... tar_pos stays at INT MAX, need to switch strategies.
 *		16 < 20					: target_pos updated to 20
 *		4  < 20					: target_pos updated to 4
 *		3  < 20					: target_pos updated to 3
 *	So tar_pos needs to be the position of index 3, since that is
 *	the "end" of the stack.
 * @param stack_a
 * @param stack_b_index
 * @param target_index
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
		// Just get inside when index of A will be smaller than index o B
		if (tmp_a->index > stack_b_index && tmp_a->index < target_index)
		{
			//TODO: Debug inside
			target_index = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	// if Diff, means that have change. Just return the Target Position
	if (target_index != INT_MAX)
		return (target_pos);
	tmp_a = *stack_a;
	// Loop through A again
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
		// Set a new position
		stack_tmp->pos = i;
		// Update the Stack to the next
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
	// With push from B, position is wrong. Fix it.
	update_position(stack);
	ft_print_list(*stack, 'A');
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
