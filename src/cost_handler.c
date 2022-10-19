/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:01:28 by rlins             #+#    #+#             */
/*   Updated: 2022/10/19 11:03:24 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	ft_abs_nb(int nb);
static void	exec_move(t_stack **stack_a, t_stack **stack_b, int cost_a,
				int cost_b);

void	get_cost(t_stack **stack_a, t_stack **stack_b)
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
		// As pattern, cost of B will be a position of B.
		tmp_b->cost_b = tmp_b->pos;
		/* Will change this cost, when we check that will be cheapest
		 * reverse rotate (negative to indicate reverse rotate)*/
		if (tmp_b->pos > (size_b / 2))
			tmp_b->cost_b = (size_b - tmp_b->pos) * -1;
		// As pattern, cost of A will be a target position of A.
		tmp_b->cost_a = tmp_b->tar_pos;
		if (tmp_b->tar_pos > (size_a / 2))
			tmp_b->cost_a = (size_a - tmp_b->tar_pos) * -1;
		// Go to next
		tmp_b = tmp_b->next;
	}
	ft_print_list(*stack_b, 'B');
}

void	exec_cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	tmp = *stack_b;
	cheapest = INT_MAX;
	while (tmp)
	{
		/* Verify the cost to execute a Push A. The signal and the number will
		 * be important. But to now known many, the number must be absolute */
		if (ft_abs_nb(tmp->cost_a) + ft_abs_nb(tmp->cost_b)
			< ft_abs_nb(cheapest))
		{
			cheapest = ft_abs_nb(tmp->cost_b) + ft_abs_nb(tmp->cost_a);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	exec_move(stack_a, stack_b, cost_a, cost_b);
}

/** [Passed]
 * @brief Chooses which move to do, to get the B stack element to the correct
 * position in stack A.
 * If cost_a and cost_b are the same signal, RRR or RR will be executed.
 * @param stack_a Stack with integers
 * @param stack_b Auxiliary stack
 * @param cost_a how many steps to rotate Stack A. (-): RR. (+): R
 * @param cost_b how many steps to rotate Stack B. (-): RR. (+): R
 */
static void	exec_move(t_stack **stack_a, t_stack **stack_b, int cost_a,
				int cost_b)
{
	//printf("A:\n");
	ft_print_list(*stack_a, 'A');
	// printf("B:\n");
	ft_print_list(*stack_b, 'B');
	// Both negative? RRR
	if (cost_a < 0 && cost_b < 0)
		aux_rev_rotate_both(stack_a, stack_b, &cost_a, &cost_b);
	// Both positive? RR
	else if (cost_a > 0 && cost_b > 0)
		aux_rotate_both(stack_a, stack_b, &cost_a, &cost_b);
	// Rotate A.
	aux_rotate_a(stack_a, &cost_a);
	// printf("A:\n");
	ft_print_list(*stack_a, 'A');
	aux_rotate_b(stack_b, &cost_b);
	// printf("B:\n");
	ft_print_list(*stack_b, 'B');
	// Push item of B to A
	push_a(stack_a, stack_b);
}

/** [Passed]
 * @brief Absolute number. Return the positive number. Itś necessary to know
 * how many interactions will be necessary. The signal will be used in future.
 * @param nb Integer number
 * @return int Positive number
 */
static int	ft_abs_nb(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}
