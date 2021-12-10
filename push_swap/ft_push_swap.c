/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sublee <sublee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:24:52 by sublee            #+#    #+#             */
/*   Updated: 2021/06/30 15:24:53 by sublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void    exit_all(t_node *a, t_node *b)
{
    while(a != NULL)
    {
        free(a);
        a = a->next;
    }
    while(b != NULL)
    {
        free(b);
        b = b->next;
    }
    exit(0);
}

void    