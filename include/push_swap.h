/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 07:17:02 by rlins             #+#    #+#             */
/*   Updated: 2022/10/18 07:42:22 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include <stdio.h> // Printf - Remover
# include <stdlib.h> // malloc
# include <limits.h> // Int Max / min

// Index = Must Stay. Position = Stay right now!
// Index calculate just 1 time. Position must be updated...
// Linked List
typedef struct s_stack
{
	int value; // Integer value to sort
	int	index; // Essential to sort algorithm. Where in the list it must stay
	int	pos; // Essential to sort algorithm. (Is like the index in array). Will exist just upper 4. Itś the position where the number stay right now!
	int tar_pos; // Target position. Will exist just in B. Maybe this value will be the same target
	int	cost_a; // how many steps to rotate Stack A
	int	cost_b; // how many steps to rotate Stack B. TODO: Cost just exist in B????
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
 * @param stack Linked list
 * @return t_stack* with next point to null
 */
t_stack *get_last_stack(t_stack *stack);

/**
 * @brief How was used malloc to generate a stack object, we must free this
 * memory allocation in linked list
 * @param stack loop through all linked stacks
 */
void	free_stack_linked(t_stack **stack);


/** [Passed]
 * @brief Get the stack size
 * @param stack will check through all items
 * @return int - Stack Size
 */
int	get_stack_size(t_stack	*stack);

/**
 * @brief Update the index in each value in stack. The index will be compared
 * with the actual value to be order (while inside while).
 * @param stack_a - All register in linked list
 * @param stack_size - How many times must to be passed
 * @sample: values: [4], [3], [2], [1]
 * 			Index:	[1],  [2], [3], [4]
 */
void	init_stack_index(t_stack *stack_a, int stack_size);

/**
 * @brief Update position will simple loop though all elements and put a number * in position. This must be update when the position in pill change. Will
 * initialize and update position of stack.
 * Position start in 0
 *		value:		[1]	[3]	[4]
 *		index:		[1]	[0]	[2]
 *		position:	[0]	[1] [2]
 * @param stack
 */
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
 * @brief Will update cost_a and cost_b in stack B.
 * calculates the cost of moving each element of stack B into the correct
 * position in stack A.
 * Two costs are calculated:
 *	cost_b represents the cost of getting the element to the top of the B stack
 *	cost_a represents the cost of getting to the right position in stack A.
 * If the element is in the bottom half of the stack, the cost will be negative,
 * If it is in the top half, the cost is positive.
 * @param stack_a Stack with integers
 * @param stack_b Auxiliary stack
 */
void	get_cost(t_stack **stack_a, t_stack **stack_b);

/** [passed]
 * @brief Gets the current position of the lower number in Stack.
 * @param stack Stack A
 * @return int - Position value
 */
int	get_position_lower_element(t_stack **stack);

/**
 * @brief Send all integers to B, but stay with 3 in stack A.
 * @param stack_a Stack with integers
 * @param stack_b Auxiliary stack
 */
void	push_all_but_three(t_stack **stack_a, t_stack **stack_b, int
stack_size);

/**
 * @brief
 *
 * @param stack_a
 * @param stack_b
 * @param cost_a
 * @param cost_b
 */
void	aux_rev_rotate_both(t_stack **stack_a, t_stack **stack_b, int *cost_a, int *cost_b);

/**
 * @brief
 *
 * @param stack_a
 * @param stack_b
 * @param cost_a
 * @param cost_b
 */
void	aux_rotate_both(t_stack **stack_a, t_stack **stack_b, int *cost_a, int *cost_b);

/**
 * @brief
 *
 * @param stack_b
 * @param cost
 */
void	aux_rotate_b(t_stack **stack_b, int *cost);

/**
 * @brief
 *
 * @param stack_a
 * @param cost
 */
void	aux_rotate_a(t_stack **stack_a, int *cost);

/**
 * @brief Finds the element in stack B with the cheapest cost to move to
 * stack A and moves it to the correct position in stack A.
 * @param stack_a
 * @param stack_b
 */
