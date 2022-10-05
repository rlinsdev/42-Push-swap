/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 07:55:51 by rlins             #+#    #+#             */
/*   Updated: 2022/10/05 08:17:25 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	ft_is_digit(char *str);
static void	terminate(void);

void	check_input(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_is_digit(argv[i]))
			i++;
		else
			terminate();
	}
}

void	ft_is_duplicated(int *arr, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			// Verify if exist the same number
			if (arr[i] == arr[j])
			{
				free(arr);
				terminate();
			}
			j++;
		}
		i++;
	}
}

static int	ft_is_digit(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			str++;
		else
			return (0);
	}
	return (1);
}
// TODO: Get Better in this
static void	terminate(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
