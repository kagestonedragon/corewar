/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_cor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <emedea@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 13:23:22 by emedea            #+#    #+#             */
/*   Updated: 2020/07/26 13:31:05 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_bool      ft_is_cor_file(const char *filename)
{
    if (filename && ft_strlen(filename) > ft_strlen(COR_FILE_EXTENSION))
        return (!ft_strcmp((ft_strchr(filename, '\0') - ft_strlen(COR_FILE_EXTENSION)), COR_FILE_EXTENSION));
    else 
        return (false);
}