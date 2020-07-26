/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_champions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <emedea@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 16:52:38 by emedea            #+#    #+#             */
/*   Updated: 2020/07/26 17:00:29 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void        debug_champions(t_corewar *corewar)
{
    while (corewar->players)
    {
        printf("%d player\n", corewar->players->id);
        printf("Name - %s\n", corewar->players->name);
        printf("Commentary - %s\n", corewar->players->comment);
        printf("Code_size - %d\n", corewar->players->code_size);
        printf("Code - %d\n", corewar->players->code);

        corewar->players = corewar->players->next;
    }
}