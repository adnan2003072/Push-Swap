/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <adnanbouzkraouoi037@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 21:59:06 by abouzkra          #+#    #+#             */
/*   Updated: 2025/12/04 22:00:10 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libpush_swap.h"

static int *stack_to_array(t_stack *s)
{
    int     *arr;
    t_node  *cur;
    int      i = 0;

    if (s->size == 0)
        return NULL;
    arr = malloc(sizeof(int) * s->size);
    if (!arr)
        return NULL;
    cur = s->top;
    while (i < s->size)
    {
        arr[i] = cur->data;
        cur = cur->next;
        i++;
    }
    return arr;
}

static void sort_array(int *arr, int n)
{
    int i, j, tmp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

int find_median(t_stack *s)
{
    int *arr;
    int median;

    if (s->size == 0)
        return 0;
    arr = stack_to_array(s);
    if (!arr)
        return 0;
    sort_array(arr, s->size);
    median = arr[s->size / 2];
    free(arr);
    return median;
}
