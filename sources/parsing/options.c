/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <emedea@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 18:12:23 by emedea            #+#    #+#             */
/*   Updated: 2020/07/23 22:09:29 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_options    init_options()
{
    t_options       options;

    options.number = O_NUMBER_DEFAULT;
    options.log = O_LOG_DEFAULT;

    return (options);
}

t_options           parse_options(int argc, char **argv)
{
    t_options       options;

    options = init_options();

    while (argv++)
    {

    }

    return (options);
}



