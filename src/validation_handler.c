/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 07:55:51 by rlins             #+#    #+#             */
/*   Updated: 2022/10/18 09:34:46 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	ft_is_duplicated(char **items, int count);
static int	ft_number_validation(char *f_digit, char *s_digit);
static int	ft_is_number(char *arg);
static int	ft_is_valid_char_number(char nbr);

int	invalid_input(char **argv, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_is_number(argv[i]))
			return (1);// Not Number
		i++;
	}
	if (ft_is_duplicated(argv, argc))
		return (2); // Duplicated
	return (0); // Return OK
}

/** [Passed]
 * @brief Verify if all values are valid inputs
 * @param arg arguments
 * @return int
 */
static int	ft_is_number(char *arg)
{
	int	i;

	i = 0;
	// Signal before number, just jump next value
	if ((arg[i] == '-' || arg[i] == '+') && arg[i + 1] != '\0')
		i++;
	// Verify char by char in param passed
	while (arg[i] && ft_is_valid_char_number(arg[i]))
		i++;
	// Next value must to be null (byte null)
	if (arg[i] != '\0')
		return (0); // Invalid
	return (1); // OK
}

/** [Passed]
 * @brief Check if exist the same number in param
 * @param items Arr of integers
 * @param count Total of integers
 */
static int	ft_is_duplicated(char **items, int count)
{
	int	i;
	int	j;

	// Start in 1. Do not compare first param (program name)
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

/** [passed]
 * @brief Verify if the char is a valid number
 * @param nbr
 * @return int 0 if it's not a number. 1 if is a valid number
 */
static int	ft_is_valid_char_number(char nbr)
{
	// Char between 0 and 9
	return (nbr >= '0' && nbr <= '9');
}

/** [Passed]
 * @brief Verify duplication and check if there are any plus (+) signal before
 * @param f_digit First number
 * @param s_digit Seconde Number
 * @return int: Diff between a value to another. If equals, will be the same
 */
static int	ft_number_validation(char *f_digit, char *s_digit)
{
	int	i;
	int	j;
	int	result;

	i = 0;
	j = i;
	// (+12) must be equal to (12)
	if (f_digit[i] == '+')
		i++;
	if (s_digit[j] == '+')
		j++;
	// TODO: Rever este while
	while (f_digit[i] != '\0' && s_digit[j] != '\0'
		&& f_digit[i] == s_digit[j])
	{
		// If same, go to the next digit
		i++;
		j++;
	}
	// Returning by ASCII diff
	result = (unsigned char)f_digit[i] - (unsigned char)s_digit[j];
	return (result);
}
