/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sublee <sublee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:31:02 by sublee            #+#    #+#             */
/*   Updated: 2021/01/09 15:40:14 by sublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	int		i;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	strjoin = (char *)malloc(sizeof(char) * len);
	if (strjoin == 0)
		return (NULL);
	i = 0;
	while (*s1)
	{
		strjoin[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		strjoin[i] = *s2;
		i++;
		s2++;
	}
	strjoin[i] = '\0';
	return (strjoin);
}
