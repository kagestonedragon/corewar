/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_collecting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 14:27:22 by rhulk             #+#    #+#             */
/*   Updated: 2019/08/29 15:44:23 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static long double		get_sign(t_printf *p, long double value)
{
	if (value < 0)
		p->sign.value = new_string("-");
	else if (p->flag.plus)
		p->sign.value = new_string("+");
	else if (p->flag.space)
		p->sign.value = new_string(" ");
	if (p->sign.value != NULL)
		p->sign.length = p_strlen(p->sign.value);
	return ((value > 0) ? value : -value);
}

static int				get_float(t_printf *p, va_list args)
{
	t_fl				f_n;
	long double			t;

	if (p->length == LEN_HL)
		t = va_arg(args, long double);
	else
		t = (long double)va_arg(args, double);
	f_n = get_pieces(get_sign(p, t));
	return (get_string(&f_n, p));
}

int						float_collecting(t_printf *p, va_list args)
{
	if (p->precision == -2 || p->precision == -1)
		p->precision = 6;
	p->arg.length = get_float(p, args);
	p->width = width_calculating(p);
	p->precision = 0;
	return (write_to_console(p));
}
