/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <emedea@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 18:12:23 by emedea            #+#    #+#             */
/*   Updated: 2020/07/22 18:19:36 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/corewar.h"

static t_options    init_options()
{
    t_options       options;

    options.number = O_NUMBER_DEFAULT;
    options.log = O_LOG_DEFAULT;

    return (options);
}

void                parse_options(int argc, char **argv)
{
    t_options       options;

    options = init_options();
}



