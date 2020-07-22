/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <emedea@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 13:47:12 by emedea            #+#    #+#             */
/*   Updated: 2020/07/22 20:12:16 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIONS_H
# define OPTIONS_H

# define O_NUMBER_DEFAULT   0
# define O_LOG_DEFAULT      0

# include "types.h"

typedef struct              s_options {
    t_bool                  number;
    t_bool                  log;
}                           t_options;

t_options                   parse_options(int argc, char **argv);\

#endif