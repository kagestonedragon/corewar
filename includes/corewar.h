/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <emedea@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 13:50:49 by emedea            #+#    #+#             */
/*   Updated: 2020/07/22 18:23:41 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "types.h"
# include "options.h"

# include <stdlib.h>

typedef struct      s_corewar {
    t_options       options;
}                   t_corewar;

#endif