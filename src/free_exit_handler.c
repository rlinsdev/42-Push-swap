/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 09:14:39 by rlins             #+#    #+#             */
/*   Updated: 2022/10/19 08:45:35 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	free_stack_linked(t_stack **stack)
{
	t_stack	*aux;

	while (*stack)
	{
		aux = (*stack)->next;
		free(*stack);
		*stack = aux;
	}
	*stack = NULL;
}

void	invalid_int(t_stack **stack_a)
{
	free_stack_linked(stack_a);
	ft_printf("Error\n");
	exit (1);
}
