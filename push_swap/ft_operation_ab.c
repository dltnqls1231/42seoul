/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_ab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sublee <sublee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 15:27:32 by sublee            #+#    #+#             */
/*   Updated: 2021/07/05 15:27:35 by sublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void    ss(t_node *a, t_node *b)
{
    swap(a);
    swap(b);
    write(1, "ss\n", 2);
}

void    rr(t_node *a, t_node *b)
{
    rotate(a);
    rotate(b);
    write(1, "rr\n", 2);
}

void    rrr(t_node *a, t_node *b)
{
    rev_rotate(a);
    rev_rotate(b);
    write(1, "rrr\n", 3);
}