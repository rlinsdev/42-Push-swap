/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 09:05:17 by rlins             #+#    #+#             */
/*   Updated: 2022/10/14 17:12:53 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	push_all_but_three(t_stack **stack_a, t_stack **stack_b, int stack_size);
static void	shift_stack(t_stack **stack_a);
static void	get_cost(t_stack **stack_a, t_stack **stack_b);
static int	nb_abs(int nb);
static void	do_move(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b);
static void	do_rev_rotate_both(t_stack **stack_a, t_stack **stack_b, int *cost_a, int *cost_b);
static void	do_rotate_both(t_stack **stack_a, t_stack **stack_b, int *cost_a, int *cost_b);
static void	do_cheapest_move(t_stack **stack_a, t_stack **stack_b);
static void	do_rotate_b(t_stack **stack_b, int *cost);
static void	do_rotate_a(t_stack **stack_a, int *cost);
static int	get_lowest_index_position(t_stack **stack);
static int	find_highest_index(t_stack *stack);

void	simple_sort(t_stack **stack_a)
{
	int		highest;
	// If sorted, just get out.
	if (is_stack_sorted(*stack_a))
		return ;
	highest = find_highest_index(*stack_a);
	// 2 is the number when call Simple sort (0, 1, 2)
	if ((*stack_a)->index == highest)
		// do_ra(stack_a);
		rotate_a(stack_a);
	else if ((*stack_a)->next->index == highest)
		// do_rra(stack_a);
		r_rotate_a(*stack_a);
	if ((*stack_a)->index > (*stack_a)->next->index)
		// do_sa(*stack_a);
		swap_a(*stack_a);
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


/**
 * @brief Get the cost object
 *
 * @param stack_a
 * @param stack_b
 */
static void	get_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	size_a = get_stack_size(tmp_a);
	size_b = get_stack_size(tmp_b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->pos;
		if (tmp_b->pos > size_b / 2)
			tmp_b->cost_b = (size_b - tmp_b->pos) * -1;
		tmp_b->cost_a = tmp_b->tar_pos;
		if (tmp_b->tar_pos > size_a / 2)
			tmp_b->cost_a = (size_a - tmp_b->tar_pos) * -1;
		tmp_b = tmp_b->next;
	}
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
// Add na classe R_rotate
static void	do_rev_rotate_both(t_stack **stack_a, t_stack **stack_b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		// do_rrr(stack_a, stack_b);
		rr_rotate(*stack_a, *stack_b);
		// do_rrr(stack_a, stack_b);
	}
}

// Add na Classe rotate
static void	do_rotate_both(t_stack **stack_a, t_stack **stack_b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		// do_rr(a, b);
		rotate_rotate(stack_a, stack_b);
	}
}

static void	do_rotate_a(t_stack **stack_a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			// do_ra(stack_a);
			rotate_a(stack_a);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			// do_rra(stack_a);
			r_rotate_a(*stack_a);
			(*cost)++;
		}
	}
}


static void	do_rotate_b(t_stack **stack_b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			rotate_b(stack_b);
			// do_rb(stack_b);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			r_rotate_b(*stack_b);
			// do_rrb(stack_b);
			(*cost)++;
		}
	}
}

// Add in class Position
static int	get_lowest_index_position(t_stack **stack)
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
	return (lowest_pos - 1); // TODO: Fix moment. Revisit.
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
			r_rotate_a(*stack_a);
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
		// TODO: Debugar aqui dentro
		if ((*stack_a)->index <= stack_size / 2)
		{
			push_b(stack_a, stack_b);
			pushed++;
			printf("StackA: ");
			test_print_list(*stack_a);
			printf("StackB: ");
			test_print_list(*stack_b);
		}
		else
		{
			// TODO: Debugar aqui dentro
			rotate_a(stack_a);
			printf("StackA: ");
			test_print_list(*stack_a);
			printf("StackB: ");
			test_print_list(*stack_b);
		}
		i++;
	}
	// 2 to 6 items in stack
	while (stack_size - pushed > 3)
	{
		push_b(stack_a, stack_b);
		pushed++;
		// printf("StackA: ");
		// test_print_list(*stack_a);
		// printf("StackB: ");
		// test_print_list(*stack_b);
	}
}
