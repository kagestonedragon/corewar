/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulk <rhulk@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 13:50:49 by emedea            #+#    #+#             */
/*   Updated: 2020/07/26 14:38:53 by rhulk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# define COR_FILE_EXTENSION ".cor"
# define MAX_PLAYERS        4

# include "../dependencies/libft/includes/libft.h"
# include "types.h"
# include "options.h"
# include <stdio.h> // отключить потом
# include <unistd.h>
# include <fcntl.h>

# include <stdlib.h>

typedef struct          s_players {
    int8_t              id;
    char                *name;
    char                *comment;
    int32_t             code_size;
    uint8_t             *code;
    int                 last_live;
    int                 current_lives_num;
    int                 previous_lives_num;
    struct s_players    *next;
}                       t_players;

typedef struct          s_corewar {
    t_options           options;
}                       t_corewar;

// misc
t_bool                  ft_is_cor_file(const char *filename);

//options
t_options                   parse_options(int argc, char **argv);
t_bool                      parse_dump(t_options *options, int *argc, char ***argv);
t_bool                      parse_number(t_players *players, int *argc, char ***argv);

#endif