/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sublee <sublee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 19:55:18 by sublee            #+#    #+#             */
/*   Updated: 2021/01/08 20:43:13 by sublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ft_strlen(big) < ft_strlen(little) || ft_strlen(little) > len)
		return (NULL);
	while (i < len - ft_strlen(little) + 1)
	{
		j = 0;
		while (little[j])
		{
			if (big[i + j] == little[j])
				j++;
			else
				break ;
		}
		if (little[j] == '\0')
			return (char *)(big + i);
		i++;
	}
	return (NULL);
}
