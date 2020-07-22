/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 14:58:13 by rhulk             #+#    #+#             */
/*   Updated: 2019/08/29 16:59:46 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "defines.h"
# include "structures.h"
# include <stdarg.h>

int			ft_printf(const char *format, ...);
int			ft_dprintf(int fd, const char *format, ...);

int			parsing(int fd, const char *format, int *i, va_list args);
int			flag_parsing(t_printf *p, const char *format, int *i);
int			width_parsing(t_printf *p,
		const char *format, int *i, va_list args);
int			precision_parsing(t_printf *p,
		const char *format, int *i, va_list args);
int			length_parsing(t_printf *p, const char *format, int *i);
int			type_parsing(t_printf *p, const char *format, int *i);

int			write_to_console(t_printf *p);

t_fl		get_pieces(long double f_n);
int			get_string(t_fl *f_n, t_printf *p);

int			collecting(t_printf *p, va_list args);
int			decimal_collecting(t_printf *p, va_list args);
int			octadecimal_collecting(t_printf *p, va_list args);
int			unsigned_collecting(t_printf *p, va_list args);
int			hexadecimal_collecting(t_printf *p, va_list args);
int			percent_collecting(t_printf *p);
int			string_collecting(t_printf *p, va_list args);
int			character_collecting(t_printf *p, va_list args);
int			address_collecting(t_printf *p, va_list args);
int			float_collecting(t_printf *p, va_list args);
int			rainbow_collecting(t_printf *p, va_list args);

int			width_calculating(t_printf *p);
int			precision_calculating(t_printf *p);

int			p_atoi(const char *str, int *i);
char		*p_itoa_base(t_printf *p, unsigned long long value, int base);
char		*new_string(const char *source);
int			p_strlen(const char *source);
int			to_lower(t_printf *p);
long long	p_power(int value, int power);
char		*p_strcat(char *destination, const char *source);
void		p_bzero(char *str, int n);

#endif
