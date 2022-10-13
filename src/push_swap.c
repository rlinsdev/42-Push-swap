/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 07:17:21 by rlins             #+#    #+#             */
/*   Updated: 2022/10/13 08:35:55 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	best_sort_alg(t_stack **stack_a, t_stack **stack_b, int stack_size);
static int	is_stack_sorted(t_stack *stack_a);

int	start(int argc, char **argv)
{
	// int sortList[] = {50, 40, 10};

	// // With this it's possible discovery the size of array!
	// int nbr_itens = sizeof(sortList) / sizeof(sortList[0]);

	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	// TODO: Put some message of invalid arguments?
	if (argc >= 2)
	{
		if (invalid_input(argv, argc))
		{
			ft_printf("Invalid arguments\n");
			exit (1);
		}
		// pass Array to Stack
		stack_a = array_to_stack(argv, argc);
		// get Stack size
		stack_size = get_stack_size(stack_a);
		init_stack_index(stack_a, stack_size);
		best_sort_alg(&stack_a, &stack_b, stack_size);


		free_stack_linked(&stack_a);
	}
	return (0);
}

/**
 * @brief Responsible to find the best sort method. Just 1 method is not able to
 * sort with just a few movements.
 * @param stack_a Pile with all numbers
 * @param stack_b Pile to aux to sort the numbers
 * @param stack_size size of pile numbers
 */
static void	best_sort_alg(t_stack **stack_a, t_stack **stack_b, int stack_size)
{

}

/**
 * @brief Verify if the stack is sorted. Will help us to choose the type of
 * method choose to sort the pile
 * @param stack_a
 * @return (1) if sorted. (0) if mess pile
 */
static int	is_stack_sorted(t_stack *stack_a)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->value > stack_a->next->value)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}
