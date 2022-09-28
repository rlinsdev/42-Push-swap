/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   samp_Radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:13:45 by rlins             #+#    #+#             */
/*   Updated: 2022/09/27 08:14:02 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	get_max (int a[], int n)
{
	int max = a[0];
	for (int i = 1; i < n; i++)
		if (a[i] > max)
			max = a[i];
	return (max);
}

static void	radix_sort (int a[], int n)
{
	int bucket[10][10], bucket_cnt[10];
	int i, j, k, r, NOP = 0, divisor = 1, lar, pass;
	lar = get_max (a, n);
	while (lar > 0)
	{
		NOP++;
		lar /= 10;
	}
	for (pass = 0; pass < NOP; pass++)
	{
		for (i = 0; i < 10; i++)
		{
			bucket_cnt[i] = 0;
		}
		for (i = 0; i < n; i++)
		{
			r = (a[i] / divisor) % 10;
			bucket[r][bucket_cnt[r]] = a[i];
			bucket_cnt[r] += 1;
		}
		i = 0;
		for (k = 0; k < 10; k++)
		{
			for (j = 0; j < bucket_cnt[k]; j++)
			{
				a[i] = bucket[k][j];
				i++;
			}
		}
		divisor *= 10;
		printf ("After pass %d : ", pass + 1);
		for (i = 0; i < n; i++)
			printf ("%d ", a[i]);
		printf ("\n");
	}
}

void radixsort()
{
	int i = 0;
	// int count = 9;
	// int arrNumber[] = {3, 2, 1, 6, 5, 4, 9, 8, 7};
	int count = 3;
	int arrNumber[] = {35, 22, 109};

	// int i, n, a[10];
	// scanf ("%d", &n);
	// printf ("Enter items: ");
	// for (i = 0; i < n; i++)
	// {
	// 	scanf ("%d", &a[i]);
	// }
	radix_sort (arrNumber, count);
	printf("Sorted items : ");
	for (i = 0; i < count; i++)
		printf ("%d ", arrNumber[i]);
	printf ("\n");
	// return (0);
}
