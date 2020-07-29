/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <emedea@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 14:00:17 by emedea            #+#    #+#             */
/*   Updated: 2020/07/29 23:57:10 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_corewar    *init_corewar(int argc, char **argv)
{
    t_corewar       *corewar;

    corewar = (t_corewar *)malloc(sizeof(t_corewar));
    corewar->options = parse_options(argc, argv);
    corewar->champions = parse_champions(corewar->options->champions);
    debug_options(corewar);
    
    return (corewar);
}

int                 main(int argc, char **argv)
{
    t_corewar       *corewar;
    
    corewar = init_corewar(argc, argv);
    corewar = NULL;
    
    return (0);
}