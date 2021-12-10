/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sublee <sublee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 11:44:11 by sublee            #+#    #+#             */
/*   Updated: 2021/01/07 16:59:20 by sublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = (size_t)ft_strlen(dst);
	src_len = (size_t)ft_strlen(src);
	i = 0;
	if (size > dst_len)
	{
		while (*dst)
			dst++;
		while ((i++ < size - dst_len - 1) && (*src != '\0'))
			*dst++ = *src++;
		*dst = '\0';
		return (src_len + dst_len);
	}
	return (src_len + size);
}
