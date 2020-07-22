/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 14:00:59 by rhulk             #+#    #+#             */
/*   Updated: 2019/08/29 14:02:59 by rhulk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			width_parsing(t_printf *p, const char *format, int *i, va_list args)
{
	int		arg;

	if (format[*i] == '*')
	{
		*i += 1;
		arg = va_arg(args, int);
		p->width = (arg > 0) ? arg : -arg;
		if (arg < 0)
			p->flag.minus = true;
	}
	if (format[*i] >= '0' && format[*i] <= '9')
		p->width = p_atoi(format, i);
	return (0);
}
