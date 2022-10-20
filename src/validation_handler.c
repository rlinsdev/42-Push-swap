/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 07:55:51 by rlins             #+#    #+#             */
/*   Updated: 2022/10/20 09:49:27 by rlins            ###   ########.fr       */
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
			return (1);
		i++;
	}
	if (ft_is_duplicated(argv, argc))
		return (2);
	return (0);
}

/**
 * @brief Verify if all values are valid inputs
 * @param arg arguments
 * @return int
 */
static int	ft_is_number(char *arg)
{
	int	i;

	i = 0;
	if ((arg[i] == '-' || arg[i] == '+') && arg[i + 1] != '\0')
		i++;
	while (arg[i] && ft_is_valid_char_number(arg[i]))
		i++;
	if (arg[i] != '\0')
		return (0);
	return (1);
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

	i = 1;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (ft_number_validation(items[i], items[j]) == 0)
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

/**
 * @brief Verify if the char is a valid number
 * @param nbr
 * @return int 0 if it's not a number. 1 if is a valid number
 */
static int	ft_is_valid_char_number(char nbr)
{
	return (nbr >= '0' && nbr <= '9');
}

/**
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
	if (f_digit[i] == '+')
		i++;
	if (s_digit[j] == '+')
		j++;
	while (f_digit[i] != '\0' && s_digit[j] != '\0'
		&& f_digit[i] == s_digit[j])
	{
		i++;
		j++;
	}
	result = (unsigned char)f_digit[i] - (unsigned char)s_digit[j];
	return (result);
}
