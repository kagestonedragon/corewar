/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 15:48:19 by emedea            #+#    #+#             */
/*   Updated: 2019/08/29 17:00:15 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int					ft_dprintf(int fd, const char *format, ...)
{
	va_list			args;
	int				length;
	int				i;

	if (fd == -1)
		return (0);
	i = -1;
	length = 0;
	va_start(args, format);
	while (format[++i])
	{
		if (format[i] == '%')
			length += parsing(fd, format, &i, args) - 1;
		else
			write(fd, &format[i], 1);
		length++;
	}
	va_end(args);
	return (length);
}
