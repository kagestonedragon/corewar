/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_collecting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 14:34:17 by rhulk             #+#    #+#             */
/*   Updated: 2019/08/29 17:02:04 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int		get_string_s(t_printf *p, va_list args)
{
	char		*temporary;
	int			length;

	temporary = (char *)va_arg(args, void*);
	if (!temporary)
		p->arg.value = new_string("(null)");
	else
		p->arg.value = new_string(temporary);
	length = p_strlen(p->arg.value);
	if (length > p->precision && (p->precision >= 0))
		return (p->precision);
	if (p->precision == -1)
		return (0);
	return (length);
}

int				string_collecting(t_printf *p, va_list args)
{
	p->arg.length = get_string_s(p, args);
	p->precision = 0;
	p->width = width_calculating(p);
	return (write_to_console(p));
}
