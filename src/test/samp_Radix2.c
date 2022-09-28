/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   samp_Radix2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:13:45 by rlins             #+#    #+#             */
/*   Updated: 2022/09/27 20:38:13 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//https://www.programiz.com/dsa/radix-sort
#include <push_swap.h>

// Function to get the largest element from an array
static int	getMax(int array[], int n)
{
	int max = array[0];
	for (int i = 1; i < n; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

// Using counting sort to sort the elements in the basis of significant places
static void	countingSort(int array[], int size, int place)
{
	int output[size + 1];
	int max = (array[0] / place) % 10;

	for (int i = 1; i < size; i++)
	{
		if (((array[i] / place) % 10) > max)
			max = array[i];
	}
	// ?? O Array está send ocriado com o número máximo passado oO??
	int count[max + 1];
	// int count[size + 1]; // Lins

	for (int i = 0; i < max; ++i)
	// for (int i = 0; i < (size+1); ++i) //lins
		count[i] = 0;

	// Calculate count of elements
	for (int i = 0; i < size; i++)
		count[(array[i] / place) % 10]++;

	// Calculate cumulative count
	for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// Place the elements in sorted order
	for (int i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / place) % 10] - 1] = array[i];
		count[(array[i] / place) % 10]--;
	}

	for (int i = 0; i < size; i++)
		array[i] = output[i];
}

// Main function to implement radix sort
static void	radixsort(int array[], int size)
{
	// Get maximum element
	int max = getMax(array, size);

	// Apply counting sort to sort elements based on place value.
	for (int place = 1; max / place > 0; place *= 10)
		countingSort(array, size, place);
}

// Print an array
void	printArray(int array[], int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		printf("%d  ", array[i]);
		i++;
	}
	printf("\n");
}

// Driver code
void	radixsort2()
{
	// int sortList[] = {121, 432, 564, 23, 1, 45, 788, 36};
	int sortList[] = {121, 5, 333};

	// With this it's possible discovery the size of array!
	int nro_itens = sizeof(sortList) / sizeof(sortList[0]);

	printf("Before:\n");
	printArray(sortList, nro_itens);

	radixsort(sortList, nro_itens);
	printf("After:\n");
	printArray(sortList, nro_itens);
}
