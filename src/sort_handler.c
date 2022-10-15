/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 09:05:17 by rlins             #+#    #+#             */
/*   Updated: 2022/10/15 15:16:14 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	shift_stack(t_stack **stack_a);
static int	nb_abs(int nb);
static void	do_move(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b);

static void	do_cheapest_move(t_stack **stack_a, t_stack **stack_b);
static int	find_highest_index(t_stack *stack);

void	simple_sort(t_stack **stack_a)
{
	int		high_index;
	// TODO: Remove this check (is sorted)
	// If sorted, just get out.
	if (is_stack_sorted(*stack_a))
		return ;
	high_index = find_highest_index(*stack_a);
	// 2 is the number when call Simple sort (0, 1, 2)
	if ((*stack_a)->index == high_index)
		// do_ra(stack_a);
		rotate_a(stack_a);
	else if ((*stack_a)->next->index == high_index)
		// do_rra(stack_a);
		r_rotate_a(stack_a);
	if ((*stack_a)->index > (*stack_a)->next->index)
		// do_sa(*stack_a);
		swap_a(stack_a);
}

static int	find_highest_index(t_stack *stack)
{
	int		index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
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
		do_cheapest_move(stack_a, stack_b);
	}
	if (!is_stack_sorted (*stack_a))
		shift_stack(stack_a);
}

/**
 * @brief
 *
 * @param stack_a
 * @param stack_b
 */
static void	do_cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	tmp = *stack_b;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (nb_abs(tmp->cost_a) + nb_abs(tmp->cost_b) < nb_abs(cheapest))
		{
			cheapest = nb_abs(tmp->cost_b) + nb_abs(tmp->cost_a);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	do_move(stack_a, stack_b, cost_a, cost_b);
}




static int	nb_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

static void	do_move(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		do_rev_rotate_both(stack_a, stack_b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		do_rotate_both(stack_a, stack_b, &cost_a, &cost_b);
	do_rotate_a(stack_a, &cost_a);
	do_rotate_b(stack_b, &cost_b);
	push_a(stack_a, stack_b);
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
			// do_rra(stack_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			rotate_a(stack_a);
			// do_ra(stack_a);
			lowest_pos--;
		}
	}
}
