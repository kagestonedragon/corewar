/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 14:07:20 by rhulk             #+#    #+#             */
/*   Updated: 2019/08/29 14:51:35 by rhulk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

char		*new_string(const char *source)
{
	char	*result;
	int		size;

	size = p_strlen(source);
	result = (char *)malloc(sizeof(char) * (size + 1));
	result[size] = '\0';
	while (size--)
		result[size] = source[size];
	return (result);
}
