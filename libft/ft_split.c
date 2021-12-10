/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sublee <sublee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 17:23:40 by sublee            #+#    #+#             */
/*   Updated: 2021/01/14 23:35:03 by sublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		words(char *s, char c)
{
	int		count;

	count = 1;
	if (*s == 0)
		return (count);
	while (*s == c)
		s++;
	while (*s != 0)
	{
		if (*s == c)
		{
			count++;
			while (*s == c)
				s++;
		}
		else
			s++;
	}
	if (*(s - 1) != c)
		count++;
	return (count);
}

static int		strl(char *s, char c)
{
	int		len;

	len = 0;
	while ((*s != 0) && (*s != c))
	{
		len++;
		s++;
	}
	return (len);
}

static char		**free_split(char **split, int i)
{
	while (i > 0)
	{
		i--;
		free(split[i]);
	}
	free(split);
	return (NULL);
}

static char		**malloc_split(char **split, int num, char *new_s, char c)
{
	int		i;
	int		k;

	i = 0;
	while (i < num - 1)
	{
		k = 0;
		while (*new_s == c)
			new_s++;
		if (!(split[i] = (char *)malloc(sizeof(char) * (strl(new_s, c) + 1))))
			return (free_split(split, i));
		while (*new_s != '\0' && *new_s != c)
		{
			split[i][k] = *new_s;
			k++;
			new_s++;
		}
		split[i][k] = '\0';
		i++;
	}
	split[i] = NULL;
	return (split);
}

char			**ft_split(char const *s, char c)
{
	int		num;
	char	**split;
	char	*new_s;

	new_s = (char *)s;
	num = words(new_s, c);
	if (!num || !(split = (char **)malloc(sizeof(char *) * (num))))
		return (NULL);
	return (malloc_split(split, num, new_s, c));
}
