/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sublee <sublee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 15:19:34 by sublee            #+#    #+#             */
/*   Updated: 2021/07/02 15:19:36 by sublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void    sb(t_node *b)
{
    int     tmp;

    if (b == NULL || b->next == NULL)
        return ;
    tmp = b->value;
    b->value = b->next->value;
    b->next->value = tmp;
    write(1, "sb", 2);
}

void    *pb(t_node **a, t_node **b)
{
    t_node  *free_a;
    t_node  *new;
    int     tmp;

    if (*a == NULL)
        return ;
    new = malloc(sizeof(t_node));
    new->value = (*a)->value;
    new->next = (*b);
    (*b) = new;
    free_a = (*a);
    (*a) = (free_a->next);
    free(free_a);
    write(1, "pb", 2);
}

void    rb(t_node *b)
{

    int     temp;

    if (b == NULL)
        return ;
    temp = b->value;
    while(b->next != NULL)
    {
        b->value = b->next->value;
        b = b->next;
    }
    b->value = temp;
    write(1, "rb", 2);
}

void    rrb(t_node *b)
{
    int     before;
    int     after;
    t_node  *temp;

    temp = b;
    before = temp->value;
    after = temp->next->value;
    if (b == NULL)
        return ;
    while(temp->next)
    {
        after = temp->next->value;
        temp->next->value = before;
        before = after;
        temp = temp->next;
    }
    b->value = after;
    write(1, "rrb", 3);
}