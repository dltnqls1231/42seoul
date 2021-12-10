/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sublee <sublee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 16:45:16 by sublee            #+#    #+#             */
/*   Updated: 2021/05/11 19:39:29 by sublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_num_width_print(t_flag *flag, long long data)
{
	int result;
	int print_len;

	result = 0;
	print_len = flag->width - flag->length;
	if (flag->length < flag->precision)
		print_len = flag->width - flag->precision;
	if (data < 0)
		print_len--;
	if (flag->format == 'p')
		print_len -= 2;
	if (flag->zero)
	{
		if (data < 0)
			result += ft_put_str("-", 1);
		if (flag->format == 'p')
			result += ft_put_str("0x", 2);
		while (print_len-- > 0)
			result += ft_put_str("0", 1);
	}
	if (flag->dot && flag->precision == 0 && data == 0)
		print_len++;
	while (flag->zero == 0 && print_len-- > 0)
		result += ft_put_str(" ", 1);
	return (result);
}

int		ft_num_precision_print(t_flag *flag, char *base, long long data)
{
	int result;
	int print_len;

	result = 0;
	if (flag->zero)
	{
		print_len = flag->precision - flag->length;
		while (print_len-- > 0)
			result += ft_put_str("0", 1);
		result += ft_base_print(flag, base, data, 0);
	}
	else
	{
		if (data < 0)
			result += ft_put_str("-", 1);
		if (flag->format == 'p')
			result += ft_put_str("0x", 2);
		print_len = flag->precision - flag->length;
		while (print_len-- > 0)
			result += ft_put_str("0", 1);
		result += ft_base_print(flag, base, data, 0);
	}
	return (result);
}

int		ft_num_print(t_flag *flag, char *base, long long data)
{
	int result;

	result = 0;
	if (flag->precision < 0)
	{
		flag->dot = 0;
		flag->precision = 0;
	}
	if (flag->dot == 1)
		flag->zero = 0;
	if (flag->align == 0)
		result += ft_num_width_print(flag, data);
	result += ft_num_precision_print(flag, base, data);
	if (flag->align)
		result += ft_num_width_print(flag, data);
	return (result);
}
