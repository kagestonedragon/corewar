/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <emedea@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 12:52:35 by emedea            #+#    #+#             */
/*   Updated: 2020/07/26 14:05:49 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_bool      parse_dump(t_options *options, int *argc, char ***argv)
{
    if (!options->dump_mode && ft_is_integer(*(*argv + 1)))
    {
        options->dump = true;
        options->dump_cycle = ft_atoi(*(*argv + 1));
        if (options->dump_cycle < 0)
            options->dump_cycle = O_DUMP_CYCLE_DEFAULT;
        options->dump_mode = O_DUMP_MODE_DEFAULT;
        (*argc) -= 2;
        (*argv) += 2;

        return (true);
    }

    return (false);
}

t_bool      parse_number(t_players *players, int *argc, char ***argv)
{
    int8_t  id;

    id = 0;
    if (*argc >= 3 && !ft_strcmp(**argv, "-n"))
    {
        if (!ft_is_integer(*(*argv + 1))
            || (id = ft_atoi(*(*argv + 1))) < 1
            || id > MAX_PLAYERS
            || !ft_is_cor_file(*(*argv + 2))
            || find_player())
            return (false);
        add_player(); //
    }

    return (true); // убрать
}