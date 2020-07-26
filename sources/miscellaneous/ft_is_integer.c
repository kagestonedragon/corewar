/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <emedea@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 12:57:22 by emedea            #+#    #+#             */
/*   Updated: 2020/07/26 12:59:58 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

t_bool      ft_is_integer(const char *str)
{
    int     i;

    i = -1;
    while (str[++i])
    {
        if (!(str[i] >= 48 && str[i] <= 57))
            return (false);
    }

    return (true);
}