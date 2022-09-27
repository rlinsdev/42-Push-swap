/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   samp_LinkedList.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 21:16:55 by rlins             #+#    #+#             */
/*   Updated: 2022/09/27 07:09:18 by rlins            ###   ########.fr       */
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

node_t *create_new_node(int value)
{
	node_t *result = malloc(sizeof(node_t));
	result->value = value;
	result->next = NULL;
	return result;
}

void linked_list()
{
	node_t *head;
	node_t *tmp;

	tmp = create_new_node(32);
	head = tmp;
	// free(tmp);
	tmp = create_new_node(8);
	head = tmp;
	// free(tmp);
	tmp = create_new_node(34);
	head = tmp;

	print_list(head);
	free(tmp);

}
