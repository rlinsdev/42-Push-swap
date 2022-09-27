/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   samp_LinkedList.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 21:16:55 by rlins             #+#    #+#             */
/*   Updated: 2022/09/27 07:37:15 by rlins            ###   ########.fr       */
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

node_t *insert_at_head(node_t **head, node_t *node_to_insert)
{
	node_to_insert->next = *head;
	*head = node_to_insert;
	return (node_to_insert);
}

node_t *find_node(node_t *head, int value)
{
	node_t *tmp = head;
	while (tmp != NULL)
	{
		if (tmp->value == value)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void linked_list()
{
	node_t *head = NULL;
	node_t *tmp;

	for (int i = 0; i < 5; i++)
	{
		tmp = create_new_node(i);
		insert_at_head(&head, tmp);
		// tmp->next = head;
		// head = tmp;
	}

	tmp = find_node(head, 3);
	printf("Found the item: %d\n", tmp->value);

	print_list(head);
	free(tmp);

}
