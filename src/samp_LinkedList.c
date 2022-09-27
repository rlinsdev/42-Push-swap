/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   samp_LinkedList.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 21:16:55 by rlins             #+#    #+#             */
/*   Updated: 2022/09/26 22:23:33 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

struct node {
	int	value;
	struct node *next;
};
typedef struct node node_t;

void	print_list(node_t *head)
{
	node_t *temp = head;

	while (temp != NULL)
	{
		printf("%d -", temp->value);
		temp = temp->next;
	}
	printf("\n");
}

void linked_list()
{
	node_t n1, n2, n3;
	node_t *head;

	n1.value = 45;
	n2.value = 8;
	n3.value = 32;

	head = &n3;
	n3.next = &n2;
	n2.next = &n1;
	n1.next = NULL;

	print_list(head);
}
