/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_binary.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <emedea@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 18:03:57 by emedea            #+#    #+#             */
/*   Updated: 2020/07/26 18:12:09 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/**
 * Function for reading small areas (4 bytes) of champion file such as Magic Header, NULL area
 * 
 */
int32_t             read_champion_bytecode(int fd)
{
    size_t          size;
    uint8_t         buffer[4];

    size = read(fd, &buffer, 4);
    if (size == -1)
        terminate(ERROR_READ_FILE_CODE, ERROR_READ_FILE, "Champion file bytecode reading failed.");
    if (size < 4)
        terminate(ERROR_READ_FILE_CODE, ERROR_READ_FILE, "Champion file is invalid.");
    return (bytecode_to_int32(buffer, 4));
}

/**
 * Function for reading champion name and champion commentary
 */
char                *read_champion_info(int fd, size_t len)
{
	ssize_t         size;
	char            *buffer;

	if (!(buffer = ft_strnew(len)))
		terminate(ERROR_MEMORY_ALLOCATE_CODE, ERROR_MEMORY_ALLOCATE, "Champion name initialization failed.");
	size = read(fd, buffer, len);
	if (size == -1)
		terminate(ERROR_READ_FILE_CODE, ERROR_READ_FILE, "Champion name reading failed.");
	if (size < (ssize_t)len)
		terminate(ERROR_READ_FILE_CODE, ERROR_READ_FILE, "Champion file is invalid.");
	return (buffer);
}

/**
 * Function for reading champion code
 */
uint8_t             *read_champion_code(int fd, size_t len)
{
	ssize_t	        size;
	uint8_t         *buffer;
	uint8_t         byte;

	if (!(buffer = malloc(len)))
		terminate(ERROR_MEMORY_ALLOCATE_CODE, ERROR_MEMORY_ALLOCATE, "Champion code initialization failed.");
	size = read(fd, buffer, len);
	if (size == -1)
		terminate(ERROR_READ_FILE_CODE, ERROR_READ_FILE, "Champion code reading failed.");
	if (size < (ssize_t)len || read(fd, &byte, 1) != 0)
		terminate(ERROR_READ_FILE_CODE, ERROR_READ_FILE, "Champion file is invalid.");
	return (buffer);
}
