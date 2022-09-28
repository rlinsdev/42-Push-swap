/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   samp_InsertionSort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:00:19 by rlins             #+#    #+#             */
/*   Updated: 2022/09/26 20:02:17 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// PARA ORDENAÇÃO ABAIXO DE 4, ESTE SERVIRÁ SIM
void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i-1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j+1] = arr[j];
			j = j-1;
		}
		arr[j+1] = key;
	}
}
