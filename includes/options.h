/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <emedea@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 13:47:12 by emedea            #+#    #+#             */
/*   Updated: 2020/07/26 14:04:29 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIONS_H
# define OPTIONS_H

# define O_NUMBER_DEFAULT       0
# define O_LOG_DEFAULT          0
# define O_DUMP_DEFAULT         0
# define O_DUMP_CYCLE_DEFAULT   -1
# define O_DUMP_MODE_DEFAULT    32

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