/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 07:17:21 by rlins             #+#    #+#             */
/*   Updated: 2022/10/18 10:26:25 by rlins            ###   ########.fr       */
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
		// ft_printf("Mess pill list:\n");
		ft_print_list(stack_a, 'A');
		// get Stack size
		stack_size = get_stack_size(stack_a);
		init_stack_index(stack_a, stack_size);
		// ft_printf("Index added:\n");
		ft_print_list(stack_a, 'A');
		best_sort_alg(&stack_a, &stack_b, stack_size);
		// TODO: Remove:
		// ft_printf("Sort list:\n");
		ft_print_list(stack_a, 'A');
		// Free Stack
		free_stack_linked(&stack_a);
	}
	return (0);
}

/** [Passed]
 * @brief Aux to print a list in current state
 * @param stack Stack to evidence
 * @param action What variable to print
 */
static void ft_print_list_aux(t_stack *stack, char *action)
{
	t_stack	*temp;

	// Value
	temp = stack;
	printf("%s: ", action);
	while (temp != NULL)
	{
		if (action == "Value")
			printf("[%d]	", temp->value);
		else if (action == "Index")
			printf("[%d]	", temp->index);
		else if (action == "Posit")
			printf("[%d]	", temp->pos);
		else if (action == "Tar-P")
			printf("[%d]	", temp->tar_pos);
		else if (action == "Cos-A")
			printf("[%d]	", temp->cost_a);
		else if (action == "Cos-B")
			printf("[%d]	", temp->cost_b);

		temp = temp->next;
	}
	printf("\n");
}

void	ft_print_list(t_stack *stack, char identify)
{
	return ;
	t_stack	*temp;

	if (identify == 'A')
		printf("A:\n");
	else
		printf("B:\n");

	ft_print_list_aux(stack, "Value");
	ft_print_list_aux(stack, "Index");
	ft_print_list_aux(stack, "Posit");
	ft_print_list_aux(stack, "Tar-P");
	ft_print_list_aux(stack, "Cos-A");
	ft_print_list_aux(stack, "Cos-B");
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
