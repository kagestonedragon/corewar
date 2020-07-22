/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculating.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 13:44:20 by rhulk             #+#    #+#             */
/*   Updated: 2019/08/29 15:51:58 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	flags_correcting(t_printf *p)
{
	if (p->flag.minus && p->flag.zero)
		p->flag.zero = false;
	return (0);
}

int			width_calculating(t_printf *p)
{
	p->width -= p->sign.length;
	if (p->precision > p->arg.length)
		p->width -= p->precision;
	else
		p->width -= p->arg.length;
	return ((p->width > 0) ? p->width : 0);
}

int			precision_calculating(t_printf *p)
{
	p->precision -= p->arg.length;
	p->precision -= (p->type == TYPE_O && p->flag.hash) ? p->sign.length : 0;
	return ((p->precision > 0) ? p->precision : 0);
}

int			write_to_console(t_printf *p)
{
	int	size;

	flags_correcting(p);
	size = p->width + p->precision + p->arg.length + p->sign.length;
	if (!p->flag.minus && !p->flag.zero)
		while (p->width--)
			write(p->fd, " ", 1);
	if (p->sign.length != 0)
		write(p->fd, p->sign.value, p->sign.length);
	if (!p->flag.minus && p->flag.zero)
		while (p->width--)
			write(p->fd, (p->precision > 0 ? " " : "0"), 1);
	while (p->precision--)
		write(p->fd, "0", 1);
	write(p->fd, p->arg.value, p->arg.length);
	if (p->flag.minus && !p->flag.zero)
		while (p->width--)
			write(p->fd, " ", 1);
	return (size);
}
