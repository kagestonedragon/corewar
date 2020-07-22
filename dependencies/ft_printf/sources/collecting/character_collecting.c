/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_collecting.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 14:22:01 by rhulk             #+#    #+#             */
/*   Updated: 2019/08/29 15:17:51 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

static int		get_character(t_printf *p, va_list args)
{
	char		temporary;

	temporary = (char)va_arg(args, int);
	p->arg.value = (char *)malloc(sizeof(char) * 2);
	p->arg.value[0] = temporary;
	p->arg.value[1] = '\0';
	p->arg.length = 1;
	return (0);
}

int				character_collecting(t_printf *p, va_list args)
{
	get_character(p, args);
	p->width = width_calculating(p);
	p->precision = 0;
	return (write_to_console(p));
}
