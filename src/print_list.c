/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 07:49:18 by rlins             #+#    #+#             */
/*   Updated: 2022/10/05 07:47:29 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

// TODO: Will be used?
void	print_list(t_node *head)
{
	t_node *temp = head;

	while (temp != NULL)
	{
		ft_printf("%d -", temp->value);
		temp = temp->next;
	}
	printf("\n");
}
