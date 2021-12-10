/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sublee <sublee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 16:01:29 by sublee            #+#    #+#             */
/*   Updated: 2021/01/11 23:07:50 by sublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_first(char const *s1, char const *set)
{
	int		first;
	char	*ptr;

	ptr = (char *)set;
	first = 0;
	while (s1[first] && ft_strchr(ptr, s1[first]))
		first++;
	return (first);
}

int		ft_last(char const *s1, char const *set)
{
	int		last;
	char	*ptr;

	ptr = (char *)set;
	last = ft_strlen(s1) - 1;
	while ((last >= 0) && ft_strchr(ptr, s1[last]))
		last--;
	return (last);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		first;
	int		last;
	char	*strtrim;

	first = ft_first(s1, set);
	last = ft_last(s1, set);
	if (s1 == 0 || first > last)
	{
		strtrim = (char *)malloc(1);
		*strtrim = '\0';
		return (strtrim);
	}
	if (set == 0)
		return (ft_strdup(s1));
	strtrim = (char *)malloc(sizeof(char) * (last - first + 2));
	if (strtrim == 0)
		return (NULL);
	ft_strlcpy(strtrim, s1 + first, last - first + 2);
	return (strtrim);
}
