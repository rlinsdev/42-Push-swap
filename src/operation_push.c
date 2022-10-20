/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 07:04:06 by rlins             #+#    #+#             */
/*   Updated: 2022/10/20 09:47:02 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	push(t_stack **stack_orig, t_stack **stack_dest);

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}

/**
 * @brief Push/send the top element of a origin stack to the dest stack
 * @param stack_orig Stack with integers
 * @param stack_dest Auxiliary stack
 */
static void	push(t_stack **stack_orig, t_stack **stack_dest)
{
	t_stack	*tmp;

	if (*stack_orig == NULL)
		return ;
	tmp = (*stack_orig)->next;
	(*stack_orig)->next = *stack_dest;
	*stack_dest = *stack_orig;
	*stack_orig = tmp;
}

void	push_all_but_three(t_stack **stack_a, t_stack **stack_b, int
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
		}
		else
		{
			rotate_a(stack_a);
		}
		i++;
	}
	while ((stack_size - pushed) > 3)
	{
		push_b(stack_a, stack_b);
		pushed++;
	}
}
