/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sublee <sublee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 11:30:38 by sublee            #+#    #+#             */
/*   Updated: 2021/07/06 11:30:39 by sublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void    sorting(int arr[], int num, t_node *a)
{
    int     i;
    int     temp;
    int     j;

    i = 0;
    j = 0;
    while (i++ < num)
    {
        arr[i] = a->value;
        a = a->next;
    }
    while (j++ < num)
    {
        i = 1;
        while (i++ < num)
        {
            if (arr[i] < arr[i-1])
            {
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
    }
}