/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collecting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 14:23:12 by rhulk             #+#    #+#             */
/*   Updated: 2019/08/29 17:24:33 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		collecting(t_printf *p, va_list args)
{
	if (p->type == TYPE_PT)
		return (percent_collecting(p));
	else if (p->type == TYPE_D || p->type == TYPE_I)
		return (decimal_collecting(p, args));
	else if (p->type == TYPE_U)
		return (unsigned_collecting(p, args));
	else if (p->type == TYPE_LX || p->type == TYPE_HX)
		return (hexadecimal_collecting(p, args));
	else if (p->type == TYPE_LF || p->type == TYPE_HF)
		return (float_collecting(p, args));
	else if (p->type == TYPE_O)
		return (octadecimal_collecting(p, args));
	else if (p->type == TYPE_S)
		return (string_collecting(p, args));
	else if (p->type == TYPE_C)
		return (character_collecting(p, args));
	else if (p->type == TYPE_P)
		return (address_collecting(p, args));
	else if (p->type == TYPE_R)
		return (rainbow_collecting(p, args));
	return (0);
}
