/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 14:43:54 by rhulk             #+#    #+#             */
/*   Updated: 2019/08/29 16:55:25 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int					ft_printf(const char *format, ...)
{
	va_list			args;
	int				length;
	int				i;

	i = -1;
	length = 0;
	va_start(args, format);
	while (format[++i])
	{
		if (format[i] == '%')
			length += parsing(1, format, &i, args) - 1;
		else
			write(1, &format[i], 1);
		length++;
	}
	va_end(args);
	return (length);
}