void	exec_cheapest_move(t_stack **stack_a, t_stack **stack_b);

/**
 * @brief Get the before last element
 * @param stack
 * @return t_stack* before the end
 */
t_stack	*get_stack_before_tail(t_stack *stack);

/**
 * @brief will return the last element
 * @param stack
 * @return t_stack* Pointer to last stack
 */
t_stack	*get_stack_tail(t_stack *stack);

/**
 * @brief
 *
 * @param stack
 * @return int
 */
int	find_highest_index(t_stack *stack);

/** [Passed]
 * @brief
 *	Assigns a target position in stack A to each element of stack A.
 *	The target position is the spot the element in B needs to
 *	get to in order to be sorted correctly. This position will
 *	be used to calculate the cost of moving each element to
 *	its target position in stack A.
 * @param stack_a Stack with integers
 * @param stack_b Auxiliary stack
 */
void	handler_target_position(t_stack **stack_a, t_stack **stack_b);

/** [OK]
 * @brief sa (swap a): Swap the first 2 elements at the top of stack a.
 * Do nothing if there is only one or no elements.
 * @param stack_a Stack with integers
 * @param stack_b Auxiliary stack
 */
void	swap_a(t_stack **stack_a);

/** (Deprecated)
 * @brief (swap b): Swap the first 2 elements at the top of stack b.
 * Do nothing if there is only one or no elements.
 * @param stack_b Auxiliary stack
 */
void	swap_b(t_stack **stack_b);

/** (Deprecated)
 * @brief sa (Swap A) and sb (Swap B) at the same time.
 * @param stack_a Stack with integers
 * @param stack_b Auxiliary stack
 */
void	swap_swap(t_stack **stack_a, t_stack **stack_b);

/** [OK]
 * @brief pa (push a): Take the first element at the top of b and put it at the * top of a. Do nothing if b is empty.
 * @param stack_a Stack with integers
 * @param stack_b Auxiliary stack
 */
void	push_a(t_stack **stack_a, t_stack **stack_b);

/** [OK]
 * @brief (push b): Take the first element at the top of a and put it at the
 * top of b. Do nothing if a is empty.
 * @param stack_a Stack with integers
 * @param stack_b Auxiliary stack
 */
void	push_b(t_stack **stack_a, t_stack **stack_b);

/** [OK]
 * @brief ra (rotate a): Shift up all elements of stack a by 1.
 * The first element becomes the last one
 * @param stack_a Stack with integers
 * @param stack_b Auxiliary stack
 */
void	rotate_a(t_stack **stack_a);

/** [OK]
 * @brief (rotate b): Shift up all elements of stack b by 1.
 * The first element becomes the last one.
 * @param stack_b Auxiliary stack
 */
void	rotate_b(t_stack **stack_b);

/** [OK]
 * @brief ra (rotate a) and rb (rotate b) at the same time
 * @param stack_a Stack with integers
 * @param stack_b Auxiliary stack
 */
void	rotate_rotate(t_stack **stack_a, t_stack **stack_b);

/** [OK]
 * @brief rra (reverse rotate a): Shift down all elements of stack a by 1.
 * The last element becomes the first one.
 * @param stack_a Stack with integers
 */
void	r_rotate_a(t_stack **stack_a);

/** [OK]
 * @brief (reverse rotate b): Shift down all elements of stack b by 1.
 * The last element becomes the first one.
 * @param stack_b Auxiliary stack
 */
void	r_rotate_b(t_stack **stack_b);

/** [OK]
 * @brief rra and rrb at the same time.
 * @param stack_a Stack with integers
 * @param stack_b Auxiliary stack
 */
void	rr_rotate(t_stack **stack_a, t_stack **stack_b);

/**
 * @brief Exit program. Invalid integer passed by param
 * @param stack_a Stack with integers
 */
void	invalid_int(t_stack **stack_a);

/**
 * @brief help us to verify how the list is in this moment
 * @param stack_a Stack with integers
 */
void	ft_print_list(t_stack *stack_a);

#endif
