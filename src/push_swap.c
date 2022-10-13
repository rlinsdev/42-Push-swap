/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 07:17:21 by rlins             #+#    #+#             */
/*   Updated: 2022/10/07 15:35:08 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	start(int argc, char **argv)
{
	// int sortList[] = {50, 40, 10};

	// // With this it's possible discovery the size of array!
	// int nbr_itens = sizeof(sortList) / sizeof(sortList[0]);

	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size_pile;

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
		stack_a->size = get_stack_size(stack_a);
		update_stack_index(stack_a);
		// arr = creat_arr(argc, argv);
		// ft_is_duplicated(arr, argc - 1);

		// list_a = creat_list(arr, argc - 1);
		// ft_sort(arr, argc - 1);
		// add_index(list_a, arr);
		// markup_head(list_a);
		// push_swap(list_a);
		free_stack_linked(&stack_a);
	}
	return (0);
}
