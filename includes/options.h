/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulk <rhulk@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 13:47:12 by emedea            #+#    #+#             */
/*   Updated: 2020/07/26 14:47:40 by rhulk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIONS_H
# define OPTIONS_H

# define O_NUMBER_DEFAULT       0
# define O_LOG_DEFAULT          0
# define O_DUMP_DEFAULT         0
# define O_DUMP_CYCLE_DEFAULT   -1
# define O_DUMP_MODE_DEFAULT    32

# define MEM_SIZE               (4 * 1024)

# define CHAMP_NAME_LENGTH		128
# define COMMENT_LENGTH			2048
# define COREWAR_EXEC_MAGIC		0xea83f3
# define CHAMP_CODE_MAX_SIZE    (MEM_SIZE / 6)

# include "types.h"
# include <stdint.h>

typedef struct              s_options {
    t_bool                  number;
    t_bool                  log;
    t_bool                  dump;
    int                     dump_cycle;
    uint8_t                 dump_mode;
}                           t_options;

#endif