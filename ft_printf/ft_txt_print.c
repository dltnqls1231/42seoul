/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_txt_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sublee <sublee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 16:03:20 by sublee            #+#    #+#             */
/*   Updated: 2021/05/13 12:57:54 by sublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_txt_width_print(t_flag *flag)
{
	int		result;
	int		print_len;
	char	format;

	result = 0;
	format = flag->format;
	print_len = flag->width - flag->length;
	if (format == 's' && flag->dot && flag->length > flag->precision)
		print_len = flag->width - flag->precision;
	while (flag->zero == 1 && print_len-- > 0)
		result += ft_put_str("0", 1);
	while (flag->zero == 0 && print_len-- > 0)
		result += ft_put_str(" ", 1);
	return (result);
}

int	ft_txt_precision_print(t_flag *flag, long long data)
{
	int		result;
	int		print_len;
	char	format;

	result = 0;
	format = flag->format;
	print_len = flag->length;
	if (format == 's' && flag->dot && flag->precision < flag->length)
		print_len = flag->precision;
	if (flag->format == 's')
		result = ft_put_str((char*)data, print_len);
	else
		result = ft_put_str((char*)(&data), print_len);
	return (result);
}

int	ft_txt_print(t_flag *flag, long long data)
{
	int	result;

	result = 0;
	if (flag->align == 0)
		result += ft_txt_width_print(flag);
	result += ft_txt_precision_print(flag, data);
	if (flag->align)
		result += ft_txt_width_print(flag);
	return (result);
}
