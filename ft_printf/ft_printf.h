/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sublee <sublee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:00:32 by sublee            #+#    #+#             */
/*   Updated: 2021/05/11 19:40:20 by sublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# define DEC "0123456789"
# define HEX_SMALL "0123456789abcdef"
# define HEX_CAPITAL "0123456789ABCDEF"

typedef struct	s_flag
{
	int			align;
	int			width;
	int			zero;
	int			precision;
	int			format;
	int			length;
	int			dot;
}				t_flag;

void			ft_init(t_flag *flag);
int				ft_printf(const char *fmt, ...);

void			ft_parsing_align(const char **fmt, t_flag *flag);
void			ft_parsing_width(const char **fmt, t_flag *flag, va_list ap);
void			ft_parsing_precision(const char **fmt,
		t_flag *flag, va_list ap);
int				ft_parsing(const char **fmt, t_flag *flag, va_list ap);

int				ft_num_width_print(t_flag *flag, long long data);
int				ft_num_precision_print(t_flag *flag, char *base,
		long long data);
int				ft_num_print(t_flag *flag, char *base, long long data);

int				ft_format_txt(t_flag *flag, va_list ap);
int				ft_format_number(t_flag *flag, va_list ap);
int				ft_format(const char **fmt, t_flag *flag, va_list ap);

int				ft_txt_width_print(t_flag *flag);
int				ft_txt_precision_print(t_flag *flag, long long data);
int				ft_txt_print(t_flag *flag, long long data);

int				ft_put_str(char *s, int len);
int				ft_strlen(char *str);
int				ft_len_as_base(long long data, char *base);
int				ft_base_print(t_flag *flag, char *base,
		long long data, int result);

#endif
