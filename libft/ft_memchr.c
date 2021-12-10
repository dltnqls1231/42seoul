/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sublee <sublee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 12:38:52 by sublee            #+#    #+#             */
/*   Updated: 2021/01/07 16:07:53 by sublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *ptr, int value, size_t num)
{
	size_t			i;
	unsigned char	*ptr1;

	ptr1 = (unsigned char *)ptr;
	i = 0;
	while (i < num)
	{
		if (ptr1[i] == (unsigned char)value)
			return (ptr + i);
		i++;
	}
	return (0);
}
