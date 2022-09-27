/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 07:17:02 by rlins             #+#    #+#             */
/*   Updated: 2022/09/26 21:44:06 by rlins            ###   ########.fr       */
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


/**
 * @brief First method in project.
 * @param argc Arguments count
 * @param argv Arguments Vector
 * @param envp Environment variables/pointer (PATH)
 * @return int
 */
int	start(int argc, char **argv);

// int quick();
// int merge_main();
void linked_list();


#endif
