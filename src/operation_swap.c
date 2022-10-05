/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:48:07 by rlins             #+#    #+#             */
/*   Updated: 2022/10/04 19:17:11 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	swap_nodes(t_node *first, t_node *second);

// TODO
void	swap_a(t_node *node_a)
{
	swap_nodes(node_a, node_a->next);
	write(1, "sa\n", 3);
}

void	swap_b(t_node *node_b)
{
	swap_nodes(node_b, node_b->next);
	write(1, "sb\n", 3);
}

void	swap_swap (t_node *node_a, t_node *node_b)
{
	swap_nodes(node_a, node_a->next);
	swap_nodes(node_b, node_b->next);
	write(1, "ss\n", 3);
}

/**
 * @brief Will swap the nodes passed by param
 * @param first First Element
 * @param second Second Element
 */
static void	swap_nodes(t_node *first, t_node *second)
{
	int		aux;

	aux = first->value;
	first->value = second->value;
	second->value = aux;
}
