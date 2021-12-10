/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_ab2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sublee <sublee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 15:34:10 by sublee            #+#    #+#             */
/*   Updated: 2021/07/05 15:34:11 by sublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void    swap(t_node *p)
{
    int     tmp;

    if (p == NULL || p->next == NULL)
        return ;
    tmp = p->value;
    p->value = p->next->value;
    p->next->value = tmp;
}

void    rotate(t_node *a)
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
}

void    rev_rotate(t_node *a)
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
}