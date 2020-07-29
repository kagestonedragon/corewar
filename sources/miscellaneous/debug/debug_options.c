/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <emedea@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 19:17:35 by emedea            #+#    #+#             */
/*   Updated: 2020/07/29 20:58:28 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void     debug_dump(t_dump_option *dump)
{
    if (dump != NULL)
    {
        printf("Dump option\n");
        printf("Dump cycles: %d\n", dump->cycle);
        printf("Dump mode: %d\n\n", dump->mode);
    }
}

static void     debug_champions_raw(t_champions_raw *champions, int champions_amount)
{
    if (champions != NULL)
    {
        printf("Champion option\n");
        printf("Champions amount: %d\n", champions_amount);

        while (champions)
        {
            if (champions->id == O_CHAMPION_ID_DEFAULT)
                printf("Champion id: unknown\n");
            else
                printf("Champion id: %d\n", champions->id);
            printf("Champion filename: %s\n", champions->filename);
            champions = champions->next;
        }
    }
}

void            debug_options(t_corewar *corewar)
{
    debug_dump(corewar->options->dump);
    debug_champions_raw(corewar->options->champions, corewar->options->champions_amount);
}