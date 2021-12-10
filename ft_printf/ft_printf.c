/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sublee <sublee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 13:06:15 by sublee            #+#    #+#             */
/*   Updated: 2021/05/11 19:44:11 by sublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init(t_flag *flag)
{
	flag->zero = 0;
	flag->width = 0;
	flag->precision = 0;
	flag->dot = 0;
	flag->align = 0;
	flag->length = 0;
	flag->format = ' ';
}

int		ft_printf(const char *fmt, ...)
{
	va_list		ap;
	t_flag		flag;
	int			ret;
	int			len;

	va_start(ap, fmt);
	ret = 0;
	ft_init(&flag);
	while (*fmt)
	{
		if (*fmt != '%')
		{
			write(1, fmt++, 1);
			ret++;
		}
		else
		{
			len = ft_parsing(&fmt, &flag, ap);
			if (len < 0)
				return (-1);
			ret += len;
		}
	}
	va_end(ap);
	return (ret);
}
