/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <emedea@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 17:17:19 by emedea            #+#    #+#             */
/*   Updated: 2020/07/26 17:27:49 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void    terminate(const int error_code, const char *error, const char *explanation)
{
    printf("%s", error);
    if (explanation != NULL)
        printf(" %s", explanation);
    printf("\n");
    printf("./corewar -help for usage help\n");

    exit(error_code);
}