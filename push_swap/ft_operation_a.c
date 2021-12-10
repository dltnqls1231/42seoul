/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sublee <sublee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:14:23 by sublee            #+#    #+#             */
/*   Updated: 2021/06/29 14:16:38 by sublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void    sa(t_node *a)
{
    int     tmp;

    if (a == NULL || a->next == NULL)
        return ;
    tmp = a->value;
    a->value = a->next->value;
    a->next->value = tmp;
    write(1, "sa\n", 2);
}

void    *pa(int num, t_node **a, t_node **b)
{
    while (num--)
    {
        t_node  *free_b;
        t_node  *new;
        int     tmp;

        if (*b == NULL)
            return ;
        new = malloc(sizeof(t_node));
        new->value = (*b)->value;
        new->next = (*a);
        (*a) = new;
        free_b = (*b);
        (*b) = (free_b->next);
        free(free_b);
        write(1, "pa\n", 2);
    }
}

void    ra(t_node *a)
{
    int     temp;

    if (a == NULL)
        return ;
    temp = a->value;
    while(a->next != NULL)
    {
        a->value = a->next->value;
        a = a->next;
    }
    a->value = temp;
    write(1, "ra\n", 2);
}

void    rra(t_node *a)
{
    int     before;
    int     after;
    t_node  *temp;

    temp = a;
    before = temp->value;
    after = temp->next->value;
    if (a == NULL)
        return ;
    while(temp->next)
    {
        after = temp->next->value;
        temp->next->value = before;
        before = after;
        temp = temp->next;
    }
    a->value = after;
    write(1, "rra\n", 3);
}