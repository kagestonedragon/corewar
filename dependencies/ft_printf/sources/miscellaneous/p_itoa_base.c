/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_itoa_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 14:12:12 by rhulk             #+#    #+#             */
/*   Updated: 2019/08/29 14:52:25 by rhulk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static int	u_size(unsigned long long value, int base)
{
	int		size;

	size = 1;
	while (value /= base)
		size++;
	return (size);
}

char		*p_itoa_base(t_printf *p, unsigned long long value, int base)
{
	int		size;
	char	*result;
	char	*base_tab;

	base_tab = new_string("0123456789ABCDEF");
	size = u_size(value, base);
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (value == 0 && (p->precision > 0 || p->precision == -2))
		result[0] = '0';
	if (value == 0 && (p->type == TYPE_LX ||
				p->type == TYPE_HX) && p->flag.hash)
		p->sign.length = 0;
	result[size] = '\0';
	while (value)
	{
		result[--size] = base_tab[value % base];
		value /= base;
	}
	free(base_tab);
	return (result);
}
