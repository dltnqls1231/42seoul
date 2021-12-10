/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sublee <sublee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 13:11:50 by sublee            #+#    #+#             */
/*   Updated: 2021/01/09 15:23:54 by sublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		digit(int n)
{
	unsigned int	i;
	int				num;

	if (n < 0)
		i = (unsigned int)(n * (-1));
	else
		i = (unsigned int)n;
	num = 0;
	if (i == 0)
		return (1);
	while (i != 0)
	{
		num++;
		i /= 10;
	}
	if (n < 0)
		num += 1;
	return (num);
}

char	*ft_itoa(int n)
{
	char			*itoa;
	int				digit_num;
	unsigned int	num;

	if (n < 0)
		num = (unsigned int)(n * (-1));
	else
		num = (unsigned int)n;
	digit_num = digit(n);
	if (!(itoa = (char *)malloc(sizeof(char) * (digit_num + 1))))
		return (NULL);
	itoa[digit_num--] = '\0';
	if (num == 0)
		itoa[0] = '0';
	while (num > 0)
	{
		itoa[digit_num--] = '0' + (num % 10);
		num /= 10;
	}
	if (n < 0)
		itoa[0] = '-';
	return (itoa);
}
