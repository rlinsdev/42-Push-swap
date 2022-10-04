/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 07:17:02 by rlins             #+#    #+#             */
/*   Updated: 2022/10/04 19:38:48 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
// # include <unistd.h> //Execve, fork, dup, dump2, write, pipe
 # include <stdio.h> // Printf - Remover
// # include <string.h> // strerror
// # include <fcntl.h> // To Open a file
// # include <sys/wait.h> // waitpid
# include <stdlib.h> // malloc

/* Consts */
// # define SA "sa"
// # define SS "ss"
// # define SB "sb"
// # define PA "pa"
// # define PB "pb"
// # define RA "ra"
// # define RB "rb"
// # define RR "rr"
// # define RRA "rra"
// # define RRB "rrb"
// # define RRR "rrr"

// Linked List
typedef struct s_node
{
	int value;
	struct s_node *next;
}	t_node;


/**
 * @brief First method in project.
 * @param argc Arguments count
 * @param argv Arguments Vector
 * @return int
 */
int	start(int argc, char **argv);

/**
 * @brief sa (swap a): Swap the first 2 elements at the top of stack a.
 * Do nothing if there is only one or no elements.
 * @param node_a
 * @param node_b
 */
void	swap_a(t_node *node_a);

void	swap_b(t_node *node_b);
void	swap_swap (t_node *node_a, t_node *node_b);

/**
 * @brief pa (push a): Take the first element at the top of b and put it at the * top of a. Do nothing if b is empty.
 * @param node_a
 * @param node_b
 */
void	push_a (t_node **node_a, t_node **node_b);

/**
 * @brief (push b): Take the first element at the top of a and put it at the
 * top of b. Do nothing if a is empty.
 * @param node_a
 * @param node_b
 */
void	push_b (t_node **node_a, t_node **node_b);

/**
 * @brief ra (rotate a): Shift up all elements of stack a by 1.
 * The first element becomes the last one
 * @param node_a
 * @param node_b
 */
void	rotate_a (t_node *node_a);
void	rotate_b (t_node *node_b);
void	rotate_rotate (t_node *node_a, t_node *node_b);

/**
 * @brief rra (reverse rotate a): Shift down all elements of stack a by 1.
 * The last element becomes the first one.
 * @param node_a
 * @param node_b
 */
void	reverse_rotate_a (t_node **node_a, t_node **node_b);
void	reverse_rotate_b (t_node **node_a, t_node **node_b);
void	reverse_rotate_rotate (t_node **node_a, t_node **node_b);

// int quick();
// int merge_main();
// void linked_list();
// void	radixsort();
// void	radixsort2();
// void radixsort3();

#endif
