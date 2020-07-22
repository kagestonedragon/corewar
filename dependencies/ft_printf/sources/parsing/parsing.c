/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 14:03:22 by rhulk             #+#    #+#             */
/*   Updated: 2019/08/29 15:59:33 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static int			deinitialization(t_printf *p)
{
	if (p->sign.value != NULL)
		free(p->sign.value);
	if (p->arg.value != NULL)
		free(p->arg.value);
	free(p);
	return (0);
}

static t_printf		*initialization(int fd)
{
	t_printf		*p;

	p = (t_printf *)malloc(sizeof(t_printf));
	p->fd = fd;
	p->flag.minus = 0;
	p->flag.plus = 0;
	p->flag.space = 0;
	p->flag.zero = 0;
	p->flag.hash = 0;
	p->width = 0;
	p->length = 0;
	p->type = 0;
	p->sign.value = NULL;
	p->arg.value = NULL;
	p->sign.length = 0;
	return (p);
}

int					parsing(int fd, const char *format, int *i, va_list args)
{
	int				length;
	t_printf		*p;

	if (!format[*i + 1])
		return (0);
	p = initialization(fd);
	flag_parsing(p, format, i);
	width_parsing(p, format, i, args);
	precision_parsing(p, format, i, args);
	length_parsing(p, format, i);
	type_parsing(p, format, i);
	length = collecting(p, args);
	deinitialization(p);
	return (length);
}
