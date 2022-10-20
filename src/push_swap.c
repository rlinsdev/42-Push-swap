/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 07:17:21 by rlins             #+#    #+#             */
/*   Updated: 2022/10/20 09:48:11 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	best_sort_alg(t_stack **stack_a, t_stack **stack_b, int stack_size);

int	start(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	if (argc >= 2)
	{
		if (invalid_input(argv, argc))
		{
			ft_printf("Error\n");
			exit (1);
		}
		stack_b = NULL;
		stack_a = array_to_stack(argv, argc);
		stack_size = get_stack_size(stack_a);
		init_stack_index(stack_a, stack_size);
		best_sort_alg(&stack_a, &stack_b, stack_size);
		free_stack_linked(&stack_a);
	}
	return (0);
}

/**
 * @brief Responsible to find the best sort method. Just 1 method is not able to
 * sort with just a few movements. Mandatory in project: Sort by minimum OP
 * possible
 * @param stack_a Pile with all numbers (Messed)
 * @param stack_b Pile to aux to sort the numbers
 * @param stack_size size of pile numbers
 */
static void	best_sort_alg(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (is_stack_sorted(*stack_a))
		return ;
	else if (stack_size == 2)
		swap_a(stack_a);
	else if (stack_size == 3)
		simple_sort(stack_a);
	else
		core_sort_stack(stack_a, stack_b, stack_size);
}

int	is_stack_sorted(t_stack *stack_a)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->value > stack_a->next->value)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}
