/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sublee <sublee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:56:52 by sublee            #+#    #+#             */
/*   Updated: 2021/07/02 14:56:53 by sublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void    sort_a(int num, t_node *a)
{
    if (num == 3)
    {
        if ((a->value < a->next->next->value && a->next->next->value <
            a->next->value) || (a->next->next->value < a->next->value &&
            a->next->value < a->value))
        {
            sa(a);
            rra(a);
        }
        else if (a->next->value < a->value && a->value < a->next->next->value)
            sa(a);
        else if (a->next->next->value < a->value && a->value < a->next->value)
            rra(a);
        else if (a->value < a->next->next->value && a->next->next->value <
            a->value)
            ra(a);
    }
    else if (num == 2)
    {
        if (a->next->value < a->value)
            sa(a);
    }
}
void    sort_b(int num, t_node **a, t_node **b)
{
    if (num == 3)
    {
        if ((*b)->value < (*b)->next->value &&
            (*b)->next->value < (*b)->next->next->value)
        {
            sb(b);
        }
    }
}

int     find_pivot(int num, t_node *a)
{
    int     arr[num];

    sorting(arr, num, a);
    return (arr[num/2]);
}

void    atob(int num, t_node **a, t_node **b)
{
    int pivot;
    int i;
    int count_pb;
    int count_ra;

    i = 0;
    count_pb = 0;
    count_ra = 0;
    if (num <= 3)
    {
        sort_a(num, *a);
        return ;
    }
    pivot = find_pivot(num, *a);
    while (num--)
    {
        if ((*a)->value >= pivot)
        {
            ra(*a);
            count_ra++;
        }
        else
        {
            pb(a,b);
            count_pb++;
        }
    }
    while (i++ < count_ra)
        rra(*a);
    atob(count_ra, a, b);
    btoa(count_pb, a, b);
}
