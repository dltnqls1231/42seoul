/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sublee <sublee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 14:29:11 by sublee            #+#    #+#             */
/*   Updated: 2021/02/19 11:11:32 by sublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t		ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char		*ft_strjoin(char *s1, char *s2)
{
	char	*strjoin;
	int		i;
	int		len;

	if (s1 == NULL)
		return (ft_strdup(s2));
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	strjoin = (char *)malloc(sizeof(char) * len);
	if (strjoin == 0)
		return (NULL);
	i = 0;
	while (*s1)
		strjoin[i++] = *(s1++);
	while (*s2)
		strjoin[i++] = *(s2++);
	strjoin[i] = '\0';
	return (strjoin);
}

char		*ft_strdup(char *str)
{
	int		len;
	int		i;
	char	*dupstr;

	i = 0;
	len = ft_strlen(str);
	dupstr = (char *)malloc(sizeof(char) * (len + 1));
	if (dupstr == 0)
		return (0);
	while (str[i])
	{
		dupstr[i] = str[i];
		i++;
	}
	dupstr[i] = '\0';
	return (dupstr);
}
