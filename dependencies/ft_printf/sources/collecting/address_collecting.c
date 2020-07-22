/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   address_collecting.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 14:20:26 by rhulk             #+#    #+#             */
/*   Updated: 2019/08/29 16:56:53 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static unsigned long long		get_sign(t_printf *p, unsigned long long value)
{
	p->sign.value = new_string("0x");
	p->sign.length = p_strlen(p->sign.value);
	return (value);
}

static int						get_address(t_printf *p, va_list args)
{
	p->arg.base = 16;
	p->arg.value = p_itoa_base(p, get_sign(p,
				(unsigned long long)va_arg(args, void*)), p->arg.base);
	return (p_strlen(p->arg.value));
}

int								address_collecting(t_printf *p, va_list args)
{
	p->arg.length = get_address(p, args);
	to_lower(p);
	p->width = width_calculating(p);
	p->precision = precision_calculating(p);
	return (write_to_console(p));
}
