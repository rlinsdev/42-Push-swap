/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:33:52 by rlins             #+#    #+#             */
/*   Updated: 2022/10/04 20:41:00 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	rotate_node(t_node *node);

// TODO
void	rotate_a(t_node *node_a)
{
	rotate_node(node_a);
	write(1, "ra\n", 3);
}

void	rotate_b(t_node *node_b)
{
	rotate_node(node_b);
	write(1, "rb\n", 3);
}

void	rotate_rotate(t_node *node_a, t_node *node_b)
{
	rotate_node(node_a);
	rotate_node(node_b);
	write(1, "rr\n", 3);
}

static void	rotate_node(t_node *node)
{
	t_node	*aux;

	aux = node;
	if (aux == NULL)
		return ;
	aux = aux->next;
	node = aux;
}
