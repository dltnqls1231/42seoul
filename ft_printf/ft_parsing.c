/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sublee <sublee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 14:15:43 by sublee            #+#    #+#             */
/*   Updated: 2021/05/11 19:42:37 by sublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parsing_align(const char **fmt, t_flag *flag)
{
	while (**fmt == '-' || **fmt == '0')
	{
		if (**fmt == '-')
			flag->align = 1;
		if (**fmt == '0')
			flag->zero = 1;
		(*fmt)++;
	}
}

void	ft_parsing_width(const char **fmt, t_flag *flag, va_list ap)
{
	if (**fmt == '*')
	{
		flag->width = va_arg(ap, int);
		(*fmt)++;
	}
	else
	{
		while (**fmt >= '0' && **fmt <= '9')
		{
			flag->width = (flag->width * 10) + (**fmt - '0');
			(*fmt)++;
		}
	}
}

void	ft_parsing_precision(const char **fmt, t_flag *flag, va_list ap)
{
	if (**fmt == '.')
	{
		flag->dot = 1;
		(*fmt)++;
		if (**fmt == '*')
		{
			flag->precision = va_arg(ap, int);
			(*fmt)++;
		}
		else
		{
			while (**fmt >= '0' && **fmt <= '9')
			{
				flag->precision = (flag->precision * 10) + (**fmt - '0');
				(*fmt)++;
			}
		}
	}
}

int		ft_parsing(const char **fmt, t_flag *flag, va_list ap)
{
	(*fmt)++;
	ft_init(flag);
	ft_parsing_align(fmt, flag);
	ft_parsing_width(fmt, flag, ap);
	ft_parsing_precision(fmt, flag, ap);
	if (flag->width < 0)
	{
		flag->width *= -1;
		flag->align = 1;
	}
	if (flag->align)
		flag->zero = 0;
	return (ft_format(fmt, flag, ap));
}
