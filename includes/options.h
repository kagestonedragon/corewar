/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <emedea@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 13:47:12 by emedea            #+#    #+#             */
/*   Updated: 2020/07/29 22:04:53 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIONS_H
# define OPTIONS_H

# define O_CHAMPION_ID_DEFAULT      -1
# define O_DUMP_CYCLE_DEFAULT       -1
# define O_DUMP_MODE_DEFAULT        32

# include "types.h"
# include <stdint.h>

typedef struct                      s_champions_raw{
    int8_t                          id;
    char                            *filename;
    struct s_champions_raw          *next;
}                                   t_champions_raw;

typedef struct                      s_dump_option{
    int                             cycle;
    uint8_t                         mode;
}                                   t_dump_option;

typedef struct                      s_options{
    t_dump_option                   *dump;
    t_champions_raw                 *champions;
    uint8_t                         champions_amount;
}                                   t_options;

#endif