/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <emedea@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 13:51:50 by emedea            #+#    #+#             */
/*   Updated: 2020/07/26 14:00:01 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_players    *init_player(int id)
{
    t_players       *player;

    if (!(player = (t_players *)ft_memalloc(sizeof(t_players))))
        printf("Ошибочка во время инита игрока");
    player->id = id;
    player->name = NULL;
    player->comment = NULL;
    player->code_size = 0;
    player->code = NULL;
    player->current_lives_num = 0;
    player->previous_lives_num = 0;
    player->next = NULL;

    return (player);
}

t_players           *parse_champion(const char *filename, int id)
{
    t_players       *player;
    int             fd;

    player = init_player(id);
    
    return (player);
}