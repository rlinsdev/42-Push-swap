/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:29:16 by rlins             #+#    #+#             */
/*   Updated: 2022/10/16 09:10:55 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	get_stack_size(t_stack	*stack)
{
	int	i;

	i = 0;
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

t_stack	*get_stack_tail(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack	*get_last_stack(t_stack *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

int	find_highest_index(t_stack *stack)
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
