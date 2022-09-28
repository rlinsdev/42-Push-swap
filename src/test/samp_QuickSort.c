/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   samp_QuickSort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:54:22 by rlins             #+#    #+#             */
/*   Updated: 2022/09/25 18:37:12 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/**
 * @brief
 *
 * @param arrNumber arrNumbers
 * @param pFirst pFirst index Element
 * @param pLast pLast index Element
 */
static void	quick_sort(int arrNumber[10], int pFirst, int pLast)
{
	int first;
	int last;
	int pivot;
	int temp;
	if (pFirst < pLast)
	{
		pivot = pFirst;
		first = pFirst;
		last = pLast;
		while(first < last)
		{
			while(arrNumber[first] <= arrNumber[pivot] && first < pLast)
				first++;
			while(arrNumber[last] > arrNumber[pivot])
				last--;
			if (first < last)
			{
				temp = arrNumber[first];
				arrNumber[first] = arrNumber[last];
				arrNumber[last] = temp;
			}
		}
		temp = arrNumber[pivot];
		arrNumber[pivot] = arrNumber[last];
		arrNumber[last] = temp;
		quick_sort(arrNumber, pFirst, (last - 1));
		quick_sort(arrNumber, (last + 1), pLast);
	}
}

//https://www.tutorialspoint.com/explain-the-quick-sort-technique-in-c-language
int quick()
{
	int i = 0;
	// int count = 9;
	// int arrNumber[] = {3, 2, 1, 6, 5, 4, 9, 8, 7};
	int count = 3;
	int arrNumber[] = {3, 2, 1};

	quick_sort(arrNumber, 0, (count - 1));
	printf("Order of Sorted elements: ");
	for(i = 0; i < count; i++)
	{
		printf(" %d",arrNumber[i]);
	}
	return (0);
}
