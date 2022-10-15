/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:29:16 by rlins             #+#    #+#             */
/*   Updated: 2022/10/15 15:32:20 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	get_stack_size(t_stack	*stack)
{
	int	i;

	i = 0;
	// TODO: Remove this condition
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

t_stack	*get_stack_before_tail(t_stack *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

// TODO: NAO DARIA CERTO JA PEGAR PELO INDEX AQUI?
/**
 * @brief will return the last element
 * @param stack
 * @return t_stack* Pointer to last stack
 */
t_stack	*get_stack_tail(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}
