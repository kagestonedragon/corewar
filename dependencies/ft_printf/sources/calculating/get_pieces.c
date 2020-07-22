/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pieces.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 13:39:04 by rhulk             #+#    #+#             */
/*   Updated: 2019/08/29 15:16:15 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

t_fl			get_pieces(long double f_n)
{
	t_fl_parts	fl;
	t_fl		n;
	int			i;

	fl.f = f_n;
	n.exponent = fl.bytes.exponent - 16383;
	i = ((64 - n.exponent - 1) * (-1)) - 1;
	n.integer_part = 0;
	n.fractional_part = 0;
	while (++i <= n.exponent)
	{
		if ((fl.bytes.mantissa & 1) && (i >= 0))
			n.integer_part += p_power(2, i);
		else if ((fl.bytes.mantissa & 1) && (i < 0))
			n.fractional_part += (1.0 / p_power(2, -i));
		fl.bytes.mantissa >>= 1;
	}
	return (n);
}

void			round_fractional_part(t_fl *f_n, char *in, int precision)
{
	int			i;

	if (precision == 0 && in[0] > '4' && f_n->integer_part > 0)
		f_n->integer_part++;
	else if (precision == 0 && in[0] > '4' && f_n->integer_part < 0)
		f_n->integer_part--;
	i = precision + 1;
	while (i--)
	{
		if (in[i] > '4')
			in[i - 1]++;
		if (in[i - 1] == ':')
		{
			in[i - 1] = '0';
			in[i] = '0';
			in[i - 2]++;
		}
		else
		{
			in[precision] = '\0';
			break ;
		}
	}
}

static char		*get_string_fp(t_fl *f_n, t_printf *pf)
{
	char		*result;
	int			temporary;
	int			i;

	result = (char *)malloc(sizeof(char) * 16);
	p_bzero(result, 16);
	result[0] = '0';
	i = 0;
	while (i < 15)
	{
		f_n->fractional_part *= 10;
		temporary = (int)f_n->fractional_part;
		f_n->fractional_part -= temporary;
		result[i++] = temporary + '0';
	}
	round_fractional_part(f_n, result, pf->precision);
	return (result);
}

int				get_string(t_fl *f_n, t_printf *p)
{
	char		*integer_part;
	char		*fractional_part;

	fractional_part = get_string_fp(f_n, p);
	integer_part = p_itoa_base(p, f_n->integer_part, 10);
	p->arg.value = (char *)malloc(sizeof(char) *
			(p_strlen(integer_part) + p_strlen(fractional_part) + 2));
	p->arg.value[0] = '\0';
	p_strcat(p->arg.value, integer_part);
	if (p->flag.hash || p->precision > 0)
		p_strcat(p->arg.value, ".");
	if (p->precision > 0)
		p_strcat(p->arg.value, fractional_part);
	free(integer_part);
	free(fractional_part);
	return (p_strlen(p->arg.value));
}
