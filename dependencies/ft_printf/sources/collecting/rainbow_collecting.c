/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rainbow_collecting.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 16:56:03 by emedea            #+#    #+#             */
/*   Updated: 2019/08/29 17:29:55 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int				rainbow_collecting(t_printf *p, va_list args)
{
	char		*temporary;

	if (p->fd == 1)
	{
		temporary = (char *)va_arg(args, void*);
		if (!temporary)
			return (0);
		else
			write(2, temporary, p_strlen(temporary));
	}
	return (0);
}
