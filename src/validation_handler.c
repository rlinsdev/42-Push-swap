/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 07:55:51 by rlins             #+#    #+#             */
/*   Updated: 2022/10/06 13:38:35 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	ft_is_duplicated(char **items, int count);
static int	ft_number_validation(char *f_item, char *s_item);

int	invalid_input(char **argv, int argc)
{
	int	i;

	i = 1;
	if (ft_is_duplicated(argv, argc))
		return (1);

	while (i < argc)
	{
		// if (ft_is_digit(argv[i]))
	 	i++;
	}
}



/**
 * @brief Check if exist the same number in param
 * @param items Arr of integers
 * @param count Total of integers
 */
static int	ft_is_duplicated(char **items, int count)
{
	int	i;
	int	j;

	// Start in 1. Don't need compare first param
	i = 1;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			// Verify if exist the same number
			if (ft_number_validation(items[i], items[j]) == 0)
			{
				// Identical numbers
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

/**
 * @brief Verify duplication and check if there are any plus (+) signal before
 * @param f_item
 * @param s_item
 * @return int: Diff between a value to another. If equals, will be the same
 */
static int	ft_number_validation(char *f_item, char *s_item)
{
	int	i;
	int	j;
	int result;

	i = 0;
	j = i;
	// +12 must be equal to 12
	if (f_item[i] == '+')
	{
		i++;
	}
	if(s_item[j] == '+')
	{
		j++;
	}
	while (f_item[i] != '\0' && s_item[j] != '\0'
		&& f_item[i] == s_item[j])
	{
		// If same, next to the next digit
		i++;
		j++;
	}

	// Returning by ASCII diff
	result = (unsigned char)f_item[i] - (unsigned char)s_item[j];
	return (result);
}
