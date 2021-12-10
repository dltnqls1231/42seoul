/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sublee <sublee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:13:44 by sublee            #+#    #+#             */
/*   Updated: 2021/05/13 12:58:21 by sublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_format_txt(t_flag *flag, va_list ap)
{
	long long	data;
	int			result;
	char		format;

	result = 0;
	format = flag->format;
	if (format == 's')
	{
		data = (long long)va_arg(ap, char*);
		if (data == 0)
			data = (long long)"(null)";
	}
	else if (format == 'c')
		data = va_arg(ap, int);
	else
		data = '%';
	flag->length = 1;
	if (format == 's')
		flag->length = ft_strlen((char*)data);
	if (flag->precision < 0)
		flag->precision = flag->length;
	result = ft_txt_print(flag, data);
	return (result);
}

int		ft_format_number(t_flag *flag, va_list ap)
{
	long long	data;
	char		*base;
	char		format;

	format = flag->format;
	if (format == 'd' || format == 'i')
		data = va_arg(ap, int);
	else if (format == 'u' || format == 'x' || format == 'X')
		data = va_arg(ap, unsigned int);
	else
		data = va_arg(ap, long long);
	if (format == 'd' || format == 'i' || format == 'u')
		base = DEC;
	else if (format == 'X')
		base = HEX_CAPITAL;
	else
		base = HEX_SMALL;
	flag->length = ft_len_as_base(data, base);
	return (ft_num_print(flag, base, data));
}

int		ft_format(const char **fmt, t_flag *flag, va_list ap)
{
	int		result;

	result = 0;
	flag->format = **fmt;
	if (**fmt == 'd' || **fmt == 'i' || **fmt == 'x')
		result = ft_format_number(flag, ap);
	else if (**fmt == 'X' || **fmt == 'p' || **fmt == 'u')
		result = ft_format_number(flag, ap);
	else if (**fmt == '%' || **fmt == 'c' || **fmt == 's')
		result = ft_format_txt(flag, ap);
	else
		return (-1);
	(*fmt)++;
	return (result);
}
