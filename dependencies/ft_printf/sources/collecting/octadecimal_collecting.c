/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octadecimal_collecting.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 14:31:08 by rhulk             #+#    #+#             */
/*   Updated: 2019/08/29 17:23:35 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static unsigned long long		get_sign(t_printf *p, unsigned long long value)
{
	if (p->flag.hash)
	{
		p->sign.value = new_string("0");
		p->sign.length = p_strlen(p->sign.value);
	}
	return (value);
}

static int						get_decimal(t_printf *p, va_list args)
{
	p->arg.base = 8;
	if (p->length == LEN_HH)
		p->arg.value = p_itoa_base(p,
				get_sign(p, (unsigned char)va_arg(args, void*)), p->arg.base);
	else if (p->length == LEN_H)
		p->arg.value = p_itoa_base(p,
				get_sign(p, (unsigned short)va_arg(args, void*)), p->arg.base);
	else if (p->length == LEN_LL || p->length == LEN_Z)
		p->arg.value = p_itoa_base(p,
				get_sign(p, (unsigned long long)va_arg(args, void *)),
				p->arg.base);
	else if (p->length == LEN_L)
		p->arg.value = p_itoa_base(p,
				get_sign(p, (unsigned long)va_arg(args, void*)), p->arg.base);
	else
		p->arg.value = p_itoa_base(p,
				get_sign(p, (unsigned int)va_arg(args, void*)), p->arg.base);
	return (p_strlen(p->arg.value));
}

int								octadecimal_collecting(t_printf *p,
		va_list args)
{
	p->arg.length = get_decimal(p, args);
	p->arg.length = (p->arg.value[0] == '0' &&
			p->arg.length == 1 && p->flag.hash) ? 0 : p->arg.length;
	p->width = width_calculating(p);
	p->precision = precision_calculating(p);
	return (write_to_console(p));
}
