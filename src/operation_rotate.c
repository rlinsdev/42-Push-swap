/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:33:52 by rlins             #+#    #+#             */
/*   Updated: 2022/10/05 23:09:55 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	rotate_stack(t_stack *stack);

// TODO
void	rotate_a(t_stack *stack_a)
{
	rotate_stack(stack_a);
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack *stack_b)
{
	rotate_stack(stack_b);
	write(1, "rb\n", 3);
}

void	rotate_rotate(t_stack *stack_a, t_stack *stack_b)
{
	rotate_stack(stack_a);
	rotate_stack(stack_b);
	write(1, "rr\n", 3);
}

static void	rotate_stack(t_stack *stack)
{
	t_stack	*aux;

	aux = stack;
	if (aux == NULL)
		return ;
	aux = aux->next;
	stack = aux;
}
