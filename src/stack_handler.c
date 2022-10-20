/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:21:59 by rlins             #+#    #+#             */
/*   Updated: 2022/10/20 09:48:56 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static t_stack	*init_stack(int value);
static void		link_stack_to_tail(t_stack **stack, t_stack *new);

t_stack	*array_to_stack(char **argv, int argc)
{
	t_stack		*stack_a;
	long long	value;
	int			i;

	i = 1;
	value = 0;
	stack_a = NULL;
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		if (value > INT_MAX || value < INT_MIN)
			invalid_int(&stack_a);
		if (i == 1)
			stack_a = init_stack(value);
		else
			link_stack_to_tail(&stack_a, init_stack(value));
		i++;
	}
	return (stack_a);
}

/**
 * @brief Add stack to the end and link it
 * @param stack
 * @param new new stack generated. Linked list will point to here
 */
static void	link_stack_to_tail(t_stack **stack, t_stack *new)
{
	t_stack	*last_stack;

	last_stack = get_last_stack(*stack);
	last_stack->next = new;
}

/**
 * @brief Initialize the stack and update value
 * @param value int value
 * @return t_stack* stack initialized
 */
static t_stack	*init_stack(int value)
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof * new_stack);
	if (!new_stack)
		return (NULL);
	new_stack->value = value;
	new_stack->index = 0;
	new_stack->pos = -1;
	new_stack->tar_pos = -1;
	new_stack->cost_a = -1;
	new_stack->cost_b = -1;
	new_stack->next = NULL;
	return (new_stack);
}

void	init_stack_index(t_stack *stack_a, int stack_size)
{
	int		value;
	t_stack	*ptr_aux;
	t_stack	*highest_stack;

	while (stack_size > 0)
	{
		ptr_aux = stack_a;
		value = INT_MIN;
		highest_stack = NULL;
		while (ptr_aux)
		{
			if (ptr_aux->value > value && ptr_aux->index == 0)
			{
				value = ptr_aux->value;
				highest_stack = ptr_aux;
				ptr_aux = stack_a;
			}
			else
			{
				ptr_aux = ptr_aux->next;
			}
		}
		if (highest_stack != NULL)
			highest_stack->index = stack_size;
		stack_size--;
	}
}
