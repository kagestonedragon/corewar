/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <emedea@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 18:12:23 by emedea            #+#    #+#             */
/*   Updated: 2020/07/26 13:49:51 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <stdio.h>

static t_options    init_options()
{
    t_options       options;

    options.number = O_NUMBER_DEFAULT;
    options.log = O_LOG_DEFAULT;
    options.dump = O_DUMP_DEFAULT;
    options.dump_cycle = O_DUMP_DEFAULT;
    options.dump_mode = O_DUMP_DEFAULT;

    return (options);
}

t_options           parse_options(int argc, char **argv)
{
    t_options       options;
    t_players       *players;

    options = init_options();
    argc--;
    argv++;
    players = NULL;
    while (argc >= 1)
    {
        if (!ft_strcmp(*argv, "-dump") && !parse_dump(&options, &argc, &argv))
            printf("Parse error"); // заменить на функцию подсказки
        else if ((!ft_strcmp(*argv, "-n") || ft_is_cor_file(*argv)) && !parse_number(&options, &argc, &argv))
            printf("Parse error"); // заменить на функцию подсказки

    }

    return (options);
}



