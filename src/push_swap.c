/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 07:17:21 by rlins             #+#    #+#             */
/*   Updated: 2022/10/17 21:27:12 by rlins            ###   ########.fr       */
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
			ft_printf("Invalid arguments\n");
			exit (1);
		}
		// Initialize Stack_b
		stack_b = NULL;
		// pass Array to Stack
		stack_a = array_to_stack(argv, argc);
		// TODO: Remove:
		ft_printf("Mess pill list:\n");
		ft_print_list(stack_a);
		// get Stack size
		stack_size = get_stack_size(stack_a);
		init_stack_index(stack_a, stack_size);
		ft_printf("Index added:\n");
		ft_print_list(stack_a);
		best_sort_alg(&stack_a, &stack_b, stack_size);
		// TODO: Remove:
		ft_printf("Sort list:\n");
		ft_print_list(stack_a);
		// Free Stack
		free_stack_linked(&stack_a);
	}
	return (0);
}

void	ft_print_list(t_stack *stack)
{
	t_stack	*temp;

	// Value
	temp = stack;
	printf("Value: ");
	while (temp != NULL)
	{
		printf(" %d 	", temp->value);
		temp = temp->next;
	}
	printf("\n");

	// index
	temp = stack;
	printf("Index: ");
	while (temp != NULL)
	{
		printf("[%d]	", temp->index);
		temp = temp->next;
	}
	printf("\n");

	// position
	temp = stack;
	printf("Posit: ");
	while (temp != NULL)
	{
		printf("<%d>	", temp->pos);
		temp = temp->next;
	}
	printf("\n");

	// Target Position
	temp = stack;
	printf("Tar P: ");
	while (temp != NULL)
	{
		printf("(%d)	", temp->pos);
		temp = temp->next;
	}
	printf("\n");

	// Cost A
	temp = stack;
	printf("Cos A: ");
	while (temp != NULL)
	{
		printf("|%d|	", temp->cost_a);
		temp = temp->next;
	}
	printf("\n");

		// Cost B
	temp = stack;
	printf("Cos B: ");
	while (temp != NULL)
	{
		printf("|%d|	", temp->cost_b);
		temp = temp->next;
	}
	printf("\n");
}

/** [Passed]
 * @brief Responsible to find the best sort method. Just 1 method is not able to
 * sort with just a few movements. Mandatory in project: Sort by minimum OP
 * possible
 * @param stack_a Pile with all numbers (Messed)
 * @param stack_b Pile to aux to sort the numbers
 * @param stack_size size of pile numbers
 */
static void	best_sort_alg(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	// Just Return sorted list
	if (is_stack_sorted(*stack_a))
		return ;
	// if not sorted, just swap 1 to other, in same stack
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
