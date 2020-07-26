/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <emedea@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 12:52:35 by emedea            #+#    #+#             */
/*   Updated: 2020/07/26 20:08:05 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_bool      parse_champions(t_players **players, int *argc, char ***argv)
{
    int8_t  id;

    id = 0;
    if (*argc >= 3 && !ft_strcmp(**argv, "-n"))
    {
        if (!is_integer(*(*argv + 1))
            || (id = ft_atoi(*(*argv + 1))) < 1
            || id > MAX_PLAYERS
            || !is_cor_file(*(*argv + 2))
            //|| find_player()
            )
            return (false);
        add_player(players, parse_champion(*(*argv + 2), id), id); //
    }

    return (true); // убрать
}