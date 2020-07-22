/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_strcat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 14:17:15 by rhulk             #+#    #+#             */
/*   Updated: 2019/08/29 14:17:30 by rhulk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*p_strcat(char *destination, const char *source)
{
	char	*begin;

	begin = destination;
	while (*destination)
		destination++;
	while (*source)
	{
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';
	return (begin);
}
