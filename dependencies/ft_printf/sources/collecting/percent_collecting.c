/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_collecting.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 14:33:19 by rhulk             #+#    #+#             */
/*   Updated: 2019/08/29 15:38:46 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int		get_percent(t_printf *p)
{
	p->arg.value = new_string("%");
	return (p_strlen(p->arg.value));
}

int				percent_collecting(t_printf *p)
{
	p->arg.length = get_percent(p);
	p->width = width_calculating(p);
	p->precision = 0;
	return (write_to_console(p));
}
