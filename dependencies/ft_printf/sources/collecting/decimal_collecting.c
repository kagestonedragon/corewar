/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_collecting.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 14:24:40 by rhulk             #+#    #+#             */
/*   Updated: 2019/08/29 17:22:06 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static long long		get_sign(t_printf *p, long long value)
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

static int				get_decimal(t_printf *p, va_list args)
{
	p->arg.base = 10;
	if (p->length == LEN_HH)
		p->arg.value = p_itoa_base(p,
				get_sign(p, (char)va_arg(args, void*)), p->arg.base);
	else if (p->length == LEN_H)
		p->arg.value = p_itoa_base(p,
				get_sign(p, (short)va_arg(args, void*)), p->arg.base);
	else if (p->length == LEN_LL)
		p->arg.value = p_itoa_base(p,
				get_sign(p, (long long)va_arg(args, void *)), p->arg.base);
	else if (p->length == LEN_L)
		p->arg.value = p_itoa_base(p,
				get_sign(p, (long)va_arg(args, void*)), p->arg.base);
	else
		p->arg.value = p_itoa_base(p,
				get_sign(p, (int)va_arg(args, void*)), p->arg.base);
	return (p_strlen(p->arg.value));
}

int						decimal_collecting(t_printf *p, va_list args)
{
	p->arg.length = get_decimal(p, args);
	p->width = width_calculating(p);
	p->precision = precision_calculating(p);
	return (write_to_console(p));
}
