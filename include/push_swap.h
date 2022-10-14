/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 07:17:02 by rlins             #+#    #+#             */
/*   Updated: 2022/10/14 17:09:06 by rlins            ###   ########.fr       */
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
//# include <limits.h> // MAXINT

//TODO: Rever a diferença do Index pra posição
// Linked List
typedef struct s_stack
{
	int value; // Integer value to sort
	int	index; // Essential to sort algorithm
	int	pos; // Essential to sort algorithm. (Is like the index in array)
	int tar_pos; // Target position in Stack A
	int	cost_a; // how many steps to rotate Stack A
	int	cost_b; // how many steps to rotate Stack B. TODO: Cost just exist in B????
	// int	size;
	struct s_stack *next;
}	t_stack;


/**
 * @brief First method in project.
 * @param argc Arguments count
 * @param argv Arguments Vector
 * @return int
 */
int	start(int argc, char **argv);

/**
 * @brief Verify if param is correct. Not allowed duplicate, spaces. Just number
 * @param argv Vector of args
 * @param argc Count of args
 * @return int: Input invalid (1) Input Valid (0)
 */
int	invalid_input(char **argv, int argc);

/**
 * @brief Will populate stack_a with values in array
 * @param argv Vector of args
 * @param argc Count of args
 * @return t_stack* filled
 */
t_stack	*array_to_stack(char** argv, int argc);

/**
 * @brief Get the last stack object
 * @param stack
 * @return t_stack*
 */
t_stack *get_last_stack(t_stack *stack);

/**
 * @brief How was used malloc to generate a stack object, we must free this
 * memory allocation in linked list
 * @param stack loop through all linked stacks
 */
void	free_stack_linked(t_stack **stack);


/**
 * @brief Get the stack size
 * @param stack will check through all items
 * @return int
 */
int	get_stack_size(t_stack	*stack);

/**
 * @brief Update the index in each value in stack. The index will be compared
 * with the actual value to be order.
 * This Assigned will be make from the highest to the lower.
 * @param stack_a
 * @param stack_size
 * @sample: values: [10], [5], [-9]
 * 			Index:	[0],  [1], [2]*/
void	init_stack_index(t_stack *stack_a, int stack_size);

// static void	get_position(t_stack **stack);
void	update_position(t_stack **stack);

/**
 * @brief Verify if the stack is sorted. Will help us to choose the type of
 * method choose to sort the pile
 * @param stack_a
 * @return (1) if sorted. (0) if mess pile
 */
int		is_stack_sorted(t_stack *stack_a);


/**
 * @brief When stack have just 3 items, this will bhe the best sort method
 * @param stack_a
 */
void	simple_sort(t_stack **stack_a);


/**
 * @brief Core of program. Responsible to sort more than 3 integers. Send all
 * element to B, but 3. Find current position. Calculate target position. Check
 * the cost of actions. Take action
 * @param stack_a Stack with integers
 * @param stack_b Auxiliary stack
 * @param stack_size Size of stack
 */
void	core_sort_stack(t_stack **stack_a, t_stack **stack_b, int stack_size);


/**
 * @brief
 *
 * @param stack_a Stack with integers
 * @param stack_b Auxiliary stack
 */
void	handler_target_position(t_stack **stack_a, t_stack **stack_b);

/** [OK]
 * @brief sa (swap a): Swap the first 2 elements at the top of stack a.
 * Do nothing if there is only one or no elements.
 * @param stack_a
 * @param stack_b
 */
void	swap_a(t_stack *stack_a);

void	swap_b(t_stack *stack_b);
void	swap_swap(t_stack *stack_a, t_stack *stack_b);

/**
 * @brief pa (push a): Take the first element at the top of b and put it at the * top of a. Do nothing if b is empty.
 * @param stack_a
 * @param stack_b
 */
void	push_a(t_stack **stack_a, t_stack **stack_b);

/** [OK]
 * @brief (push b): Take the first element at the top of a and put it at the
 * top of b. Do nothing if a is empty.
 * @param stack_a
 * @param stack_b
 */
void	push_b(t_stack **stack_a, t_stack **stack_b);

/** [OK]
 * @brief ra (rotate a): Shift up all elements of stack a by 1.
 * The first element becomes the last one
 * @param stack_a
 * @param stack_b
 */
void	rotate_a(t_stack **stack_a);

/**
 * @brief
 *
 * @param stack_b
 */
void	rotate_b(t_stack **stack_b);

/**
 * @brief ra (rotate a) and rb (rotate b) at the same time
 * @param stack_a Stack with integers
 * @param stack_b Auxiliary stack
 */
void	rotate_rotate(t_stack **stack_a, t_stack **stack_b);

/** [OK]
 * @brief rra (reverse rotate a): Shift down all elements of stack a by 1.
 * The last element becomes the first one.
 * @param stack_a
 */
void	r_rotate_a(t_stack *stack_a);

/** [OK]
 * @brief
 *
 * @param stack_b
 */
void	r_rotate_b(t_stack *stack_b);

/** [OK]
 * @brief
 *
 * @param stack_a Stack with integers
 * @param stack_b Auxiliary stack
 */
void	rr_rotate(t_stack *stack_a, t_stack *stack_b);

/**
 * @brief help us to verify how the list is in this moment
 * @param stack_a Stack with integers
 */
void	test_print_list(t_stack *stack_a);

#endif
