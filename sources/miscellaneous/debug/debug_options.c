/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <emedea@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 19:17:35 by emedea            #+#    #+#             */
/*   Updated: 2020/07/26 19:29:25 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void            debug_options(t_corewar *corewar)
{
    debug_dump(corewar->options->dump);
    debug_champions_raw(corewar->options->champions);
}

static void     debug_dump(t_dump_option *dump)
{
    printf("Dump option\n");
    printf("Dump cycles: %du\n", dump->cycle);
    printf("Dump mode: %d\n\n", dump->mode);
}

static void     debug_champions(t_champions_raw *champions, const int champions_amount)
{
    printf("Champion option\n");
    printf("Champions amount: %d\n", champions_amount);

    while (champions)
    {
        if (champions->id == O_CHAMPION_ID_DEFAULT)
            printf("Champion id: unknown\n");
        else
            printf("Champion id: %d\n", champions->id);
        print("Champion filename: %s\n", champions->filename);
        champions = champions->next;
    }
}