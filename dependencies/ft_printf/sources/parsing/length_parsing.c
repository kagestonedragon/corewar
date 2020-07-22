/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 13:52:36 by rhulk             #+#    #+#             */
/*   Updated: 2019/08/29 17:20:45 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		length_parsing(t_printf *p, const char *format, int *i)
{
	if (format[*i] == LEN_H && format[*i + 1] == LEN_H)
		p->length = LEN_HH;
	else if (format[*i] == LEN_L && format[*i + 1] == LEN_L)
		p->length = LEN_LL;
	else if (format[*i] == LEN_L)
		p->length = LEN_L;
	else if (format[*i] == LEN_H)
		p->length = LEN_H;
	else if (format[*i] == LEN_HL)
		p->length = LEN_HL;
	else if (format[*i] == LEN_Z)
		p->length = LEN_Z;
	if (p->length > 150)
		*i += 2;
	else if (p->length != 0)
		*i += 1;
	return (0);
}
