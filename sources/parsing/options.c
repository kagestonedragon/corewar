/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <emedea@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 18:12:23 by emedea            #+#    #+#             */
/*   Updated: 2020/07/29 23:54:22 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void         add_champion_raw(t_options **options, const char *filename, const int8_t id)
{
    t_champions_raw	*current;
    t_champions_raw *new;
    
    if (!(new = (t_champions_raw *)ft_memalloc(sizeof(t_champions_raw))))
        terminate(ERROR_MEMORY_ALLOCATE_CODE, ERROR_MEMORY_ALLOCATE, "Error champion raw initialization.");
    new->id = id;
    new->filename = ft_strdup(filename);
    new->next = NULL;
    if ((*options)->champions)
    {
        current = (*options)->champions;
        while (current->next)
        {
            current = current->next;
            if (new->id != O_CHAMPION_ID_DEFAULT && current->id == new->id)
                terminate(ERROR_INPUT_OPTIONS_CODE, ERROR_INPUT_OPTIONS, "Error champions parsing (number duplicate).");
        }
        current->next = new;
    }
    else
        (*options)->champions = new;
    (*options)->champions_amount += 1;
}

static t_bool       parse_champions(t_options **options, int *argc, char ***argv)
{
    int8_t         id;

    if ((*options)->champions_amount > MAX_PLAYERS)
        return (false);
    if (*argc >= 3 && !ft_strcmp(**argv, "-n"))
    {
        if (!is_integer(*(*argv + 1)) || (id = ft_atoi(*(*argv + 1))) < 1 || id > MAX_PLAYERS || !is_cor_file(*(*argv + 2)))
            return (false);
        add_champion_raw(options, *(*argv + 2), id);
        (*argc) -= 3;
        (*argv) += 3;
    }
    else
    {
        add_champion_raw(options, (**argv), O_CHAMPION_ID_DEFAULT);
        (*argc) -= 1;
        (*argv) += 1;
    }

    return (true);
}

static t_bool       parse_dump(t_options **options, int *argc, char ***argv)
{
    t_dump_option   *dump;

    if (!(*options)->dump && is_integer(*(*argv + 1)))
    {
        if (!(dump = (t_dump_option *)ft_memalloc(sizeof(t_dump_option))))
            terminate(ERROR_MEMORY_ALLOCATE_CODE, ERROR_MEMORY_ALLOCATE, "Error dump option initialization.");
        if ((dump->cycle = ft_atoi(*(*argv + 1))) < 0)
            dump->cycle = O_DUMP_CYCLE_DEFAULT;
        dump->mode = O_DUMP_MODE_DEFAULT;
        
        (*options)->dump = dump;
        (*argc) -= 2;
        (*argv) += 2;

        return (true);
    }

    return (false);
}

static t_options    *init_options()
{
    t_options       *options;

    if (!(options = (t_options *)ft_memalloc(sizeof(t_options))))
        terminate(ERROR_MEMORY_ALLOCATE_CODE, ERROR_MEMORY_ALLOCATE, "Error options initialization.");
    options->dump = NULL;
    options->champions = NULL;
    options->champions_amount = 0;

    return (options);
}

t_options           *parse_options(int argc, char **argv)
{
    t_options       *options;

    options = init_options();
    argc--;
    argv++;
    while (argc >= 1)
    {
        if (!ft_strcmp(*argv, "-help"))
            print_help();
        if (argc >= 1 && !ft_strcmp(*argv, "-dump"))
            if (!parse_dump(&options, &argc, &argv))
                terminate(ERROR_INPUT_OPTIONS_CODE, ERROR_INPUT_OPTIONS, "Error dump flag.");
        if (argc >= 1 && (!ft_strcmp(*argv, "-n") || is_cor_file(*argv)))
            if (!parse_champions(&options, &argc, &argv))
                terminate(ERROR_INPUT_OPTIONS_CODE, ERROR_INPUT_OPTIONS, "Error champions parsing.");
    }

    return (options);
}
