/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sublee <sublee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:51:18 by sublee            #+#    #+#             */
/*   Updated: 2021/06/29 13:51:20 by sublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int main(int argc, char *argv[])
{
    t_node  *stack_a;
    t_node  *stack_b;

    if (argc == 0 || argc == 1)
        return (0);
    stack_a = malloc(sizeof(t_node) * argc);
    stack_init(stack_a, argc, argv);
    stack_b = NULL;
    push_swap(stack_a, stack_b);
}