/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 13:48:39 by rhulk             #+#    #+#             */
/*   Updated: 2019/08/29 13:50:22 by rhulk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		is_flag(t_printf *p, char character)
{
	if (character == FLAG_M)
		return (p->flag.minus = true);
	else if (character == FLAG_P)
		return (p->flag.plus = true);
	else if (character == FLAG_S)
		return (p->flag.space = true);
	else if (character == FLAG_Z)
		return (p->flag.zero = true);
	else if (character == FLAG_H)
		return (p->flag.hash = true);
	return (0);
}

int				flag_parsing(t_printf *p, const char *format, int *i)
{
	*i += 1;
	while (is_flag(p, format[*i]))
		*i += 1;
	return (0);
}
