/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 07:17:02 by rlins             #+#    #+#             */
/*   Updated: 2022/10/20 09:20:11 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include <stdlib.h> // malloc

/**
 * @brief Linked List
 * Value: Integer value to sort
 * Index: Essential to sort algorithm. Where in the list it must stay
 * Pos: Essential to sort algorithm. (Is like the index in array).
 *  Will exist just upper 4. Its the position where the number stay right now!
 * Tar_pos: Target position. Will exist just in B. Where the value should be.
 *  Some times, it may be the same value
 * cost_a: how many steps to rotate Stack A. Cost just exist in B
 * cost_b: How many steps to rotate Stack B. Cost just exist in B
 */
typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				tar_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

/**
 * @brief First method in project.
 * @param argc Arguments count
 * @param argv Arguments Vector
 * @return int
 */
int		start(int argc, char **argv);

/**
 * @brief Verify if param is correct. Not allowed duplicate, spaces. Just number
 * @param argv Vector of args
 * @param argc Count of args
 * @return int: Input invalid (1) Input Valid (0)
 */
int		invalid_input(char **argv, int argc);

/**
 * @brief Will populate stack_a with values in array
 * @param argv Vector of args
 * @param argc Count of args
 * @return t_stack* filled
 */
t_stack	*array_to_stack(char **argv, int argc);

/**
 * @brief Get the last stack object. Will be used in rotate and to push a list
 * @param stack Linked list
 * @return t_stack* with next point to null
 */
t_stack	*get_last_stack(t_stack *stack);

/**
 * @brief How was used malloc to generate a stack object, we must free this
 * memory allocation in linked list
 * @param stack loop through all linked stacks
 */
void	free_stack_linked(t_stack **stack);

/**
 * @brief Get the stack size
 * @param stack will check through all items
 * @return int - Stack Size
 */
int		get_stack_size(t_stack	*stack);

/**
 * @brief Initialize a Stack, updating the index in each value in stack.
 * The index will be compared with the actual value to be order (while inside
 * while). This method will be called just once, in initialize routine.
 * @param stack_a - All register in linked list
 * @param stack_size - How many times must to be passed
  */
void	init_stack_index(t_stack *stack_a, int stack_size);

/**
 * @brief Update position. Will loop though all elements and put a number
 * in position. This must be update when the position in pill change. Will
 * initialize and update position of stack.
 * Position start in 0
 * @param stack
 */
void	update_position(t_stack **stack);

/**
 * @brief Verify if the stack is sorted. Will help us to choose the type of
 * method choose to sort the pile. Will help when the List is sorted and we
 * don't need do any action.
 * Will be called in the end too, to check if stack is sorted correctly
 * @param stack_a Stack with integers
 * @return (1) if sorted. (0) if mess pile
 */
int		is_stack_sorted(t_stack *stack_a);

/**
 * @brief When stack have just 3 items, this will bhe the best sort method.
 * Based on the Highest_index, we will work with Rotate (R) or Reverse Rotate
 * (RR). And Then, Swap (if necessary)
 * @param stack_a Stack with integers
 */
void	simple_sort(t_stack **stack_a);

/**
 * @brief Core of program. Responsible to sort more than 3 integers. Send all
 * element to B, but 3. Find current position. Calculate target position. Check
 * the cost of actions. Take action. Try to let the Highest Number in Stack A.
 * @param stack_a Stack with integers
 * @param stack_b Auxiliary stack
 * @param stack_size Size of stack
 */
void	core_sort_stack(t_stack **stack_a, t_stack **stack_b, int stack_size);

/**
 * @brief Will update cost_a and cost_b in stack B.
 * Verify how many actions must to do to order a list.
 * Two costs are calculated:
 *	cost_b represents the cost of getting the element to the top of the B stack
 *	cost_a represents the cost of getting to the right position in stack A.
 * If the element is in the bottom half of the stack, the cost will be negative,
 * If it is in the top half, the cost is positive.
 * Cost B -> Will be always the position B to be send to A. If the position
 * is in middle to tail, negative it (reverse rotate cheapest).
 * Cost A -> Will be always the target Position A. If the position is in middle
 * to tail, negative it (Reverse rotate cheapest)
 * @param stack_a Stack with integers
 * @param stack_b Auxiliary stack
 */
void	get_cost(t_stack **stack_a, t_stack **stack_b);

/**
 * @brief Gets the current position of the lower number in Stack.
 * @param stack Stack A
 * @return int - Position value
 */
int		get_position_lower_element(t_stack **stack);

/**
 * @brief Send all integers to B, but stay with 3 in stack A. In this moment,
 * we apply the first sort method. Lets largest number in A
 * @param stack_a Stack with integers
 * @param stack_b Auxiliary stack
 */
void	push_all_but_three(t_stack **stack_a, t_stack **stack_b,
			int stack_size);

/**
 * @brief Will Reverse Rotate Both stacks
 * Both (cost_a and cost_b) must to be negative. If yes, reverse rotate both
 * @param stack_a Stack with integers
 * @param stack_b Auxiliary stack
 * @param cost_a How many reverse rotate must be done
 * @param cost_b How many reverse rotate must be done
 */
void	aux_rev_rotate_both(t_stack **stack_a, t_stack **stack_b,
			int *cost_a, int *cost_b);

/**
 * @brief Will Rotate Both stacks
 * Both (cost_a and cost_b) must to be positive. If yes, reverse rotate both
 * @param stack_a Stack with integers
 * @param stack_b Auxiliary stack
 * @param cost_a How many rotate must be done
 * @param cost_b How many rotate must be done
 */
void	aux_rotate_both(t_stack **stack_a, t_stack **stack_b, int *cost_a,
			int *cost_b);

/**
 * @brief Will Rotate Stack_B.
 * If Cost is positive, just Rotate.
 * If Cost is negative. Reverse Rotate
 * How many times? Integer value of cost
 * If Cost is 0, nothing to do.
 * @param stack_b Stack with integers
 * @param cost Indicate the number of rotations, and direction
 */
void	aux_rotate_b(t_stack **stack_b, int *cost);

/**
 * @brief Will Rotate Stack_A.
 * If Cost is positive, just Rotate.
 * If Cost is negative. Reverse Rotate
 * How many times? Integer value of cost
 * If Cost is 0, nothing to do
 * @param stack_a Stack with integers
 * @param cost Indicate the number of rotations, and direction
 */
void	aux_rotate_a(t_stack **stack_a, int *cost);

/**
 * @brief Finds the element in stack B with the cheapest cost to move to
 * stack A and moves it to the correct position in stack A.
 * @param stack_a Stack with integers
 * @param stack_b Auxiliary stack
 */
void	exec_cheapest_move(t_stack **stack_a, t_stack **stack_b);

/**
 * @brief Get the stack before last element
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
 * @brief Return the highest index in stack. This will help us to handler
 * simple sort approach.
 * @param stack
 * @return int value of maxIndex
 */
int		find_highest_index(t_stack *stack);

/**
 * @brief Assigns a target position in stack A to each element of stack A.
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
 * @brief pa (push a): Take the first element at the top of b and put it
 * at the top of a. Do nothing if b is empty.
 * @param stack_a Stack with integers
 * @param stack_b Auxiliary stack
 */
void	push_a(t_stack **stack_a, t_stack **stack_b);

/** [OK]
 * @brief (push b): Take the first element at the top of a and put it at
 * the top of b. Do nothing if a is empty.
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
 * @param identify (A) Stack A. (B) Stack B
 */
void	ft_print_list(t_stack *stack_a, char identify);

#endif
