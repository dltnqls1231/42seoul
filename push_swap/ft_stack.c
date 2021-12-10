/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sublee <sublee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 14:29:31 by sublee            #+#    #+#             */
/*   Updated: 2021/06/30 14:29:32 by sublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void    stack_init(t_node *a, int argc, char *argv[])
{
    int i;
    char **numbers;

    i = 1;
    numbers = argv;
    if (argc == 2)
        numbers = ft_split(argv[1], ' ');
    while(i++ <= argc - 1)
    {
        a = malloc(sizeof(t_node));
        if (argc == 2)
            a->value = ft_atoi(numbers[i]);
        else
            a->value = ft_atoi(numbers[i-1]);
        a = a->next;
    }
    a = NULL;
    if (argc == 2)
        free(numbers);
}