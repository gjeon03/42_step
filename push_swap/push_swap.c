/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 17:27:27 by gjeon             #+#    #+#             */
/*   Updated: 2021/06/10 17:27:29 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	myquicksort(int *arr, int start, int end)
{
	int		pivot;
	int		left;
	int		right;
	int		tmp;

	pivot = arr[start];
	left = start + 1;
	right = end;
	while (left <= right)
	{
		while (arr[left] < pivot)
			left++;
		while (arr[right] > pivot)
			right--;
		if (left <= right)
		{
			tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
		}
	}
	if (start < end)
	{
		tmp = arr[start];
		arr[start] = arr[right];
		arr[right] = tmp;
		myquicksort(arr, start, right - 1);
		myquicksort(arr, right + 1, end);
	}
}

int		main(int ac, char **av)
{
	int		i;
	t_stack	stack;

	if (!(stack.a = malloc(sizeof(int) * (ac - 1))))
		return (0);
	if (!(stack.b = malloc(sizeof(int) * (ac - 1))))
		return (0);
	i = -1;
	while (++i < ac - 1)
		stack.a[i] = ft_atoi(av[i + 1]);

	printf("initial value\n");
	for (int j = 0; j < 7; j++)
		printf(":%d: ", arr[j]);
	printf("\n");

	//myquicksort(arr, 0, ac - 2);
	int pivot = set_pivot(arr, 0, ac - 2);
	printf("pivot=%d\n", pivot);

	printf("sort value\n");
	for (int j = 0; j < 7; j++)
		printf(":%d: ", arr[j]);
	printf("\n");

	free(stack.a);
	free(stack.b);
	return (0);
}
