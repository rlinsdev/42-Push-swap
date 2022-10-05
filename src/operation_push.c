/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 07:04:06 by rlins             #+#    #+#             */
/*   Updated: 2022/10/05 07:50:58 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static t_node	*pop_node(t_node **stack);
static void	push_node(t_node *pop, t_node **stack);

// TODO
void	push_a(t_node *node_a, t_node *node_b)
{
	t_node	*pop;

	// pop = pop_node(&stack->b);
	// push_node(pop, &stack->a);
	// stack->nodes_on_a += 1;
	// stack->nodes_on_b -= 1;
	write(1, "pa\n", 3);
}

// TODO
void	push_b(t_node *node_a, t_node *node_b)
{

}


static t_node	*pop_node(t_node **stack)
{
	t_node	*pop;
	// t_node	*tail;
	// t_node	*head;

	// head = *stack;
	// if (!head)
	// 	return (NULL);
	// pop = head;
	// if (head->next != head)
	// {
	// 	tail = head->previous;
	// 	head = head->next;
	// 	connect_nodes(head, tail);
	// }
	// else
	// 	head = NULL;
	// pop->previous = NULL;
	// pop->next = NULL;
	// *stack = head;
	return (pop);
}

static void	push_node(t_node *pop, t_node **stack)
{
	// t_node	*tail;
	// t_node	*head;

	// head = *stack;
	// if (!head)
	// 	connect_nodes(pop, pop);
	// else
	// {
	// 	tail = head->previous;
	// 	pop->next = head;
	// 	head->previous = pop;
	// 	pop->previous = tail;
	// 	tail->next = pop;
	// }
	// *stack = pop;
}
