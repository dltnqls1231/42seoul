/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sublee <sublee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 16:31:00 by sublee            #+#    #+#             */
/*   Updated: 2021/04/29 16:31:02 by sublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_str(char *s, int len)
{
	write(1, s, len);
	return (len);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str && *str)
	{
		str++;
		len++;
	}
	return (len);
}

int	ft_len_as_base(long long data, char *base)
{
	int	num_len;
	int	base_len;

	if (data == 0)
		return (1);
	if (data < 0)
		data *= -1;
	num_len = 0;
	base_len = ft_strlen(base);
	while (data != 0)
	{
		data = data / base_len;
		num_len++;
	}
	return (num_len);
}

int	ft_base_print(t_flag *flag, char *base, long long data, int result)
{
	int	base_len;

	base_len = ft_strlen(base);
	if (data < 0)
		data *= -1;
	if (data == 0 && flag->dot && flag->precision == 0)
		;
	else
	{
		if (data / base_len > 0)
			result += ft_base_print(flag, base, data / base_len, result);
		result += ft_put_str(&(base[data % base_len]), 1);
	}
	return (result);
}
